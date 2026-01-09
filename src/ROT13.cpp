#include "ROT13.hpp"

// Create object of class Caesar with fixed key.
JR::ROT13::ROT13(const std::vector<std::string>& data_val): Caesar("13", data_val)
{}