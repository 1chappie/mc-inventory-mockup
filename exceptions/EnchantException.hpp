//
// Created by stefa on 30.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ENCHANTEXCEPTION_HPP
#define MC_INVENTORY_MOCKUP_ENCHANTEXCEPTION_HPP

#include <exception>
#include <string>

class EnchantException : public std::exception {
private:
    std::string message;
public:
    EnchantException(const std::string &_message) : message(_message) {}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //MC_INVENTORY_MOCKUP_ENCHANTEXCEPTION_HPP
