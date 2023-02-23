#include "wordtool/word.h"

namespace wordtool {

Word::Word() : data_(""), count_(0) {
}

Word::Word(const std::string& data) : data_(data), count_(1) {
}

Word::Word(const Word& other) : data_(other.data_), count_(other.count_) {
}

Word::Word(Word&& other) : data_(std::move(other.data_)), count_(other.count_) {
}

Word& Word::operator=(const Word& other) {
    if (this != &other) {
        data_ = other.data_;
        count_ = other.count_;
    }
    return *this;
}

Word& Word::operator=(Word&& other) {
    if (this != &other) {
        data_ = std::move(other.data_);
        count_ = std::move(other.count_);
    }
    return *this;
}

const std::string& Word::GetData() const {
    return data_;
}

void Word::SetData(const std::string& data) {
    data_ = data;
    count_ = 1;
}

int Word::GetCount() const {
    return count_;
}

void Word::IncrementCount() {
    ++count_;
}

}  // namespace wordtool
