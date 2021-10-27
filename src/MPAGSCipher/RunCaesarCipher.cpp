#include <vector>
#include <string>

#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText,
                            const size_t cipher_key, 
                            const bool decrypt) {
    /*
    Function to apply the Caesar cipher (encryption or decryption) on
    some given input string

    ARGUMENTS:

        const std::string& inputText           - input string to be encrypted/decrypted
        const size_t cipher_key                - key to be used by the Caesar cipher
        const bool decrypt                     - switch specifying whether to encrypt/decrypt

    RETURN:

        string containing the encrypted/decrypted text
    */


    // initialise alphabet container
    std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                                  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // initialise encrypted/decrypted text container
    std::string newText;
    // loop over input characters
    for (std::size_t i{0}; i < inputText.size(); i++) {
        // convert each character to ascii code
        // 'A' = 65, 'B' = '66', ... , 'Z' = 90
        // character's position in the alphabet is (ascii code) - 65 
        std::size_t index = ((std::size_t)inputText[i] - 65);
        if (!decrypt) {
            // if encrypting, add key to ascii code
            index += cipher_key;
        }
        else {
            // if decrypting, subtract key to ascii code
            index -= cipher_key;
        }
        // use index to find encrypted/decrypted letter
        char newLetter = alphabet[ (index % 26) ];
        // add new character to encrypted/decrypted text
        newText += newLetter;
    }
    // return encrypted/decrypted text
    return newText;
}