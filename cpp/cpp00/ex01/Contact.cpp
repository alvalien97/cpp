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

void printField(const std::string& str){
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::string(10 - str.length(), ' ') << str;
}

std::string Contact::getNonEmptyInput(const std::string& prompt)
{
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "No puede estar vacio, intente de nuevo. \n";
    } while (input.empty());
    return input;
}

void Contact::setContact(){
    firstName = getNonEmptyInput("First Name: ");
    lastName = getNonEmptyInput("Last Name: ");
    nickName = getNonEmptyInput("Nickname: ");
    phoneNumber = getNonEmptyInput("Phone Number: ");
    darkestSecret = getNonEmptyInput("Darkest Secret: ");
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
