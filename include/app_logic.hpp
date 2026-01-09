/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

/**
 * \file app_logic.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing includes and functions used app_logic.cpp file.
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Cipher.hpp"
#include "Caesar.hpp"
#include "Atbash.hpp"
#include "ROT13.hpp"
#include "string_utilities.hpp"
#include "file_manager.hpp"
#include "show_on_screen.hpp"
        
namespace JR 
{      
    namespace app_logic
    {     
        /**
         * \brief Struct used to hold information needed to encrypt or decrypt.
         * \param cipher_ptr Pointer for used cipher object.
         * \param mode String that holds information whether user want to encrypt
         * or decrypt.
         * \param filename String that holds filename for file with outcome.
         * \param key String that holds key used for encrypting/decrypting.
         */   
        struct Cipher_data 
        {
            Cipher* cipher_ptr;
            std::string mode;
            std::string filename;
            std::string key;
        };
        
        /**
         * \brief Get the name of the cipher that user wants to use.
         * It shows available ciphers, gets user's choice, changes it
         * to lower case and informs if it's incorrect.
         * * \note Functions work in a while loop until it gets data in correct form.
         * \warning This function returns pointer to a Cipher object created with "new".
         * User is responsible for deleting it.
         * \return Struct that holds information about:
         * - Pointer for a cipher object or nullptr if mode is "exit"
         * - mode (encrypting/decrypting or exit),
         * - filename used for storing a result,
         * - key if it is used while encrypting/decrypting.
         */
        Cipher_data users_choice();
        
        /**
         * \brief Function that specify the purpose of using ciphers and the output filename.
         * It ask user for purpose and filename and store it along with used cipher name.
         * \param chosen_cipher The name of a cipher that user chose to use.
         * \return Vector of strings that contains: 
         * - [0]: cipher name,
         * - [1]: encode/decode,
         * - [2]: filename.
         * * \note Function work in a while loop until it gets data in correct form.
         */
        std::vector<std::string> what_to_do(std::string chosen_cipher);
        
        /**
         * \brief Process data with previously chosen cipher and it's parameters.
         * Function calles appriopriate methods (encode/decode) and save outcome data to file.
         * * \note If previously chosen mode is "exit" it cleans up and signals to end program
         * \attention Function automatically deletes previously created Cipher object.
         * \return true if mode is not "exit", false if it is.
         */
        bool cipher_process();

    }
}