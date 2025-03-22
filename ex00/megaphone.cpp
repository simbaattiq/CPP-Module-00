/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:01:20 by mel-atti          #+#    #+#             */
/*   Updated: 2024/12/30 21:16:12 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>


int	main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	std::string tmp;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" ;
		return (1);
	}
	while (i < ac)
	{
		tmp = av[i];
		j = 0;
		while (j < tmp.length())
		{
			std::cout << static_cast<char>(std::toupper(tmp[j]));
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return (0);
}
