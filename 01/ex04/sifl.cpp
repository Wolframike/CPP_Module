/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sifl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:27:06 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/24 18:43:23 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sifl.hpp"

Sifl::Sifl(std::string filename)
{
	this->_filename = filename;
}

Sifl::~Sifl() {}

void Sifl::setFilename(std::string filename)
{
	this->_filename = filename;
}

std::string Sifl::getFilename()
{
	return this->_filename;
}

void Sifl::replace(std::string s1, std::string s2)
{
	std::ifstream	file(this->_filename);
	std::string		line;
	std::string		content;

	if (file.is_open())
	{
		content = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	std::ofstream newfile(this->_filename + ".replace");
	newfile << content;
	newfile.close();
}