/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:38:07 by misargsy          #+#    #+#             */
/*   Updated: 2024/01/31 03:02:39 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		void			set_first_name(std::string first_name);
		void			set_last_name(std::string last_name);
		void			set_nickname(std::string nickname);
		void			set_phone_number(std::string phone_number);
		void			set_darkest_secret(std::string darkest_secret);
		std::string		get_first_name(void);
		std::string		get_last_name(void);
		std::string		get_nickname(void);
		std::string		get_phone_number(void);
		std::string		get_darkest_secret(void);
};

#endif
