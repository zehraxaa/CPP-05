/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:54:47 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/10 00:35:42 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = NULL;
	
	try {
		b1 = new Bureaucrat("Josh", -100000);

		std::cout<<"What is b? "<<*b1;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	if (b1)
		delete b1;
	
	return 0;
}