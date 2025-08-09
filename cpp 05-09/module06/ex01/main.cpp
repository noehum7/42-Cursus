/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:01:04 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:18:47 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::cout << "🔧 Serializer Test" << std::endl;
	std::cout << "==================" << std::endl;

	Data	original;

	original.name = "Pepito";
	original.age = 30;

	std::cout << "📊 Original Data:" << std::endl;
	std::cout << "   Name: " << original.name << std::endl;
	std::cout << "   Age: " << original.age << std::endl;
	std::cout << "   Address: " << &original << std::endl;

	std::cout << "\n🎯 TEST 1: Normal case";
	uintptr_t	serialized = Serializer::serialize(&original);
	std::cout << "\n🔀 Serialization:" << std::endl;
	std::cout << "   Address converted to integer: " << serialized << std::endl;

	Data*	deserializedPtr = Serializer::deserialize(serialized);
	std::cout << "\n🔄 Deserialization:" << std::endl;
	std::cout << "   Restored address: " << deserializedPtr << std::endl;

	std::cout << "\n🎯 Test Result:" << std::endl;
	if (deserializedPtr == &original)
	{
		std::cout << "   ✅ SUCCESS: Addresses match!" << std::endl;
		std::cout << "   📋 Data: " << deserializedPtr->name 
				  << " (age " << deserializedPtr->age << ")" << std::endl;
	}
	else
		std::cout << "   ❌ FAILURE: Addresses don't match!" << std::endl;
	return (0);
}
