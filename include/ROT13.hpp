/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

 /**
 * \file ROT13.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing declaration of class ROT13.
 */

#pragma once
#include "Caesar.hpp"

namespace JR
{
    /**
     * \brief Definition of class ROT13.
     * It inherits from Class Caesar. It has two constructors: default
     * and parametrized.
     */
    class ROT13: public JR::Caesar
    {
        
        public:
            /**
             * \brief Default constructor.
             */
            ROT13() = default;

            /**
             * \brief Parametrized constructor.
             * As ROT13 is a Caesar cipher with fixed key of 13, it initializes
             * Caesar with given data and a fixed key.
             * \param data_val Vector of strings to be encrypted/decrypted.
             * \throw std::invalid_argument If provided vector is empty.
             */
            ROT13(const std::vector<std::string>& data_val);
    };
}