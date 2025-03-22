/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:01:06 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/01 16:01:08 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;
    int index;
    
public:
    Contact();
    ~Contact();

    void set_contact_index(int i);
    void set_first_name(std::string str);
    void set_last_name(std::string str);
    void set_nick_name(std::string str);
    void set_number(std::string str);
    void set_dark_sec(std::string str);

    int         get_contact_index(void);
    std::string get_first_name(void);
    std::string get_last_name(void);
    std::string get_nick_name(void);
    std::string get_number(void);
    std::string get_dark_sec(void);
};

#endif