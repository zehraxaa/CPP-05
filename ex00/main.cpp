/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:54:47 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/03 13:55:11 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1;
		b1.setGrade(149);
		std::cout<<b1<<std::endl;
		b1.decreament();
		std::cout<<b1<<std::endl;
		b1.decreament();
		std::cout<<b1<<std::endl;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	
	return 0;
}