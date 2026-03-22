/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:19:09 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/22 21:17:33 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("Zehra", 5);
	PresidentialPardonForm form("Ikamet");

	std::cout<<form<<std::endl;
	b1.signForm(form);
	b1.executeForm(form);

}