/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:24:52 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/22 23:43:50 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), gSign(50), gExecute(10)
{}

AForm::AForm(const std::string n, const int gS, const int gE)
	: name(n),
	  gSign(gS),
	  gExecute(gE)
{
	this->sign = false;
	if (gS > 150 || gE > 150)
		throw AForm::GradeTooLowException();
	else if (gS < 1 || gE < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other) : sign(other.sign), gSign(other.gSign), gExecute(other.gExecute)
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gSign)
		this->sign = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getSign() const
{
	return sign;
}

int AForm::getGradeSign() const
{
	return this->gSign;
}

int AForm::getGradeExecute() const
{
	return this->gExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed yet";
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
	std::cout<<"Form Name: "<<f.getName()<<std::endl;
	std::cout<<"Is Form signed?: "<<(f.getSign() ? "True" : "False")<<std::endl;
	std::cout<<"Form sign grade: "<<f.getGradeSign()<<std::endl;
	std::cout<<"Form execute grade: "<<f.getGradeExecute()<<std::endl;
	return os;
}