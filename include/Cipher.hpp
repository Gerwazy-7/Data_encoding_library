/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

 /**
 * \file Cipher.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing declaration of abstract class Cipher and its methods.
 */

#pragma once
#include <string>
#include <vector>
#include <string>

/**
 * \brief Definition of abstract class Cipher.
 * It works as a base for other classes that inferits after it.
 */
class Cipher
{
    protected:
        /**
         * \brief Data to be encrypted/decrypted.
         */
        std::vector<std::string> m_data;

    public:
        /**
         * \brief Default constructor.
         */
        Cipher() = default;

        /**
         * \brief Parametrized constructor.
         * It initialies Cipher with given data. It is used
         * by inheriting functions.
         */
        Cipher(const std::vector<std::string>& data_val)
            : m_data(data_val)
        {}

        /**
         * \brief Virtual method used by inheriting classes to
         * override and encode.
         */
        virtual std::string encode() = 0;

        /**
         * \brief Virtual method used by inheriting classes to
         * override and decode.
         */
        virtual std::string decode() = 0;

        /**
         * \brief Virtual destructor.
         * It is used to correctly delete existing inheriting classes 
         * objects.
         */
        virtual ~Cipher()
        {}
};  