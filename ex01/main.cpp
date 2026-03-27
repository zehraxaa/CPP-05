/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:54:47 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 14:49:31 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form f("Acceptance", 72, 70);
	Bureaucrat b("Joshua", 71);
	
	try {
		Bureaucrat b2;
		b2.signForm(f);
	}
	catch(std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	
	try {
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	try {
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr<<f.getName()<<" "<<e.what()<<std::endl;
	}

	return 0;
}