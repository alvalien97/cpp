/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzsurf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:54:40 by hzsurf            #+#    #+#             */
/*   Updated: 2025/07/08 12:54:42 by hzsurf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

bool isAscii(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        unsigned char c = str[i];
        if (c < 32 || c > 126)
            return false;
    }
    return true;
}

void printField(const std::string& str){
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::string(10 - str.length(), ' ') << str;
}

std::string Contact::getNonEmptyInput(const std::string& prompt)
{
    std::string input;
    while (true){
        std::cout << prompt;
        if (!std::getline(std::cin, input)){
            std::cout << "\nExiting..." << std::endl;
            return "";
        }
        if (input.empty()){
            std::cout << "Cannot be empty, try again.\n";
            continue;
        }
        if (!isAscii(input)) {
            std::cout << "Only ASCII characters are allowed. Try again.\n";
            continue;
        }
        return input;
    }
}

bool isValidPhoneNumber(const std::string& number) {
    
    size_t start = 0;

    if (number.empty())
        return false;
    if (number[0] == '+')
        start = 1;
    for (size_t i = start; i < number.length(); ++i) {
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

bool Contact::setContact(){
    firstName = getNonEmptyInput("First Name: ");
    if (firstName.empty()) return false; 
    lastName = getNonEmptyInput("Last Name: ");
    if (lastName.empty()) return false;
    nickName = getNonEmptyInput("Nickname: ");
    if (nickName.empty()) return false;
    while (true) {
        phoneNumber = getNonEmptyInput("Phone Number (digits only, optional '+' at start): ");
        if (phoneNumber.empty()) return false;
        if (isValidPhoneNumber(phoneNumber))
            break;
        std::cout << "Invalid phone number format. Try again.\n";
    }
    darkestSecret = getNonEmptyInput("Darkest Secret: ");
    if (darkestSecret.empty()) return false;
    return true;
}

void Contact::displayShort(int index) const {
    std::cout << "          " << index << "|";
    printField(firstName);
    std::cout << "|";
    printField(lastName);
    std::cout << "|";
    printField(nickName);
    std::cout << std::endl;
}

void Contact::displayFull() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret <<std::endl;

}
