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

Form::Form() : name("default"), sign(false), gSign(50), gExecute(10)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const std::string n, bool s, const int gS, const int gE)
	: name(n),
	  sign(s),
	  gSign(gS),
	  gExecute(gE)
{
	std::cout<<"Form parameterized constructor called"<<std::endl;
}

Form::Form(const Form &other) : sign(other.sign), gSign(other.gSign), gExecute(other.gExecute)
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form& Form::&operator=(const Form &other)
{
	std::cout<<"Form copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->sign = other.sign;
		this->gSign = other.gSign;
		this->gExecute = other.gExecute;
	}
	return (*this);
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

void Form::beSigned(Bureaucrat& b) const
{
	if (b.getGrade() <= gSign)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return this->name;
}

std::string Form::getSign()
{
	if (this->sign == 0)
		return "False";
	else
		return "True";
}

int Form::getGradeSign() const
{
	return this->gSign;
}

int Form::getGradeExecute() const
{
	return this->gExecute;
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
	std::cout<<"Form Name: "<<this->getName()<<std::endl;
	std::cout<<"Is Form signed?: "<<this->this->getSign()<<std::endl;
	std::cout<<"Form sign grade: "<<this->this->getGradeSign()<<std::endl;
	std::cout<<"Form execute grade: "<<this->getGradeExecute()<<std::endl;
	return os;
}