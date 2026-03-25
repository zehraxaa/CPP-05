/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/25 23:02:00 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));
	
	Bureaucrat b1("Zehra", 1);
	PresidentialPardonForm form1("Form1");
	ShrubberyCreationForm form2("Form2");
	RobotomyRequestForm form3("Form3");

	std::cout<<form1<<std::endl;
	b1.signForm(form1);
	b1.executeForm(form1);

	std::cout<<form2<<std::endl;
	b1.signForm(form2);
	b1.executeForm(form2);

	std::cout<<form3<<std::endl;
	b1.signForm(form3);
	b1.executeForm(form3);

	std::cout<<std::endl<<"***COMPANY HIRED A NEW INTERN***"<<std::endl<<std::endl;
	
	Intern internboy;
	AForm *rrf;
	rrf = internboy.makeForm("presidential pardon", "Sofia");
	std::cout<<"The form internboy created: "<<std::endl<<*rrf<<std::endl;

	delete rrf;
}