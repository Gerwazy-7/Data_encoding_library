#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Cipher.hpp"
#include "Caesar.hpp"

class Input_handler
{
    public:
        std::vector<std::string> parser(const std::string& to_be_parsed)
        {
            if (to_be_parsed == "")
            {
                return {};
            }
            std::string string = to_be_parsed;
            if (to_be_parsed[to_be_parsed.size()-1] != ' ')
            {
               string += ' ';
            }
            std::vector<std::string> parsed {};
            int string_size = string.size();
            std::string tmp = "";
            for (int i = 0; i < string_size; ++i)
            {
                if (string[i] != ' ')
                {
                    tmp += string[i];
                }
                else
                {
                    parsed.push_back(tmp);
                    tmp = "";
                }
            }
            return parsed;
        }

        template <typename T>
        void write_to_file(T key, std::string string, std::string filename)
        {
            const std::string folder = "../outcomes/";    
            const std::string filetype = ".txt";
            const std::string file = folder + filename + filetype;
            std::ofstream MyFile(file);
            MyFile << "Your data: \n" << string << "\nUsed key:\n" << key;
            MyFile.close();
        }

        Cipher* choose_cipher(std::string de_code, std::string cipher_choice, std::vector<std::string> data, std::string key,std::string filename)
        {
            if (cipher_choice == "Caesar")
            {
                return new Caesar(key, data);
            }
            else
                return nullptr;
        }

        void available_ciphers()
        {
            std::cout << "Type name of the cipher to use it, or <Exit> to exit program\n\n";
            std::cout << "Available ciphers:\n";
            std::cout << ">>> Caesar" << std::endl;

        }

        void ending_program()
        {
            std::cout << "Thank you for using my program!\n";
            std::cout << "Have a nice day!\n";
            std::cout << "\n======= PROGRAM ENDED =======\n" << std::endl;
        }

        void introduce()
        {
            std::cout << "\n==========================================================================\n" << std::endl;
            std::cout << "Author: Jan Rajski\n";
            std::cout << "This program was designed to encode/decode strings using popular ciphers!\n" << std::endl;
        }

        std::vector<std::string> what_to_do(std::string chosen_cipher)
        {
            std::vector<std::string> users_input {};
            std::string data {};
            std::cout << "You chosed: " << chosen_cipher << std::endl;
            users_input.push_back(chosen_cipher);
            std::cout << "Specify your purpose and filename in which outcome will be saved.\n";
            std::cout << "<encode/decode> <filename>\n";
            while(1)
            {
                std::cout << "> ";
                std::getline(std::cin, data);
                std::vector<std::string> parsed = parser(data);
                if ((parsed.size() == 2) && (parsed[0] == "encode" || parsed[0] == "decode"))
                {
                    users_input.push_back(parsed[0]);
                    users_input.push_back(parsed[1]);
                    return users_input; //0. cipher, 1. encode/decode, 2. filename
                }
                else
                {
                    std::cerr << "[!] Wrong input! Try again\n" << std::endl;
                    std::cout << "Usage: <encode/decode> <filename>" << std::endl;
                }
            }
        }

        struct Cipher_data 
        {
            Cipher* cipher_ptr;
            std::string mode;
            std::string filename;
            std::string key;
        };
        
        bool cipher_process()
        {
            Cipher_data current_task = users_choice();
            
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
                write_to_file(current_task.key, outcome, current_task.filename);
                std::cout << "Result: '" << outcome << "' has been written to file" << std::endl;
                delete current_task.cipher_ptr;
                std::cout << "\nWaiting for next instructions...\n" << std::endl;
                return true;
            }
            else
            {
                delete current_task.cipher_ptr;
                ending_program();
                return false;
            }
        }

        Cipher_data users_choice()
        {
            std::string data = "";
            std::string cipher_choice = "";
            std::string key = "";
            while(1)    
            {    
                available_ciphers();
                std::getline(std::cin, cipher_choice);
                if (cipher_choice == "Exit")
                {
                    return {nullptr,"exit","",""};
                }
                else if (cipher_choice != "Caesar")
                {
                    std::cerr << "[!] Given name doesn't match any available ciphers\n" << std::endl;
                }
                else
                {
                    break;
                }
            }
            std::vector<std::string> info = what_to_do(cipher_choice);
            while(true)
            {
                try
                {
                    std::cout << "Enter key: \n> ";
                    std::getline(std::cin, key);
                    std::cout << "Enter data to " << info[1] << ":\n> ";
                    std::getline(std::cin, data);
                    std::vector<std::string> parsed_data = parser(data);

                    if (info[0] == "Caesar")
                    {
                        return { new Caesar(key, parsed_data), info[1], info[2], key};
                    }
                }
                catch (const std::invalid_argument& e)
                {
                    std::cerr << "[!] Invalid argument: " << e.what() << std::endl;
                    std::cout << "Try again" << std::endl;
                }
            }
        }


};