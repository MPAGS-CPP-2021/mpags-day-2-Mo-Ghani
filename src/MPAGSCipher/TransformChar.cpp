#include <string>

#include "TransformChar.hpp"

std::string transformChar(const char in_char) {

    /*
    Function to transcribe input text into a consistent format
    (Alphabet and numerical characters only
     Letters are forced into uppercase
     numbers are replaced with their corresponding word in English)

    ARGUMENTS:

        const char in_char         - a character to be transcribed

    RETURN:
        
        string containing transcribed input character
    */

    std::string inputString;
    // Uppercase alphabetic characters
    if (std::isalpha(in_char)) {
        inputString += std::toupper(in_char);
    }
    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            inputString += "ZERO";
            break;
        case '1':
            inputString += "ONE";
            break;
        case '2':
            inputString += "TWO";
            break;
        case '3':
            inputString += "THREE";
            break;
        case '4':
            inputString += "FOUR";
            break;
        case '5':
            inputString += "FIVE";
            break;
        case '6':
            inputString += "SIX";
            break;
        case '7':
            inputString += "SEVEN";
            break;
        case '8':
            inputString += "EIGHT";
            break;
        case '9':
            inputString += "NINE";
            break;
    }
    // If the character isn't alphabetic or numeric, DONT add it
    return inputString;
}