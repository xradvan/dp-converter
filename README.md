# MQ Analyzer
Supplementary software for the analysis of MQ cryptosystems

## Build and run
This project uses CMake as a build system:
1. Go to project directory
2. Run ./configure.py
3. cd .build
4. make
5. ./MQAnalyzer <path to config file>

## Build the docs
Doxygen is used to auto-generate docs from the source code. Further info at http://www.doxygen.nl/.
1. Go to docs directory
2. Run "doxygen"
3. Open docs/html/index.html in your favourite web browser

## Dependencies
This software is build on top of NTL library, therefore installing it is a must. Further info can be found at https://www.shoup.net/ntl/.
