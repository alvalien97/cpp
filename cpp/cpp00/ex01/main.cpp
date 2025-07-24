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

int main(){
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter: (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nSignal detected; exiting" << std::endl;
            break;
        }
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
