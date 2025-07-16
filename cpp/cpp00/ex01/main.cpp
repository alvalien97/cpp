/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <alvalien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:55:02 by hzsurf            #+#    #+#             */
/*   Updated: 2025/07/08 16:18:36 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string to_uppercase(std::string c)
{
    int i;

    i = 0;
    while (c[i])
    {
        if (c[i] >= 'a' && c[i] <= 'z')
            c[i] = c[i] - 32;  
        i++;
    }
    return c;
}

int main(){
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter: (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        command = to_uppercase(command);
        if (command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH")
            phonebook.searchContacts();
        else if(command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
}
