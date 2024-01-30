/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:38:09 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 03:07:01 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

# define CONTACT_MAX 8
# define COLUMN_LEN 10
# define DISPLAY_LEN 16

class PhoneBook
{
	private:
		Contact			contacts[8];
		unsigned short	contact_count;
		unsigned short	oldest_index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void			set_contact_count(unsigned short contact_count);
		void			set_oldest_index(unsigned short olest_index);
		unsigned short	get_contact_count(void);
		unsigned short	get_oldest_index(void);
		void			add(void);
		void			search(void);
};

#endif