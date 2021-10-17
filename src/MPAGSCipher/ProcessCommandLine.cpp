#include <iostream>
#include <vector>
#include <string>

#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFile,
                        std::string& outputFile,
                        int& cipher_key,
                        bool& decrypt) {
    
    /*
    Function to parse and process the arguments given to src/mpags-cipher 
    ARGUMENTS:

        const std::vector<std::string>& args   - Array of all arguments
        bool& helpRequested                    - bool signalling for help text
        bool& versionRequested                 - bool signalling for version number
        std::string& inputFile                 - directory of a file to read from
        std::string& outputFile                - directory of a file to write to
        int& cipher_key                        - key used to encrypt/decrypt input text
        bool& decrypt                          - switch used for decryption
    
    RETURN:

        bool specifying whether processComandLine was successful (0) or not (1)
    */

    const std::size_t nArgs{args.size()};
    for (std::size_t i{1}; i < nArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-k") {
            // Handle cipher key option
            i++;
            if (i == nArgs) {
                std::cerr << "[error] -k requires an integer argument \n";
                // exit main with non-zero return to indicate failure
                return 1;
            }
            try{cipher_key = std::stoi(args[i]);}
            catch(std::invalid_argument const &ex) {
                std::cerr << "[error] -k expected an integer key as input \n";
                return 1;
            }
        } else if (args[i] == "-d") {
            // Handle decrypt toggle option
            // if left unchanged, encryption is selected by default
            i++;
            if (i == nArgs) {
                std::cerr << "[error] -d requires an argument \n";
                // exit main with non-zero return to indicate failure
                return 1;
            }
            if (args[i] == "1") {
                decrypt = 1;
            } else if (args[i] != "0") {
                std::cerr << "[error] -d expected either '1' or '0' as input \n";
                // exit main with non-zero return to indicate failure
                return 1;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return 1;
        }
    }
    return 0;
}