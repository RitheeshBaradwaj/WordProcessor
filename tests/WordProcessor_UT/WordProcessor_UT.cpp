#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define private public
#include "wordtool/word_processor.h"
#undef private

using wordtool::WordProcessor;

class WordProcessorTest : public ::testing::Test {
   protected:
    void SetUp() override {
        // Redirect cin to a stringstream to simulate input
        saved_cin = std::cin.rdbuf();
        std::cin.rdbuf(input_stream.rdbuf());
    }

    void TearDown() override {
        // Restore cin
        std::cin.rdbuf(saved_cin);
    }

    // Stream to simulate input
    std::stringstream input_stream;
    // Saved cin buffer
    std::streambuf* saved_cin;
};

TEST_F(WordProcessorTest, ReadInputWords) {
    // Arrange
    WordProcessor wp;

    // Simulate input
    input_stream << "apple\n";
    input_stream << "banana\n";
    input_stream << "apple\n";
    input_stream << "end\n";

    // Act
    wp.ReadInputWords();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto words = wp.word_list_.SortAndGetWordList();

    // Assert
    ASSERT_EQ(words.size(), 2);

    EXPECT_EQ(words[0].GetData(), "apple");
    EXPECT_EQ(words[0].GetCount(), 2);

    EXPECT_EQ(words[1].GetData(), "banana");
    EXPECT_EQ(words[1].GetCount(), 1);
}

TEST_F(WordProcessorTest, LookupWords) {
    // Arrrange
    WordProcessor wp;

    // Simulate input
    input_stream << "apple\n";
    input_stream << "banana\n";
    input_stream << "apple\n";
    input_stream << "end\n";
    input_stream << "apple\n";
    input_stream << "banana\n";
    input_stream << "cherry\n";
    input_stream << EOF;

    wp.ReadInputWords();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    testing::internal::CaptureStdout();

    // Act
    wp.LookupWords();
    std::string output = testing::internal::GetCapturedStdout();

    // Assert
    EXPECT_THAT(output, testing::HasSubstr("'apple' was present 2 times in the word list"));
    EXPECT_THAT(output, testing::HasSubstr("'banana' was present 1 times in the word list"));
    EXPECT_THAT(output, testing::HasSubstr("'cherry' was NOT found in the initial word list"));
}

TEST_F(WordProcessorTest, PrintWordList) {
    // Arrange
    WordProcessor wp;

    // Simulate input
    input_stream << "apple\n";
    input_stream << "banana\n";
    input_stream << "apple\n";
    input_stream << "end\n";

    wp.ReadInputWords();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    testing::internal::CaptureStdout();
    // Act
    wp.PrintWordList();
    std::string output = testing::internal::GetCapturedStdout();

    // Assert
    EXPECT_THAT(output, testing::HasSubstr("apple: 2"));
    EXPECT_THAT(output, testing::HasSubstr("banana: 1"));
}
