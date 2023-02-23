# Change Log

All notable changes to this package will be documented in this file.
This package adheres to [Semantic Versioning](http://semver.org/).

## 1.0.0 release

### Breaking Changes

* Change the name of public API: readInputWords() to ReadInputWords()following Google C++ Coding Styles.
* Change the name of public API: lookupWords() to LookupWords() following Google C++ Coding Styles.

### Features

* Add WordProcessor, SafeQueue, WordList, Word classes to implement word processor application.
* WordList class can be used to manage the word list and handle thread-safety issues.
* WordProcessor class can be used to handle input processing and avoid the use of unsafe functions.
* SafeQueue class can be used to handle the producer-consumer problem and avoid the use of `s_word` and potential race conditions.

### Documentation

* Added detailed-design documentation and WordProcessor sequence diagram.
* Add README and CHANGELOG

### Bug Fixes

* Improvements: Follow modern C++ coding standards, paradigms and styles.
* Improvements: Added unit tests and code coverage generation for improved software quality and reliability.
* Fixed the issue with use of s_word which is not thread-safe as multiple threads can try to access it simultaneously leading to race conditions.
* Fixed the use of std::gets as it is unsafe and doesn't check for buffer overflow leading to potential security vulnerabilities.
* Fixed the use of std::strcpy and std::strcmp as it is unsafe as they don't check for buffer overflow leading to potential security vulnerabilities.
