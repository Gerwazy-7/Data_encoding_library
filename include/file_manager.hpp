/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

/**
 * \file file_manager.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing includes and function used for writing data to file
 */

#pragma once
#include <string>
#include <fstream>

namespace JR
{
    namespace file_manager
    {
        /**
         * \brief Function used for saving data in file.
         * It creates file in fixed folder and writes in it ciphered/decrypted
         * data and optionally key.
         * \param key Key used for encrypting/decrypting.
         * \param string Encrypted/decoded data
         * \param filename Name of the file in which information will be stored.
         */
        template <typename T>
        void write_to_file(T key, std::string string, std::string filename)
        {
            constexpr std::string folder = "../outcomes/";    
            constexpr std::string filetype = ".txt";
            const std::string file = folder + filename + filetype;
            std::ofstream MyFile(file);
            
            // If there is not key to write
            if (key == "")
            {
                MyFile << "Your data: \n" << string;
            }
            // If there is key
            else
            {
                MyFile << "Your data: \n" << string << "\nUsed key:\n" << key;
            }
            MyFile.close();
        }
    }
}