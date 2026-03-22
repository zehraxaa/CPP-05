/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:54:47 by aaydogdu          #+#    #+#             */
/*   Updated: 2026/03/20 00:40:34 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form f("izin kagidi", 71, 70);
	Bureaucrat b("Joshua", 70);

	std::cout<<b<<std::endl<<std::endl;
	std::cout<<f<<std::endl;
	b.signForm(f);
	std::cout<<f<<std::endl;
	b.signForm(f);
	std::cout<<f<<std::endl;
	
	return 0;
}