/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

 /**
 * \file Caesar.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing declaration of class Caesar and its methods.
 */


#pragma once
#include "Cipher.hpp"
#include <vector>
#include <string>

namespace JR
{
    /**
     * \brief Definition of class Caesar.
     * It inherits from class Cipher. It has two constructors: default
     * and parametrized and also methods run_caesar_cipher(), key_check(),
     * encode() and decode().
     */
    class Caesar: public Cipher
    {
        private:
            /**
             * \brief It runs caesar cipher for given data.
             * The functions goes through every char in data and shifts letter
             * by number given in as the key.
             * \return String with changed by cipher data.
             */
            std::string run_caesar_cipher(int used_key);

        protected:
            /**
             * \brief Key used in working on data.
             */
            int m_key;
        
        public:
            /**
             * \brief Default constructor.
             */
            Caesar() = default;
            
            /**
             * \brief Parametrized constructor.
             * Initializes Caesar with given data and key.
             * \param key_val String containing an intiger. Given string is
             * converted for intiger by function key_check. Input is string instead
             * of intiger because it allows for better validating.
             * \param data_val Vector of strings to be encrypted/decrypted.
             * \throw std::invalid_argument If provided vector is empty, given key is not
             * a number, or not in proper range.
             */
            Caesar(const std::string& key_val, const std::vector<std::string>& data_val);
            
            /**
             * \brief Parametrized constructor.
             * Initializes Caesar with given data and key. In this version, key is given
             * as intiger.
             * \param key_val Intiger, key used in Caesar cipher.
             * \param data_val Vector of strings to be encrypted/decrypted.
             * \throw std::invalid_argument If provided vector is empty, given key is not
             * in correct range.
             */
            Caesar(const int& key_val, const std::vector<std::string>& data_val);

            /**
             * \brief Function used for validating given key.
             * It checks if given string is not empty, if it is not just
             * sign (+/-), if it is a number and if it is in correct range.
             * \param key String passed by user. It is validated and returned
             * as intiger.
             * \return Converted to intiger and validated key given by user.
             */
            int key_check(const std::string& key);

            /**
             * \brief It encrypts given data.
             * The function calls run_caesar_cipher with unchanged key given
             * by user and because of that it encrypts the data.
             * \return Encoded string
             */
            std::string encode() override;

            /**
             * \brief It decodes given data.
             * The function calls run_caesar_cipher with changed sign of a key
             * given by user and because of that it decrypts the data.
             * \return Decoded string.
             */
            std::string decode() override;
    };
}