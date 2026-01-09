#include "show_on_screen.hpp"

 void JR::show_on_screen::introduce()
{
    std::cout << "\n==========================================================================\n\n";
    std::cout << "Author: Jan Rajski\n";
    std::cout << "This application was designed to encode/decode strings using popular ciphers!\n" << std::endl;
}

void JR::show_on_screen::available_ciphers()
{
    std::cout << "Type name of the cipher to use it, or <exit> to exit program\n\n";
    std::cout << "Available ciphers:\n";
    std::cout << ">>> Atbash" << std::endl;
    std::cout << ">>> Caesar" << std::endl;
    std::cout << ">>> ROT13" << std::endl;   
}

void JR::show_on_screen::ending_program()
{
    std::cout << "Thank you for using my program!\n";
    std::cout << "Have a nice day!\n";
    std::cout << "\n================ PROGRAM ENDED ================\n" << std::endl;
}