/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 14:45:34 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));
	
	std::cout<<std::endl<<"***COMPANY HIRED A NEW INTERN***"<<std::endl<<std::endl;
	
	Intern internboy;
	AForm *rrf = NULL;
	AForm *ppf = NULL;
	AForm *scf = NULL;
	AForm *mistake = NULL;
	
	try {
		rrf = internboy.makeForm("robotomy request", "Bender");
		std::cout<<"The form internboy created: "<<std::endl<<*rrf<<std::endl;
	}
	catch (std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		mistake = internboy.makeForm("mistaken", "Format");
		std::cout<<"The form internboy created: "<<std::endl<<*mistake<<std::endl;
	}
	catch (std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try {
		ppf = internboy.makeForm("presidential pardon", "Carl");
		std::cout<<"The form internboy created: "<<std::endl<<*ppf<<std::endl;
	}
	catch (std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
	try {
		scf = internboy.makeForm("shrubbery creation", "whatsoever");
		std::cout<<"The form internboy created: "<<std::endl<<*scf<<std::endl;
	}
	catch (std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}

	if (ppf)
		delete ppf;
	if (mistake)
		delete mistake;
	if (rrf)
		delete rrf;
	if (scf)
		delete scf;
}