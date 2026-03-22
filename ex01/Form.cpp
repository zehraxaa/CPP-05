/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:37:11 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/22 00:11:48 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("default"), sign(false), gSign(50), gExecute(10)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const std::string n, const int gS, const int gE)
	: name(n),
	  gSign(gS),
	  gExecute(gE)
{
	this->sign = false;
	std::cout<<"Form parameterized constructor called"<<std::endl;
	if (gS > 150 || gE > 150)
		throw Form::GradeTooLowException();
	else if (gS < 1 || gE < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other) : sign(other.sign), gSign(other.gSign), gExecute(other.gExecute)
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form& Form::operator=(const Form &other)
{
	std::cout<<"Form copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gSign)
		this->sign = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getSign() const
{
	return sign;
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
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
	std::cout<<"Form Name: "<<f.getName()<<std::endl;
	std::cout<<"Is Form signed?: "<<(f.getSign() ? "True" : "False")<<std::endl;
	std::cout<<"Form sign grade: "<<f.getGradeSign()<<std::endl;
	std::cout<<"Form execute grade: "<<f.getGradeExecute()<<std::endl;
	return os;
}