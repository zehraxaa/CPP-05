/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:20:06 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/22 21:11:58 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string trgt)
	: AForm("Presidential Pardon Form", 25, 5), target(trgt) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const char* PresidentialPardonForm::FormNotSignedException::what() const throw()
{
	return "Form not signed yet";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getSign() == false)
	{
		throw PresidentialPardonForm::FormNotSignedException();
		return;
	}
	if (executor.getGrade() <= this->getGradeExecute())
	{
		std::cout<<target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
	}
	else {
		throw Bureaucrat::GradeTooLowException();
	}
}