/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:18:23 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/24 00:47:03 by aaydogdu         ###   ########.fr       */
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
		AForm(const std::string n, const int gS, const int gE);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		void beSigned(const Bureaucrat& b);
		
		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExecute() const;
	
		virtual void execute(Bureaucrat const & executor) const = 0;
		
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
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();	
	};
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif