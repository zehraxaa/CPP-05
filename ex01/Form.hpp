/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:16:49 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/22 00:03:43 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int gSign;
		const int gExecute;
	public:
		Form();
		Form(const std::string n, const int gS, const int gE);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		void beSigned(const Bureaucrat& b);
		
		std::string getName() const;
		bool getSign() const;
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