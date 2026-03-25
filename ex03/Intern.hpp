/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:13:58 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/25 22:37:35 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string.h>

class Intern
{
	private:
		AForm* makePPF(std::string target);
		AForm* makeSCF(std::string target);
		AForm* makeRRF(std::string target);
		
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm* makeForm(std::string fName, std::string target);
	
	class FormNotFoundException : public std::exception
	{
		public:
			const char* what() const throw();	
	};
};

#endif