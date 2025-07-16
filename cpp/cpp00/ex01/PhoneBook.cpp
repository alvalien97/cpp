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
    std::cout << "Adding contact #" << totalContacts + 1 << std::endl;
    contacts[index].setContact();
    
    if (totalContacts < 8)
        totalContacts++;
    else
        std::cout << "Contact list full, overwriting oldest contact." <<std::endl;
    index = (index + 1) % 8;
}

void PhoneBook::searchContacts() const {
    int displayCount;
    int realIndex;
    
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
        realIndex = (index + i) % 8;
        contacts[realIndex].displayShort(i);
    }

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || !isdigit(input[0])) {
        std::cout << "Invalid input. Must be a digit between 0 and " << totalContacts - 1 << "." << std::endl;
        return;
    }

    int i = input[0] - '0';
    if(i < 0 || i >= displayCount){
        std::cout << "Index out of range." << std::endl;
        return;
    }

    int realIndex = (index + i) % 8;
    contacts[realIndex].displayFull();
}
