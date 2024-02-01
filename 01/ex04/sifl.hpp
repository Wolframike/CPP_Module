/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sifl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:24:53 by misargsy          #+#    #+#             */
/*   Updated: 2024/02/01 18:30:32 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIFL_HPP
# define SIFL_HPP

# include <iostream>
# include <fstream>

class Sifl
{
	private:
		std::string _filename;

	public:
		Sifl(std::string filename);
		~Sifl();
		void		setFilename(std::string filename);
		std::string	getFilename();
		void		replace(std::string s1, std::string s2);
};

#endif