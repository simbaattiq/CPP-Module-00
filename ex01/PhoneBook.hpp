/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:01:17 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/01 16:01:20 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>


class Contact;

class PhoneBook 
{
private:
    
    Contact contacts[8];
    int     count;
    int     i;

public:

    PhoneBook();
    ~PhoneBook();
    void	    adding_handle(void);
    void        add_contact(std::string fields[5]);
    void        search_handle(std::string input);
    void        search_contacts();
    void        display_contact(int indexx);
    int         get_list_size();
    std::string truncate(std::string str);
};

#endif