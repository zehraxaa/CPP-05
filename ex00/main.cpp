/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:54:47 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 14:41:07 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	
	try {
		b1 = new Bureaucrat("Josh", -1);
		std::cout<<*b1;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		b2 = new Bureaucrat("Micheal", 10);
		std::cout<<*b2;
	}
	catch(std::exception& e) {
		std::cerr<< e.what() << std::endl;
	}
	try {
		b3 = new Bureaucrat("Sam", 159);
		std::cout<<*b3;
	}
	catch(std::exception& e) {
		std::cerr<< e.what() << std::endl;
	}

	if (b1)
		delete b1;
	if (b2)
		delete b2;
	if (b3)
		delete b3;
	
	return 0;
}