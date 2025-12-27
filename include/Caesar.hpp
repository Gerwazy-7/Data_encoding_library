#pragma once
#include "Cipher.hpp"
#include <vector>

class Caesar: public Cipher
{
    private:
        std::string m_key;
        std::vector<std::string> data;

    public:
        Caesar() = default;

        Caesar(std::string& key_val, std::vector<std::string>& data_val)
            : m_key(key_val), data(data_val)
        {}

};