/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:28:28 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/17 12:12:43 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool sign;
		const int gSign;
		const int gExecute;
	public:
		AForm();
		AForm(const std::string n, bool s, const int gS, const int gE);
		AForm(const Form &other);
		AForm &operator=(const Form &other);
		virtual ~AForm();

		void beSigned(const Bureaucrat& b);
		
		std::string getName() const;
		std::string getSign() const;
		int getGradeSign() const;
		int getGradeExecute() const;
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();	
	};
};

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif