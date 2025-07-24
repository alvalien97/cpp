/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <alvalien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:55:16 by hzsurf            #+#    #+#             */
/*   Updated: 2025/07/08 13:19:32 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

PhoneBook::PhoneBook() : totalContacts(0), index(0) {}

void PhoneBook::addContact() {
    std::cout << "Adding contact #" << index + 1 << std::endl;
    if (!contacts[index].setContact()) {
        std::cout << "Contact creation aborted.\n";
        return;
    }
    if (totalContacts < 8)
        totalContacts++;
    else
        std::cout << "Contact list full, overwriting oldest contact." <<std::endl;
    index = (index + 1) % 8;
}

void PhoneBook::searchContacts() const {
    int displayCount;
    
    if (totalContacts == 0){
        std::cout << "PhoneBook is empty. Add some contacts first." << std::endl;
        return;
    }
    std::cout << "      Index|First Name| Last Name| Nickname" << std::endl;
    std::cout << "-----------|----------|----------|---------" << std::endl;

    if (totalContacts < 8)
        displayCount = totalContacts;
    else
        displayCount = 8;
    for(int i = 0; i < displayCount; i++){
        contacts[i].displayShort(i);
    }
    std::cout << "Enter index to view details: ";
    std::string input;
    if (!std::getline(std::cin, input)) {
        std::cout << "End of input detected. Exiting search." << std::endl;
        return;
    }

    if (input.length() != 1 || !isdigit(input[0])) {
        std::cout << "Invalid input. Must be a digit between 0 and " << totalContacts - 1 << "." << std::endl;
        return;
    }

    int i = input[0] - '0';
    if(i < 0 || i >= displayCount){
        std::cout << "Index out of range." << std::endl;
        return;
    }
    contacts[i].displayFull();
}
