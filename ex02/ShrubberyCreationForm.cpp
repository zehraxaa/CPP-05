/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 23:41:51 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/27 00:02:39 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt)
	: AForm("Shrubbery Creation Form", 145, 137), target(trgt) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getSign() == false)
	{
		throw AForm::FormNotSignedException();
		return;
	}
	if (executor.getGrade() <= this->getGradeExecute())
	{
		std::string filename = this->target + "_shrubbery";
		std::ofstream outfile(filename.c_str());
		
		if (!outfile.is_open())
		{
			std::cout<<"Error! File could not opened."<<std::endl;
			return;
		}
		outfile << "               ,@@@@@@@," << std::endl;
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		outfile << "       |o|        | |         | |" << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		outfile.close();
		std::cout<<this->target<<"_shrubbery form created"<<std::endl;
	}
	else {
		throw Bureaucrat::GradeTooLowException();
	}
}