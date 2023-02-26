# WordProcessor Application

The WordProcessor application is a C++ program that reads a list of ASCII words from STDIN, removes duplicates, sorts the words alphabetically and prints them with the number of how many times each word was encountered. It also allows users to enter a word to look it up in the word list which was initially entered.

This ReadME file contains information on how to install and run the application, as well as the application's design page.

## Status

[![Build WorkProcessor Project](https://github.com/RitheeshBaradwaj/WordProcessor/actions/workflows/build-cpp.yaml/badge.svg?branch=main)](https://github.com/RitheeshBaradwaj/WordProcessor/actions/workflows/build-cpp.yaml)

## Design

The detailed design of the WordProcessor application can be found on the [Design Page](docs/DESIGN.md).

## CHANGELOG

The initial implementation of the application can be found in `challenge/` folder.
Changes made in the current version can be found on [CHANGELOG Page](CHANGELOG.md)

## Artifacts

All the test results including binaries, unit test results, code coverage reports can be available in `artifacts/` folder

## Table of Contents

* [Design Page](docs/DESIGN.md)

* [Installation Guide](README.md#installation-guide)

* [Suitable Compiler](README.md#suitable-compiler)

* [LCov for Coverage](README.md#lcov-for-coverage)

* [Google Test for Testing](README.md#google-test-for-testing)

* [Run Steps](README.md#run-steps)

## Install Build Dependencies

The following are the steps to install dependencies for Wordprocessor applications:

1. Update the package index on your Ubuntu system:

```shell
sudo apt-get update
```

2. Install the cmake, g++ compiler, lcov coverage tool, Google Test and Google Mock libraries and headers using apt-get:

```shell
sudo apt-get install -y googletest
```

3. Once the installation is complete, navigate to the /usr/src/googletest directory:

```shell
cd /usr/src/googletest
```

4. Build the Google Test and Google Mock libraries:

```shell
sudo cmake CMakeLists.txt
sudo make
```

5. Copy the compiled library files to the system library directory:

```shell
sudo cp lib/*.a /usr/lib
```

## Installation Guide

The following instructions explain how to install the WordProcessor application:

1. Install the dependencies mentioned above.
2. Clone the repository by running git clone https://github.com/example/WordProcessor.git.
3. Change to the project directory by running cd WordProcessor.
4. Build the application by running `build.sh`.

```shell
./build.sh -c
```

## Suitable Compiler

The WordProcessor application requires a suitable C++ compiler to be installed. The recommended compiler is g++.

## LCov for Coverage
The WordProcessor application uses LCov for coverage. To view the coverage report, run the following command:

```shell
make coverage
```

## Google Test for Testing

The WordProcessor application uses Google Test for testing. To run the tests, run the following command:

```shell
make test
```

## Run Steps

To run the WordProcessor application, follow these steps:

1. Change to the project directory by running `cd WordProcessor`.
2. Build the application using `build.sh` or `build.ps1` or manually. The binaries will be available in _bin folder.
3. Run the application by running `./_bin/bin/WordProcessor`. This will start the program and prompt the user to enter words to add to the word list.
4. Type in words, one per line, and press enter after each word.
5. Once finished entering words, type 'end' on a new line to stop entering words.
6. The application will then print the words in the list, sorted alphabetically and with the number of times each word was encountered.
7. To look up a word in the list, enter the word on a new line and press enter. The application will print whether the word is in the list and how many times it was encountered.
8. To exit the application, press Ctrl + D.

## Thank you!
