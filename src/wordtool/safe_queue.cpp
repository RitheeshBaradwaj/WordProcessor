#include "wordtool/safe_queue.h"

#include "wordtool/word.h"

namespace wordtool {

template <typename T>
void SafeQueue<T>::Push(T item) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(item);
    cv_.notify_one();
}

template <typename T>
bool SafeQueue<T>::TryPop(T item) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty()) {
        return false;
    }
    item = queue_.front();
    queue_.pop();
    return true;
}

template <typename T>
T SafeQueue<T>::WaitAndPop() {
    std::unique_lock<std::mutex> lock(mutex_);

    // wait until an item is available
    cv_.wait(lock, [this]() { return !queue_.empty(); });
    T item = queue_.front();
    queue_.pop();
    return item;
}

template <typename T>
bool SafeQueue<T>::Empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}

template class SafeQueue<Word>;

}  // namespace wordtool
