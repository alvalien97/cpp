/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzsurf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:55:24 by hzsurf            #+#    #+#             */
/*   Updated: 2025/07/08 12:55:26 by hzsurf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    int index;
public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif
