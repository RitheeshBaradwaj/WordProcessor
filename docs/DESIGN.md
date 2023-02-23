# WordProcessor Application Design

The Word Processor application is designed to read a list of ASCII words from standard input, remove duplicates, sort them alphabetically, and
print them with the number of times each word was encountered. It also allows the user to search for a specific word in the list.

## WordProcessor Workflow

Below is the sequence of WordProcessor Application,

![WordProcessor-Workflow](http://www.plantuml.com/plantuml/png/fPD1Zzem48Nl_XLMJd3e_W0ErLOghP1MXHPMlLJgccHsDoBOmJCkxR_lonWBikcjI4WXR-RDDy_cdiL5ISVE65TBYBPwP8gLTMmJ7epf8RTrspiljjhkFgw-gDZwiN9qhLV1zVrO-HvYiucX9kQGZS_JYWF5tMiar-G2UJFMFTFNH8bKvTDqm4FBabkx2V7wSQTII6BCi9HzzrunyRqyseKTOSxcvgpQMI1LcX6ybTDA1ZNGKC6deTcryi4tc_LcDl_XgpD-jlx5FYDFwkX8895WzsJTBzTs-uwGdptfHgPWd0UARt1U-Jx9WCF0C2ynfDuE4z430HHGB2mfKcFtV_8vMNpARl06j5QmTTfmTtTNQGsc5EXDubV57SmvT-SHpZUsXpf0Cx8lgEX7Qya5i9AYvxAYBduWEFN8Y2vnbRHqk6XlXzwLPxfaEYmc0Q1FBCrYmIHFXdnZp3_tWOBehuaffxf8o9oAJxzR5fxcUODGxit2RacMlbdwEgGSwqnYehaQiOIUnuUqYG0ktVcg5C_FT9saRqEIqZ7B9wTqhhv0wyZvsFyXX4Fgtzm09XVHX2jLmct-yn8ey5PjXrcADrTzYfwd_up4gGFkz7YMwq-tfvBZlzq4mytu7uSQkIQhRk19TKsCr_UOaOxTNm00)

## Class Overview

The Word Processor application is composed of the following classes:

### Word

The `Word` class is a wrapper to std::string and represents a word given by user.
It stores the word data and the count of how many times the word was encountered.

### WordList

The `WordList` class represents the set of all words entered by user.
It stores a set of unique words, and provides methods for performaing basic operations
like inserting words, getting a sorted list of words, searching for a word, and checking
if the "end" keyword has been encountered.

### SafeQueue

1. A `SafeQueue` is a thread-safe data structure used to store and access data from multiple threads.
In the WordProcessor application, a SafeQueue is used to store the words entered by the user.
This ensures that multiple threads can access and modify the queue without causing data races or deadlocks.

2. The SafeQueue is implemented using a std::queue and a std::mutex. The push() and pop() operations are wrapped
in a std::lock_guard, which automatically locks and unlocks the mutex when entering and leaving the scope of the function.

3. In addition to the std::queue and std::mutex, a std::condition_variable is used to allow threads to wait until data
is available in the queue. The wait() operation on the condition variable releases the lock on the mutex and waits for a
notification from another thread. When data is pushed into the queue, a notify_one() operation is called on the condition
variable, waking up one of the waiting threads.

### WordProcessor

The `WordProcessor` class is the main class of the WordProcessor application. It encapsulates the core functionality of the application,
including reading input words, processing and printing word list, and performing word lookups.

## WordProcessor Implementation Overview

In the WordProcessor class, an IO bound task is implemented using a thread-safe queue.
The ReadInputWords() method is responsible for reading input words from the user and adding
them to the word list. Since reading input from the user is an IO-bound task, it can block
the main thread and affect the responsiveness of the application.

To avoid blocking the main thread, a separate thread is created to handle the IO-bound task of
reading input from the user. The input is read line-by-line and added to a thread-safe queue
using the Push() method. The main thread then waits on the thread-safe queue using the WaitAndPop()
method, which blocks worker thread until an item is available in the queue.

Once an item is available in the queue, it is popped and added to the word list using the InsertWord()
method of the WordList class. This method is thread-safe and ensures that words are inserted in a synchronized manner.
The IO-bound task is thus decoupled from the main thread and can run concurrently, improving the responsiveness of the application.

Overall, the use of a thread-safe queue enables the implementation of an IO-bound task in a thread-safe and non-blocking manner.

**NOTE:** Insert each individual word can also be performed using Future::then() or separate thread which is
not in the scope of this application now.
