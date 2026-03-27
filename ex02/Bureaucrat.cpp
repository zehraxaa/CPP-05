/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:50:23 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 14:42:32 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <exception>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Pam"), grade(75)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::increament()
{
	if (this->grade > 1)
		this->grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreament()
{
	if (this->grade < 150)
		this->grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm& form) const
{
	if (form.getSign())
		throw FormAlreadySignedException();
	try {
		form.beSigned(*this);
		std::cout<<this->name<<" signed "<<form.getName()<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr<<this->name<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout<<this->name<<" executed "<<form.getName()<<std::endl;
	}
	catch (std::exception &e) {
		std::cerr<<this->name<<" couldn't execute "<<form.getName()<<" because "<<e.what()<<std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade too low";
}

const char* Bureaucrat::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	std::cout<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<"."<<std::endl;
	return os;
}