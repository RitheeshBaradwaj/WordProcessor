#include <thread>

#include "gtest/gtest.h"
#include "wordtool/word.h"

#define private public
#include "wordtool/safe_queue.h"
#undef private

using wordtool::SafeQueue;
using wordtool::Word;

class SafeQueueTest : public ::testing::Test {
   protected:
    SafeQueue<Word> q;
};

TEST_F(SafeQueueTest, Push_WaitsForWaitAndPop) {
    // Arrange & Act
    q.Push(Word("hello"));

    // Assert
    Word result = q.queue_.front();
    EXPECT_EQ(result.GetData(), "hello");
}

TEST_F(SafeQueueTest, TryPop_ReturnsTrueIfNotEmpty) {
    // Arrange
    Word result("hello");
    q.Push(result);

    // Act
    bool success = q.TryPop(result);

    // Assert
    EXPECT_TRUE(success);
    EXPECT_EQ(result.GetData(), "hello");
}

TEST_F(SafeQueueTest, TryPop_ReturnsFalseIfEmpty) {
    // Arrange
    Word result("world");

    // Act
    bool success = q.TryPop(result);

    // Assert
    EXPECT_FALSE(success);
    EXPECT_EQ(result.GetData(), "world");
}

TEST_F(SafeQueueTest, WaitAndPop_WaitsIfEmpty) {
    // Arrange
    std::thread t([&q = this->q] {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        q.Push(Word("hello"));
    });

    // Act
    Word result = q.WaitAndPop();

    // Assert
    EXPECT_EQ(result.GetData(), "hello");
    t.join();
}

TEST_F(SafeQueueTest, Empty_ReturnsTrueIfEmpty) {
    // Arrange

    // Act
    bool empty = q.Empty();

    // Assert
    EXPECT_TRUE(empty);
}

TEST_F(SafeQueueTest, Empty_ReturnsFalseIfNotEmpty) {
    // Arrange
    q.Push(Word("hello"));

    // Act
    bool empty = q.Empty();

    // Assert
    EXPECT_FALSE(empty);
}
