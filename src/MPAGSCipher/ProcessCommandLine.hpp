#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <vector>
#include <string>

// header for processComandLine.cpp

bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFile,
                        std::string& outputFile,
                        size_t& cipher_key,
                        bool& decrypt);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP