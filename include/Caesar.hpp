#pragma once
#include "Cipher.hpp"
#include <vector>
#include <stdexcept>
#include <string>
#include <cctype>

class Caesar: public Cipher
{
    private:
        int m_key;
        std::vector<std::string> m_data;

    public:
        Caesar() = default;

        Caesar(const std::string& key_val, const std::vector<std::string>& data_val)
            : m_key(key_check(key_val)), m_data(data_val)
        {
            if (m_data.empty())
            {
                throw std::invalid_argument("Data weren't given!");
            }
        }

        int key_check(const std::string& key)
        {
            int i = 0;
            if (key.empty())
            {
                throw std::invalid_argument("Key cannot be emtpty!");
            }
            if ((key[0] == '-') || (key[0] == '+'))
            {
                if (key.length() == 1)
                {
                    throw std::invalid_argument("Given key cannot be +/- without specyfing number!");
                }
                i = 1;
            }
            for (; i < key.length(); ++i)
            {
                if (!std::isdigit(static_cast<unsigned char>(key[i])))
                {
                    throw std::invalid_argument("Key must be a number!");
                }
            }
            int int_key = stoi(key);
            if (int_key < -26 || int_key > 26)
            {
                throw std::invalid_argument("Given key must be in range [-26,26]!");
            }
            return int_key;
        }

        std::string encode() override
        {
            int length_of_vector = m_data.size();
            std::string ciphered {};
            for (int i = 0; i < length_of_vector; ++i)
            {
                int base = 0;
                int length_of_element = m_data[i].size();
                std::string word = m_data[i];
                std::string new_word = "";
                for (int j = 0; j < length_of_element; ++j)
                {
                    if (std::islower(static_cast<unsigned char>(word[j]))) 
                    {
                        base = 'a';
                        new_word += (word[j] - base + m_key + 26) % 26 + base;
                    }
                    else if (!isalpha(word[j]))
                    {
                        new_word+=word[j];
                    }
                    else
                    {
                        base = 'A';
                        new_word += (word[j] - base + m_key + 26) % 26 + base;
                    }
                }
                if (i != (length_of_vector-1))
                {
                    new_word += " ";
                    
                }
                ciphered += new_word;
            }
            return ciphered;
        }

        std::string decode() override
         {
            int length_of_vector = m_data.size();
            std::string deciphered {};
            for (int i = 0; i < length_of_vector; ++i)
            {
                int decipher_key = -m_key;
                int base = 0;
                int length_of_element = m_data[i].size();
                std::string word = m_data[i];
                std::string new_word = "";
                for (int j = 0; j < length_of_element; ++j)
                {
                    if (std::islower(static_cast<unsigned char>(word[j]))) 
                    {
                        base = 'a';
                        new_word += (word[j] - base + decipher_key + 26) % 26 + base;
                    }
                    else if (!isalpha(word[j]))
                    {
                        new_word+=word[j];
                    }
                    else
                    {
                        base = 'A';
                        new_word += (word[j] - base + decipher_key + 26) % 26 + base;
                    }
                }
                if (i != (length_of_vector-1))
                {
                    new_word += " ";
                    
                }
                deciphered += new_word;
            }
            return deciphered;
        }

};