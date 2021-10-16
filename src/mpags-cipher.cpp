#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "MPAGSCipher/TransformChar.hpp" // added MPAGSCipher/ to remove error squigglies...
#include "MPAGSCipher/ProcessCommandLine.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    bool status = processCommandLine(cmdLineArgs,
                                     helpRequested,
                                     versionRequested,
                                     inputFile,
                                     outputFile);
    if (status) {
        // terminate after error in processing command line
        std::cout << "Exiting...\n";
        return 0;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Read in user input from stdin/file
    std::ifstream in_file {inputFile};
    if (!in_file.good()) {
        std::cerr << "Error reading input from file: " << inputFile << "\n";
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // loop over each character from user input
    if (inputFile.empty()) {
        std::cout << "No input file specified - enter input text: \n";
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
        }
    }
    else {
        while (in_file >> inputChar) {
            inputText += transformChar(inputChar);
        }
        in_file.close();
    }

    // print or write results
    if (outputFile.empty()) {
        std::cout << "No output file specified - printing results: \n";
        std::cout << inputText << "\n";
    }
    else {
        std::ofstream out_file {outputFile};
        out_file << inputText;
        out_file.close();   
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}