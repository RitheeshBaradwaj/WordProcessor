#include "wordtool/word_list.h"

namespace wordtool {

void WordList::InsertWord(const Word& word) {
    if (!end_encountered_) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = words_.find(word);
        if (it != words_.end()) {
            const_cast<Word*>(&(*it))->IncrementCount();
            return;
        }
        words_.insert(word);
    }
}

const std::set<Word>& WordList::GetWords() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return words_;
}

bool operator<(const Word& lhs, const Word& rhs) {
    return lhs.GetData() < rhs.GetData();
}

std::vector<Word> WordList::SortAndGetWordList() const {
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<Word> sorted_words(words_.begin(), words_.end());
    std::sort(sorted_words.begin(), sorted_words.end(), [](const Word& a, const Word& b) { return a < b; });
    return sorted_words;
}

bool WordList::IsEndEncountered() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return end_encountered_;
}

void WordList::SetEndEncountered(bool end_encountered) {
    std::lock_guard<std::mutex> lock(mutex_);
    end_encountered_ = end_encountered;
}

const Word* WordList::SearchWord(const Word& word) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = words_.find(word);
    return (it != words_.end()) ? &(*it) : nullptr;
}

}  // namespace wordtool
