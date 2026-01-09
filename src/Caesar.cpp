#include "Caesar.hpp"
#include <stdexcept>
#include <cctype>

std::string JR::Caesar::run_caesar_cipher(int used_key)
{
    int length_of_vector = m_data.size();
    std::string result {};
    // Apply the Caesar ciphering technique for given data and key.
    for (int i = 0; i < length_of_vector; ++i)
    {
        int base = 0;
        int length_of_element = m_data[i].size();
        const std::string& word = m_data[i];
        std::string new_word = "";
        for (int j = 0; j < length_of_element; ++j)
        {
            if (std::islower(static_cast<unsigned char>(word[j]))) 
            {
                base = 'a';
                new_word += (word[j] - base + used_key + 26) % 26 + base;
            }
            else if (std::isupper(static_cast<unsigned char>(word[j]))) 
            {
                base = 'A';
                new_word += (word[j] - base + used_key + 26) % 26 + base;
            }
            // If char is not a letter save it unchanged to outcome string.
            else
            {
                new_word+=word[j];
            }
        }
        // Add spaces between words.
        if (i != (length_of_vector-1))
        {
            new_word += " ";
            
        }
        // Add word for returned string.
        result += new_word;
    }
    // Return string with changed data.
    return result;
}

JR::Caesar::Caesar(const std::string& key_val, const std::vector<std::string>& data_val)
    : m_key(key_check(key_val)), Cipher(data_val)
{
    // Throw error if given vector is empty.
    if (m_data.empty())
    {
        throw std::invalid_argument("[!] Data wasn't given!");
    }
}


JR::Caesar::Caesar(const int& key_val, const std::vector<std::string>& data_val)
    : m_key(key_val), Cipher(data_val)
{   
    // Throw error if given number is not in proper range.
    if (m_key < -26 || m_key > 26)
    {
        throw std::invalid_argument("[!] Given key must be in range [-26,26]!");
    }
    // Throw error if given vector is empty.
    if (m_data.empty())
    {
        throw std::invalid_argument("[!] Data wasn't given!");
    }
}


int JR::Caesar::key_check(const std::string& key)
{
    int i = 0;
    // Throw error if given string is empty.
    if (key.empty())
    {
        throw std::invalid_argument("[!] Key cannot be emtpty!");
    }
    // Throw error if only given data is a sign of a number.
    if ((key[0] == '-') || (key[0] == '+'))
    {
        if (key.length() == 1)
        {
            throw std::invalid_argument("[!] Given key cannot be +/- without specyfing number!");
        }
        i = 1;
    }
    // Throw error if given key is not a number.
    for (; i < key.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(key[i])))
        {
            throw std::invalid_argument("[!] Key must be a number!");
        }
    }
    // Convert given string to intiger.
    int int_key = stoi(key);
    // CHeck if given number is in proper range and throw error if it is not.
    if (int_key < -26 || int_key > 26)
    {
        throw std::invalid_argument("[!] Given key must be in range [-26,26]!");
    }
    // Return converted and validated key.
    return int_key;
}

std::string JR::Caesar::encode()
{
    // Call run_caesar_cipher with unchanged sign of a key (encrypt).
    return run_caesar_cipher(m_key);
}

std::string JR::Caesar::decode()
{
    // Call run_caesar_cipher with changed sign of a key (decode).
    return run_caesar_cipher(-m_key);
}
