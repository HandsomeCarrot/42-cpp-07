/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:28:45 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/13 15:43:39 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// ===== ITER ===== //

template <typename T, typename Function>
void iter(T* array, const unsigned int length, Function f)
{
	if (!array || !f)
		return ;

	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

// ===== HELPERS ===== //

# include <iostream>

template <typename T>
void print(const T& a)
{
	std::cout << a << std::endl;
}

//template <typename T>
//void add(T& a)
//{
//	a++;
//}

//template <typename T>
//void subtract(T& a)
//{
//	a--;
//}

#endif /* ITER_HPP */