#include <main.hpp>

int main()
{
   // Introduce application for user
   JR::show_on_screen::introduce();

   // Main program loop
   while(1)
   {
      if (JR::app_logic::cipher_process() == false)
      {
         break;
      }
   }
   return 0;
}