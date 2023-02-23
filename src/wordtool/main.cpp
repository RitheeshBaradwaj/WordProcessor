#include "wordtool/word_processor.h"

int main() {
    std::cout << "\n====================START====================\n\n";

    try {
        wordtool::WordProcessor word_processor;

        std::cout << "Enter words to add to the word list (type 'end' to stop):\n";
        word_processor.ReadInputWords();

        std::cout << "\nWords in the list:\n";
        word_processor.PrintWordList();

        std::cout << "\nLookup words in the list:\n";
        word_processor.LookupWords();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\n=====================END=====================\n\n";
    return 0;
}
