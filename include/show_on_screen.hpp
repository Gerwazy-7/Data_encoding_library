/******************************************************************************
 * This file is a part of the JPO final project.                              *
 ******************************************************************************/

/**
 * \file show_on_screen.hpp
 * \author Rajski Jan
 * \date JAN 2026
 * \brief File containing functions used to show information for user.
 */


#pragma once
#include <iostream>

namespace JR
{
    namespace show_on_screen
    {
        /**
         * \brief Introduce application to user.
         * When program starts it shows user information about author and purpose
         * of application.
         */
        void introduce();

        /**
         * \brief Show user what ciphers are available for use.
         */
        void available_ciphers();
        
        /**
         * \brief Shou user that program is ending its working.
         */
        void ending_program();
    }
}