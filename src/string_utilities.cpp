#include "string_utilities.hpp"

std::string JR::string_utilities::lowercase(const std::string& to_lower_case)
{
    std::string outcome = to_lower_case;

    // Change every letter in string to lowercase.
    for (char &letter : outcome)
    {
        letter = std::tolower(static_cast<unsigned char>(letter));
    }
    return outcome;
}

std::vector<std::string> JR::string_utilities::parser(const std::string& to_be_parsed)
{
    // If there is nothing to parsed return empty vector.
    if (to_be_parsed == "")
    {
        return {};
    }
    std::string string = to_be_parsed;

    // Add auxiliary space in the end of a string.
    if (to_be_parsed[to_be_parsed.size()-1] != ' ')
    {
        string += ' ';
    }
    std::vector<std::string> parsed {};
    int string_size = string.size();
    std::string tmp = "";

    // Add chars to word as long as it is not space.
    for (int i = 0; i < string_size; ++i)
    {
        if (string[i] != ' ')
        {
            tmp += string[i];
        }
        // If space, add word to vector.
        else
        {
            parsed.push_back(tmp);
            tmp = "";
        }
    }
    return parsed;
}