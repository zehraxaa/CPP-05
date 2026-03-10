/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:50:23 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/10 00:21:17 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		throw GradeTooHighException();
}

void Bureaucrat::decreament()
{
	if (this->grade < 150)
		this->grade += 1;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high! Try lower than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low. Try higher than 150";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	std::cout<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<"."<<std::endl;
	return os;
}