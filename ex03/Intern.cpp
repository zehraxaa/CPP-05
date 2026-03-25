/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:13:07 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/25 22:56:23 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form could not found";
}

AForm* Intern::makePPF(std::string target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::makeSCF(std::string target)
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRRF(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::makeForm(std::string fName, std::string target)
{
	std::string levels[] = { "robotomy request", "presidential pardon", "shrubbery creation" };
	
	AForm* (Intern::*func[])(std::string target) = {
		&Intern::makeRRF,
		&Intern::makePPF,
		&Intern::makeSCF
	};

	for (int i=0; i<3; i++)
	{
		if (levels[i] == fName)
			return (this->*func[i])(target);
	}
	std::cout<<fName<<" ";
	throw FormNotFoundException();
}