/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

 /**
 * \file Atbash.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing declaration of class Atbash and its methods.
 */

#pragma once
#include "Cipher.hpp"
#include <string>
#include <vector>


namespace JR
{
    /**
     * \brief Definition of class Atbash.
     * It inherits from class Cipher. It has two constructors: default
     * and parametrized and also method encode() and decode().
     */
    class Atbash: public Cipher
    {
        public:
            
            /**
             * \brief Default constructor.
             */
            Atbash() = default;
            
            /**
             * \brief Parametrized constructor.
             * Initializes Atbash with given data.
             * \param data_val Vector of strings to be encrypted/decrypted.
             * \throw std::invalid_argument If provided vector is empty.
             */
            Atbash(const std::vector<std::string>& data_val);

            /**
             * \brief It encrypts given data.
             * It changes n letter of alphabet and replace
             * it with 26-n letter, for instance A -> Z, c -> x.
             * \return Encoded string
             */
            std::string encode() override;
            
            /**
             * \brief It decrypts given data
             * As cipher is symmetrical, function encode is used
             * to decode.
             * \return Decoded string
             */
            std::string decode() override;
    };
}