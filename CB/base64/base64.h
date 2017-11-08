#ifndef BASE64_H
#define BASE64_H

#include <string>

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);
#include "base64.cpp"
#endif // BASE64_H
