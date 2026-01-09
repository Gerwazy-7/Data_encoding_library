/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

/**
 * \file string_utilities.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing includes and functions used for operating on strings.
 */


#pragma once
#include <string>
#include <vector>

namespace JR
{
    namespace string_utilities
    {
        /**
         * \brief Change all chars in string to lowercase
         * \param to_lower_case String that will be changed
         * \return String with outcome.
         */
        std::string lowercase(const std::string& to_lower_case);

        /**
         * \brief Parse string.
         * Goes through every char, adds them to word and saves it
         * in individual string in vector.
         * \param to_be_parsed String that will be parsed
         * \return Vector of strings. Every string is individual word.
         */
        std::vector<std::string> parser(const std::string& to_be_parsed);
    }
}