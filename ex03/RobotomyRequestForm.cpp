/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:26:07 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/26 00:21:41 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string trgt)
	: AForm("Robotomy Request Form", 72, 45), target(trgt) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char* RobotomyRequestForm::RobotomyRequestFailedException::what() const throw()
{
	return "Robotomy Request failed";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getSign() == false)
	{
		throw AForm::FormNotSignedException();
		return;
	}
	std::cout<<"Vrrrrrrrrr Bzzzzzzzzz Trrrrrrr"<<std::endl;
	if (executor.getGrade() <= this->getGradeExecute())
	{
		if (std::rand() % 2 == 0)
			std::cout<<this->target<<" Robotomy Request successful"<<std::endl;
		else {
			std::cerr<<this->target<<" ";
			throw RobotomyRequestFailedException();
		}
	}
	else {
		throw Bureaucrat::GradeTooLowException();
	}
}