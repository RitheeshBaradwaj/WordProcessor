#include <gtest/gtest.h>

#include "wordtool/word.h"

using wordtool::Word;

class WordTest : public ::testing::Test {
   protected:
    void SetUp() override {
        // Set up the test fixture state
        word1_ = Word("hello");
        word2_ = Word("world");
    }

    Word word1_;
    Word word2_;
};

TEST_F(WordTest, ConstructorWithString_CreatesWordWithCorrectData) {
    // Arrange
    std::string data = "test";

    // Act
    Word word(data);

    // Assert
    ASSERT_EQ(word.GetData(), data);
}

TEST_F(WordTest, ConstructorWithString_CreatesWordWithCountOne) {
    // Arrange
    std::string data = "test";

    // Act
    Word word(data);

    // Assert
    ASSERT_EQ(word.GetCount(), 1);
}

TEST_F(WordTest, CopyConstructor_CreatesNewWordWithSameData) {
    // Arrange & Act
    Word word = Word(word1_);

    // Assert
    ASSERT_EQ(word.GetData(), word1_.GetData());
}

TEST_F(WordTest, CopyConstructor_CreatesNewWordWithSameCount) {
    // Arrange & Act
    Word word = Word(word1_);

    // Assert
    ASSERT_EQ(word.GetCount(), word1_.GetCount());
}

TEST_F(WordTest, MoveConstructor_CreatesNewWordWithSameData) {
    // Arrange & Act
    Word word = std::move(word1_);

    // Assert
    ASSERT_EQ(word.GetData(), "hello");
}

TEST_F(WordTest, MoveConstructor_CreatesNewWordWithSameCount) {
    // Arrange & Act
    Word word = std::move(word1_);

    // Assert
    ASSERT_EQ(word.GetCount(), 1);
}

TEST_F(WordTest, CopyAssignmentOperator_CreatesNewWordWithSameData) {
    // Arrange & Act
    Word word;
    word = word1_;

    // Assert
    ASSERT_EQ(word.GetData(), word1_.GetData());
}

TEST_F(WordTest, CopyAssignmentOperator_CreatesNewWordWithSameCount) {
    // Arrange & Act
    Word word;
    word = word1_;

    // Assert
    ASSERT_EQ(word.GetCount(), word1_.GetCount());
}

TEST_F(WordTest, MoveAssignmentOperator_CreatesNewWordWithSameData) {
    // Arrange & Act
    Word word;
    word = std::move(word1_);

    // Assert
    ASSERT_EQ(word.GetData(), "hello");
}

TEST_F(WordTest, MoveAssignmentOperator_CreatesNewWordWithSameCount) {
    // Arrange & Act
    Word word;
    word = std::move(word1_);

    // Assert
    ASSERT_EQ(word.GetCount(), 1);
}

TEST_F(WordTest, GetData_ReturnsCorrectData) {
    // Arrange & Act
    std::string data = "hello";

    // Assert
    ASSERT_EQ(word1_.GetData(), data);
}

TEST_F(WordTest, SetData_ChangesData) {
    // Arrange & Act
    std::string data = "world";
    word1_.SetData(data);

    // Assert
    ASSERT_EQ(word1_.GetData(), data);
}

TEST_F(WordTest, SetData_SetsCountToOne) {
    // Arrange & Act
    word1_.SetData("world");

    // Assert
    ASSERT_EQ(word1_.GetCount(), 1);
}

TEST_F(WordTest, GetCount_ReturnTheCountOfTheStoredWord) {
    // Arrange & Act
    int count = word1_.GetCount();

    // Assert
    EXPECT_EQ(1, count);
}

TEST_F(WordTest, IncrementCount_IncreasesCountByOne) {
    // Arrange
    Word word("test");

    // Act
    word.IncrementCount();

    // Assert
    ASSERT_EQ(2, word.GetCount());
}
