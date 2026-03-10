/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:16:49 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/11 00:42:41 by aaydogdu         ###   ########.fr       */
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
		Form(std::string name, bool sign, const int gSign, const int gExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool getSign();
		int getGradeSign() const;
		int getGradeExecute() const;
		void beSigned(Bureaucrat b);
	
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

std::ostream& operator<<(std::ostream &os, const Form &fo);

#endif