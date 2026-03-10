/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:37:11 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/11 00:57:04 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form() : name("default"), sign(false), gSign(150), gExecute(150)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= gSign)
		sign = true;
	else
		Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Bureacrat's grade is too low to sign this form";
}

std::ostream& operator<<(std::ostream &os, const Form &fo)
{
	std::cout<<"Form "<<" "<<std::endl;
	return os;
}