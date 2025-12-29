#include <iostream>
#include "Input_handler.hpp"

int main()
{
   Input_handler handler;
   handler.introduce();
   bool continue_program = true;
   while(continue_program)
   {
      bool check = handler.cipher_process();
      if (check == false)
      {
         continue_program = false;
      }
   }
   return 0;
}