/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:40:39 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/05 01:40:46 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Use one of these commands: [ADD] [SEARCH] [EXIT]\n";
		std::cout << "PhoneBook> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.adding_handle();
		else if (input == "SEARCH")
		{
			phonebook.search_handle(input);
			continue;
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "ERROR: "<< input << ": Is Not a Valid Command" << std::endl;
	}
}
