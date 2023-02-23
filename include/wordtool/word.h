//==============================================================================

/// @file word.h
/// @brief Definition of the Word class.
//==============================================================================

#ifndef WORDTOOL_WORD_H
#define WORDTOOL_WORD_H

#include <string>

namespace wordtool {

/// @class Word
/// @brief A class representing a word and its count.
class Word {
   public:
    /// @brief Default constructor for Word class.
    Word();

    /// @brief Constructor that takes a string and initializes the count to 1.
    /// @param data The word to be stored.
    explicit Word(const std::string& data);

    /// @brief Copy constructor for Word class.
    /// @param other The Word object to be copied.
    Word(const Word& other);

    /// @brief Move constructor for Word class.
    /// @param other The Word object to be moved.
    Word(Word&& other);

    /// @brief Assignment operator for Word class.
    /// @param other The Word object to be assigned.
    /// @return The reference to the assigned Word object.
    Word& operator=(const Word& other);

    /// @brief Move assignment operator for Word class.
    /// @param other The Word object to be moved and assigned.
    /// @return The reference to the assigned Word object.
    Word& operator=(Word&& other);

    /// @brief Returns the stored word.
    /// @return The stored word as a constant reference to a string.
    const std::string& GetData() const;

    /// @brief Sets a new word data, incrementing the count.
    /// @param data The new word data to set.
    void SetData(const std::string& data);

    /// @brief Returns the count of the stored word.
    /// @return The count of the stored word as an integer.
    int GetCount() const;

    /// @brief Increments the count of the stored word by 1.
    /// @note this function should be used with a mutex lock
    void IncrementCount();

   private:
    std::string data_;  ///< The stored word.
    int count_;         ///< The count of the stored word.
};

// bool operator<(const Word& lhs, const Word& rhs) {
//     return lhs.GetData() < rhs.GetData();
// }

// bool operator==(const Word& lhs, const Word& rhs) {
//     return lhs.GetData() == rhs.GetData();
// }

}  // namespace wordtool

#endif  // WORDTOOL_WORD_H
