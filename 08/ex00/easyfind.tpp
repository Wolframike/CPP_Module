/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:52:17 by misargsy          #+#    #+#             */
/*   Updated: 2024/04/30 21:02:01 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void easyfind (T &container, int index)
{
	typename T::iterator it = std::find(container.begin(), container.end(), index);
	if (it == container.end())
		throw std::out_of_range("easyfind: Element not found");
}
