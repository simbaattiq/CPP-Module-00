/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:00:56 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/01 16:01:01 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    // std::cout << "Contacts class Instructore is called \n" ;
}

Contact::~Contact()
{
    // std::cout << "Contact class Destructor called \n";
}

void Contact::set_contact_index(int i)
{
    this->index = i;
}

void Contact::set_first_name(std::string str)
{
    this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
    this->last_name = str;    
}

void Contact::set_nick_name(std::string str)
{
    this->nickname = str;
}

void Contact::set_number(std::string str)
{
    this->number = str;
}

void Contact::set_dark_sec(std::string str)
{
    this->secret = str;
}

int Contact::get_contact_index(void)
{
    return (this->index);
}

std::string Contact::get_first_name(void)
{
    return (this->first_name);
}

std::string Contact::get_last_name(void)
{
    return (this->last_name);
}

std::string Contact::get_nick_name(void)
{
    return (this->nickname);    
}

std::string Contact::get_number(void)
{
    return (this->number);    
}

std::string Contact::get_dark_sec(void)
{
    return (this->secret);
}