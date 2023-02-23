//==============================================================================

/// @file safe_queue.h
/// @brief Definition of the SafeQueue class.
//==============================================================================

#ifndef WORDTOOL_SAFE_QUEUE_H
#define WORDTOOL_SAFE_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>

namespace wordtool {

/// @class SafeQueue
/// @brief A thread-safe queue implementation.
/// @tparam T The type of elements to be stored in the queue.
template <typename T>
class SafeQueue {
   public:
    /// @brief Adds an item to the end of the queue.
    /// @param item The item to be added.
    void Push(T item);

    /// @brief Attempts to remove an item from the front of the queue.
    /// @param item The variable where the removed item will be stored.
    /// @return True if an item was removed, false otherwise.
    bool TryPop(T item);

    /// @brief Waits until an item is available, then removes and returns it.
    /// @return The item at the front of the queue.
    T WaitAndPop();

    /// @brief Checks if the queue is currently empty.
    /// @return True if the queue is empty, false otherwise.
    bool Empty() const;

   private:
    std::queue<T> queue_;         ///< The underlying queue.
    mutable std::mutex mutex_;    ///< Mutex to protect the queue from concurrent access.
    std::condition_variable cv_;  ///< Condition variable to signal threads waiting for queue updates.
};

}  // namespace wordtool

#endif  // WORDTOOL_SAFE_QUEUE_H
