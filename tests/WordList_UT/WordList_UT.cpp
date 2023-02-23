#include <gtest/gtest.h>

#include "wordtool/word_list.h"

using wordtool::Word;
using wordtool::WordList;

class WordListTest : public ::testing::Test {
   protected:
    void SetUp() override {
        word_list_.InsertWord(Word("hello"));
        word_list_.InsertWord(Word("world"));
        word_list_.InsertWord(Word("hello"));
        word_list_.InsertWord(Word("foo"));
        word_list_.InsertWord(Word("bar"));
    }

    WordList word_list_;
};

namespace wordtool {
bool operator==(const Word& lhs, const Word& rhs) {
    return lhs.GetData() == rhs.GetData();
}
}  // namespace wordtool

TEST_F(WordListTest, InsertWord_AddsNewWord) {
    // Arrange
    auto initial_size = word_list_.GetWords().size();
    auto word = Word("new");

    // Act
    word_list_.InsertWord(word);
    auto final_size = word_list_.GetWords().size();
    auto word_found = word_list_.SearchWord(word);

    // Assert
    EXPECT_EQ(final_size, initial_size + 1);
    EXPECT_TRUE(word_found);
}

TEST_F(WordListTest, InsertWord_IncrementExistingWord) {
    // Arrange
    auto initial_size = word_list_.GetWords().size();
    auto word = Word("bar");

    // Act
    word_list_.InsertWord(word);
    auto final_size = word_list_.GetWords().size();
    auto word_found = word_list_.SearchWord(word);

    // Assert
    EXPECT_EQ(final_size, initial_size);
    EXPECT_EQ(word_found->GetCount(), 2);
}

TEST_F(WordListTest, SortAndGetWordList_ReturnsSortedWordList) {
    // Arrange
    std::vector<Word> expected_words = {Word("bar"), Word("foo"), Word("hello"), Word("world")};

    // Act
    auto sorted_words = word_list_.SortAndGetWordList();

    // Assert
    EXPECT_EQ(sorted_words, expected_words);
}

TEST_F(WordListTest, IsEndEncountered_ReturnsFalseByDefault) {
    // Act
    auto is_end_encountered = word_list_.IsEndEncountered();

    // Assert
    EXPECT_FALSE(is_end_encountered);
}

TEST_F(WordListTest, SetEndEncountered_ChangesValue) {
    // Arrange
    auto is_end_encountered = false;

    // Act
    word_list_.SetEndEncountered(is_end_encountered);
    auto updated_is_end_encountered = word_list_.IsEndEncountered();

    // Assert
    EXPECT_EQ(updated_is_end_encountered, is_end_encountered);
}

TEST_F(WordListTest, SearchWord_ReturnsWordPointerIfExists) {
    // Arrange
    auto word = Word("hello");

    // Act
    auto word_ptr = word_list_.SearchWord(word);

    // Assert
    EXPECT_NE(word_ptr, nullptr);
    EXPECT_EQ(word_ptr->GetData(), word.GetData());
}

TEST_F(WordListTest, SearchWord_ReturnsNullptrIfNotExists) {
    // Arrange
    auto word = Word("not_exists");

    // Act
    auto word_ptr = word_list_.SearchWord(word);

    // Assert
    EXPECT_EQ(word_ptr, nullptr);
}
