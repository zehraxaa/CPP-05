/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 00:03:42 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	
	Bureaucrat b1("Zehra", 45);
	PresidentialPardonForm form1("Carl");
	ShrubberyCreationForm form2("aaa");
	RobotomyRequestForm form3("Sofia");

	try {
		std::cout<<form1<<std::endl;
		b1.signForm(form1);
		b1.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	
	try{
		std::cout<<form2<<std::endl;
		b1.signForm(form2);
		b1.executeForm(form2);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	
	try {
		std::cout<<form3<<std::endl;
		b1.signForm(form3);
		b1.executeForm(form3);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}