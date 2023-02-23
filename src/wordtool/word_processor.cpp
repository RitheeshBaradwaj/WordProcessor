#include "wordtool/word_processor.h"

namespace wordtool {

WordProcessor::WordProcessor() : worker_thread_(&WordProcessor::WorkerThread, this) {
}

WordProcessor::~WordProcessor() {
    // Notify the worker thread that we're done adding words
    word_list_.SetEndEncountered(true);

    // Wait for the worker thread to finish
    if (worker_thread_.joinable()) {
        worker_thread_.join();
    }
}

void WordProcessor::WorkerThread() {
    while (true) {
        // Wait for a new word to be inserted or for the end of input to be encountered
        Word word = word_queue_.WaitAndPop();
        if (word.GetData() == "end") {
            word_list_.SetEndEncountered(true);
            break;
        }

        // Insert the word into the word list
        word_list_.InsertWord(word);
    }
}

void WordProcessor::ReadInputWords() {
    std::string line;
    bool end_encountered = false;
    while (!end_encountered) {
        if (!std::getline(std::cin, line)) {
            return;
        }

        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());  // Remove carriage return character
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());  // Remove newline character

        if (line == "end") {
            end_encountered = true;
        }

        // Insert the new word into the safe queue
        word_queue_.Push(Word(line));
    }
}

void WordProcessor::LookupWords() {
    std::string input_word;

    while (!word_list_.IsEndEncountered()) {
        std::cerr << "LookupWords() should be used after input words are processed. Waiting for 100ms...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::printf("\nEnter a word for lookup (enter 'Ctrl+D' to stop): ");

    while (std::getline(std::cin, input_word)) {
        input_word.erase(std::remove(input_word.begin(), input_word.end(), '\r'),
                         input_word.end());  // Remove carriage return character
        input_word.erase(std::remove(input_word.begin(), input_word.end(), '\n'),
                         input_word.end());  // Remove newline character

        Word word(input_word);
        auto word_ptr = word_list_.SearchWord(word);

        if (word_ptr != nullptr) {
            std::printf("SUCCESS: '%s' was present %d times in the word list\n", word_ptr->GetData().c_str(),
                        word_ptr->GetCount());
        } else {
            std::printf("'%s' was NOT found in the initial word list\n", word.GetData().c_str());
        }

        std::printf("\nEnter a word for lookup (enter 'Ctrl+D' to stop): ");
    }
    std::printf("\nExiting WordProcessor Application...\n");
}

void WordProcessor::PrintWordList() {
    while (!word_list_.IsEndEncountered()) {
        std::cerr << "PrintWordList() should be used after input words are processed. Waiting for 100ms...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    auto words = word_list_.SortAndGetWordList();

    std::cout << "\nTotal Words Found: " << words.size() << "\n\nWord List:\n";

    for (const auto& word : words) {
        std::printf("%s: %d\n", word.GetData().c_str(), word.GetCount());
    }
}

}  // namespace wordtool
