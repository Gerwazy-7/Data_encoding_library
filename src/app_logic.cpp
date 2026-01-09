#include "app_logic.hpp"


JR::app_logic::Cipher_data JR::app_logic::users_choice()
{
    std::string data = "";
    std::string cipher_choice = "";
    std::string key = "";
    // Get users choice of ciphers
    while(1)    
    {    
        JR::show_on_screen::available_ciphers();
        std::getline(std::cin, cipher_choice);
        cipher_choice = JR::string_utilities::lowercase(cipher_choice);
        if (cipher_choice == "exit")
        {
            return {nullptr,"exit","",""};
        }
        else if ((cipher_choice != "caesar")
                && (cipher_choice != "atbash")
                && (cipher_choice != "rot13"))
        {
            std::cerr << "[!] Given name doesn't match any available ciphers\n" << std::endl;
        }
        else
        {
            break;
        }
    }
    /**
     * Get information about users intentions.
     */
    std::vector<std::string> info = JR::app_logic::what_to_do(cipher_choice);
    std::string cipher_name = info[0];
    std::string mode = info [1];
    std::string filename = info[2];
    while(true)
    {
        try
        {
            // Enter key for ciphers that need it.
            if (cipher_name == "caesar")
            {
                std::cout << "Enter key: \n> ";
                std::getline(std::cin, key);    
            }
            std::cout << "Enter data to " << mode << ":\n> ";
            std::getline(std::cin, data);
            std::vector<std::string> parsed_data = JR::string_utilities::parser(data);

            // Make new object depending on users choice.
            if (cipher_name == "caesar")
            {
                return { new JR::Caesar(key, parsed_data), mode, filename, key};
            }
            else if (cipher_name == "atbash")
            {
                return { new JR::Atbash(parsed_data), mode, filename, ""};
            }
            else if (cipher_name == "rot13")
            {
                return {new JR::ROT13(parsed_data), mode, filename, "13"};
            }
        }
        // Catch possible errors that occured during crearting objects.
        catch (const std::invalid_argument& e)
        {
            std::cerr << "[!] Invalid argument: " << e.what() << std::endl;
            std::cout << "Try again" << std::endl;
        }
    }
}

std::vector<std::string> JR::app_logic::what_to_do(std::string chosen_cipher)
        {
            std::vector<std::string> users_input {};
            std::string data {};
            std::cout << "You chosed: " << chosen_cipher << std::endl;
            users_input.push_back(chosen_cipher);
            std::cout << "Specify your purpose and filename in which outcome will be saved.\n";
            std::cout << "<encode/decode> <filename>\n";
            // Try to get proper data.
            while(1)
            {
                std::cout << "> ";
                std::getline(std::cin, data);
                data = JR::string_utilities::lowercase(data);
                std::vector<std::string> parsed = JR::string_utilities::parser(data);
                
                // Return vecotr of strings with data if user gave it correctly.
                if ((parsed.size() == 2) && (parsed[0] == "encode" || parsed[0] == "decode"))
                {
                    users_input.push_back(JR::string_utilities::lowercase(parsed[0]));
                    users_input.push_back(parsed[1]);
                    return users_input;
                }
                // If needed word order is not achieved, inform about error and try again.
                else
                {
                    std::cerr << "[!] Wrong input! Try again\n" << std::endl;
                    std::cout << "Usage: <encode/decode> <filename>" << std::endl;
                }
            }
        }

bool JR::app_logic::cipher_process()
{
    Cipher_data current_task = users_choice();
    
    // Process user's data with given instructions
    std::string outcome;
    if (!((current_task.mode == "exit") && current_task.cipher_ptr == nullptr))
    {
        if (current_task.mode == "encode")
        {
            outcome = current_task.cipher_ptr -> encode();
        }
        else if (current_task.mode == "decode")
        {
            outcome = current_task.cipher_ptr -> decode();
        }
        std::cout << "\nOperation successfull!\n" << std::endl;
        JR::file_manager::write_to_file(current_task.key, outcome, current_task.filename);
        std::cout << "Result: '" << outcome << "' has been written to file" << std::endl;
        delete current_task.cipher_ptr;
        std::cout << "\nWaiting for next instructions...\n" << std::endl;
        return true;
    }
    else
    {
        // If user wrote exit in function "users_choice", end program
        delete current_task.cipher_ptr;
        JR::show_on_screen::ending_program();
        return false;
    }
}
