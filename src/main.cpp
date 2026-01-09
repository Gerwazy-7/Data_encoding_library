#include <main.hpp>

int main()
{
   // Introduce application for user
   JR::show_on_screen::introduce();

   // Flag used to determin whether program should be continued
   bool continue_program = true;

   // Main program loop
   while(continue_program)
   {
      bool check = JR::app_logic::cipher_process();
      if (check == false)
      {
         // Program ends when user type "exit"
         continue_program = false;
      }
   }
   return 0;
}