/**
 * @file exceptions.hpp
 * @author Anthony Fabius
 * @brief Where all the exceptions are stored
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class SizeException : public std::logic_error {
  public:
    SizeException(const std::string& message) : std::logic_error(message) {}
};


#endif