/*
** EPITECH PROJECT, 2020
** name
** File description:
** desc
*/

#pragma once
#include <iostream>
#include <exception>

class Error : public std::exception {
    public:
        Error(const std::string &message = "Unknown error") noexcept;
        ~Error() noexcept;
        const char *what() const noexcept;
    private:
        std::string _message;
};