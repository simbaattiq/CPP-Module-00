/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:01:27 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/01 16:01:28 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static int is_valid_number(std::string str)
{
        int     i = 0;

        if (str[i] == '+')
            i++;
        while (str[i])
        {
			if (str[i] < '0' || str[i] > '9')
					return (0);
			i++;
        }
        return (1);
}

PhoneBook::PhoneBook()
{
    this->i = 0;
    this->count = 0;
}

PhoneBook::~PhoneBook()
{
}
void PhoneBook::add_contact(std::string fields[5])
{
    int i = this->i;
    this->contacts[i].set_contact_index(i);
    this->contacts[i].set_first_name(fields[0]);
    this->contacts[i].set_last_name(fields[1]);
    this->contacts[i].set_nick_name(fields[2]);
    this->contacts[i].set_number(fields[3]);
    this->contacts[i].set_dark_sec(fields[4]);
    if (this->count < 8)
    {
        this->count++;
    }
    this->i = (i + 1) % 8;
}

void PhoneBook::search_contacts()
{
    int size = 0;
    int i = -1;

    size = get_list_size();
    std::cout << "---------------------------------------------\n";
    std::cout << "|     index|first name| last name|  nickname|\n";
    std::cout << "---------------------------------------------\n";
    while (++i < size)
    {
        std::cout << "|" << std::setw(10) << this->contacts[i].get_contact_index() << "|";
        std::cout << std::setw(10) << this->truncate(contacts[i].get_first_name()) << "|";
        std::cout << std::setw(10) << this->truncate(contacts[i].get_last_name()) << "|";
        std::cout << std::setw(10) << this->truncate(contacts[i].get_nick_name()) << "|";
        std::cout << std::endl ;
        std::cout << "---------------------------------------------\n";
    }
}


void PhoneBook::display_contact(int indexx)
{
    std::cout << "Contact Number: " << indexx; 
    std::cout << " Detailed Information: \n";
    std::cout << "First Name    : " << this->contacts[indexx].get_first_name() << std::endl;
    std::cout << "Last Name     : " << this->contacts[indexx].get_last_name() << std::endl;
    std::cout << "Nick Name     : " << this->contacts[indexx].get_nick_name() << std::endl;
    std::cout << "Number        : " << this->contacts[indexx].get_number() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[indexx].get_dark_sec() << std::endl;
}

int PhoneBook::get_list_size()
{
    return (this->count);
}

std::string PhoneBook::truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void	PhoneBook::adding_handle(void)
{
	std::string	fields[5];
	std::cout << " *** Enter Contact's Information ***\n";
	std::cout << "First Name: ";
	std::getline(std::cin, fields[0]);
	std::cout << "Last Name: ";
	std::getline(std::cin, fields[1]);
	std::cout << "Nick Name: ";
	std::getline(std::cin, fields[2]);
	do
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, fields[3]);
		if (is_valid_number(fields[3]))
			break;
		std::cout << "Please input a valid number" << std::endl;
	} while (!is_valid_number(fields[3]));	
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, fields[4]);
	this->add_contact(fields);
	std::cout << "Contact Added Successfully!!!" << std::endl;
}

void PhoneBook::search_handle(std::string input)
{
	int index;

	this->search_contacts();
	std::cout << "\nInsert Index: ";
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= this->get_list_size())
	{
			std::cout << "ERROR: Invalid Index!" << std::endl;
			std::cin.clear();
			std::getline(std::cin, input);
			return ;
	}
	this->display_contact(index);
	std::cin.clear();
	std::getline(std::cin, input);
	return ;
}