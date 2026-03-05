/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:50:23 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/04 19:03:57 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Pam"), grade(75)
{
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
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
	if (this->grade < 1)
		this->grade += 1;
	else
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	std::cout<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<std::endl;
	return os;
}