/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:16:59 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 17:49:07 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "🟢 MutantStack output:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Extra test: copy constructor and assignment
	std::cout << "\n🟠 Copy and assignment test:" << std::endl;
	MutantStack<int> copyStack(mstack);
	MutantStack<int> assignStack;
	assignStack = mstack;
	std::cout << "CopyStack top: " << copyStack.top() << std::endl;
	std::cout << "AssignStack top: " << assignStack.top() << std::endl;

	// Extra test: MutantStack with std::string
	std::cout << "\n🟢 MutantStack<std::string> test:" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("hello");
	strStack.push("world");
	for (MutantStack<std::string>::iterator sit = strStack.begin(); sit != strStack.end(); ++sit)
		std::cout << *sit << std::endl;

	// Extra test: empty stack iteration
	std::cout << "\n🔴 Empty MutantStack iteration:" << std::endl;
	MutantStack<int> emptyStack;
	if (emptyStack.begin() == emptyStack.end())
		std::cout << "Empty stack: no elements to iterate." << std::endl;

	std::cout << "\n🔵 std::list output:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	return (0);
}
