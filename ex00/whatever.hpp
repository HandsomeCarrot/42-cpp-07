/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:19:42 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/13 15:47:44 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T& a, T& b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T& a, T& b)
{
	return (a > b ? a : b);
}

#endif /* WHATEVER_HPP */
