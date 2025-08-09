/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:01:27 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:21:12 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int	random = rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated: A" << std::endl;
		return new A();
	case 1:
		std::cout << "Generated: B" << std::endl;
		return new B();
	case 2:
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified by pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified by pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified by pointer: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified by reference: A" << std::endl;
		return ;
	} catch (const std::exception&) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Identified by reference: B" << std::endl;
		return ;
	} catch (const std::exception&) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Identified by reference: C" << std::endl;
		return ;
	} catch (const std::exception&) {}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	srand(time(NULL));
	std::cout << "🔍 Dynamic Cast Test" << std::endl;
	std::cout << "====================" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\n🧪 --- Test " << (i + 1) << " ---" << std::endl;
		Base*	obj = generate();

		identify(obj);
		identify(*obj);
		std::cout << "🗑️  Deleting object..." << std::endl;
		delete obj;
	}
	std::cout << "\n✅ All tests completed!" << std::endl;
	return (0);
}
