/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:50:23 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/11 00:22:39 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Pam"), grade(75)
{
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout<<"Bureaucrat parameterized constructor called"<<std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

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

void Bureaucrat::signForm(Form& form) const
{
	try {
		form.beSigned(*this);
		std::cout<<this->name<<" signed "<<form.getName()<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<this->name<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	std::cout<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<"."<<std::endl;
	return os;
}