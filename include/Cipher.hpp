#pragma once
#include <string>

class Cipher
{
    public:
        virtual std::string encode() = 0;

        virtual std::string decode() = 0;

        virtual ~Cipher()
        {}
};  