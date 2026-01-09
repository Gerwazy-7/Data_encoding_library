#include "Atbash.hpp"
#include <cctype>
#include <stdexcept>

JR::Atbash::Atbash(const std::vector<std::string>& data_val): Cipher(data_val)
{
    // Throw error if given vector is empty.
    if (m_data.empty())
    {
        throw std::invalid_argument("[!] Data wasn't given!");
    }
}

/**
 * Main logic of the cipher.
 * It goes through every char in string and replaces it with proper char.
 */
std::string JR::Atbash::encode()
{
    int length_of_vector = m_data.size();
    std::string ciphered {};

    for (int i = 0; i < length_of_vector; ++i)
    {
        const std::string& word = m_data[i];
        std::string new_word = "";

        for (char letter : word)
        {
            // Encoding uppercase letters i.e. A -> Z, C -> X
            if (std::isupper(letter))
            {
                new_word += (char)('Z' - (letter - 'A'));
            }
            // Encoding lowercase letters i.e. a -> z, c -> x
            else if (std::islower(letter))
            {
                new_word += (char)('z' - (letter - 'a'));
            }
            // Chars that are not letters go without changes.
            else
            {
                new_word += letter;
            }
        }
        // Adding spaces between words
        if (i != (length_of_vector-1))
        {
            new_word += " ";
            
        }
        ciphered += new_word;
    }
    return ciphered;
}

std::string JR::Atbash::decode()
{
    // Using function encode, as cipher is symmetrical
    return encode();
}