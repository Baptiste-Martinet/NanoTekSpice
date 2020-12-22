/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#include "Error.hpp"

Error::Error(const std::string &message) noexcept : _message(message)
{
}

Error::~Error() noexcept
{
}

const char *Error::what() const noexcept
{
    return (this->_message.c_str());
}