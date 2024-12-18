#ifndef UTILS_H
#define UTILS_H

#include <string>

// Helper function to check if a character is in a given string
bool charIsAnyOfThese(char c, const std::string &chars)
{
    return chars.find(c) != std::string::npos;
}

#endif // UTILS_H