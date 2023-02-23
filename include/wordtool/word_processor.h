//==============================================================================

/// @file word_processor.h
/// @brief Definition of the WordProcessor class.
//==============================================================================

#ifndef WORDTOOL_WORD_PROCESSOR_H
#define WORDTOOL_WORD_PROCESSOR_H

#include <iostream>
#include <string>
#include <thread>

#include "wordtool/safe_queue.h"
#include "wordtool/word.h"
#include "wordtool/word_list.h"

namespace wordtool {

/// @brief The WordProcessor class provides methods to read input words from STDIN
/// and to search for a word in the list of words entered initially.
class WordProcessor {
   public:
    /// @brief Construct a new Word Processor object
    WordProcessor();

    /// @brief Destroy the Word Processor object
    ~WordProcessor();

    /// @brief Lookup a word in the word list and print the number of times it was encountered.
    void LookupWords();

    /// @brief Read input words from STDIN and add them to the word list.
    void ReadInputWords();

    /// @brief Print the word list to the console.
    void PrintWordList();

   private:
    /// @brief The worker thread function that continuously pops words from the word queue and inserts them into the
    /// word list
    void WorkerThread();

    std::thread worker_thread_;   ///< The worker thread that adds words to the word list.
    WordList word_list_;          ///< The word list.
    Word word_;                   ///< The current word being processed.
    SafeQueue<Word> word_queue_;  ///< The queue of words read from STDIN.
};

}  // namespace wordtool

#endif  // WORDTOOL_WORD_PROCESSOR_H
