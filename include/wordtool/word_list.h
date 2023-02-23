//==============================================================================

/// @file word_list.h
/// @brief Definition of the WordList class.
//==============================================================================

#ifndef WORDTOOL_WORD_LIST_H
#define WORDTOOL_WORD_LIST_H

#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <set>
#include <typeinfo>
#include <vector>

#include "wordtool/word.h"

namespace wordtool {

/// @class WordList
/// @brief A thread-safe class for storing a list of unique words.
class WordList {
   public:
    /// @brief Adds a word to the word list if it doesn't already exist.
    /// @param word The word to be added.
    void InsertWord(const Word& word);

    /// @brief Returns the current word list.
    /// @return The current word list as a constant reference to a set of Word objects.
    const std::set<Word>& GetWords() const;

    /// @brief Sorts the word list in alphabetical order and returns it.
    /// @return The sorted word list as a vector of Word objects.
    std::vector<Word> SortAndGetWordList() const;

    /// @brief Checks if `end` was encountered while reading the input stream.
    /// @return True if `end` word was encountered, false otherwise.
    bool IsEndEncountered() const;

    /// @brief Sets the flag indicating whether `end` word was encountered while reading the input stream.
    /// @param endEncountered True if `end` word was encountered, false otherwise.
    void SetEndEncountered(bool endEncountered);

    /// @brief Searches for a word in the word list.
    /// @param word The word to search for.
    /// @return If found, returns a constant pointer to the Word object in the word list, nullptr otherwise.
    const Word* SearchWord(const Word& word) const;

   private:
    std::set<Word> words_;  ///< The set of unique words in the word list.
    bool end_encountered_{
        false};                 ///< Flag indicating whether `end` word was encountered while reading the input stream.
    mutable std::mutex mutex_;  ///< Mutex to protect the word list from concurrent access.
};

}  // namespace wordtool

#endif  // WORDTOOL_WORD_LIST_H
