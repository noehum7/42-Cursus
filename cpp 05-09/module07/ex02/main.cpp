/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:45:21 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 18:02:37 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int	main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

// int main() {
//     std::cout << "🧪 === Array<T> Basic Tests ===" << std::endl;

//     // Test 1: Empty array
//     std::cout << "\n🟢 Test 1: Empty array" << std::endl;
//     Array<int> empty;
//     std::cout << "  ➡️ Size: " << empty.size() << std::endl;

//     // Test 2: Array with size and assignment
//     std::cout << "\n🟢 Test 2: Array with size 3" << std::endl;
//     Array<int> arr(3);
//     for (unsigned int i = 0; i < arr.size(); i++) {
//         arr[i] = (i + 1) * 5;
//         std::cout << "  ➡️ arr[" << i << "] = " << arr[i] << std::endl;
//     }

//     // Test 3: Copy constructor
//     std::cout << "\n🟢 Test 3: Copy constructor" << std::endl;
//     Array<int> copy(arr);
//     std::cout << "  ➡️ copy[0] = " << copy[0] << std::endl;

//     // Test 4: Out-of-bounds exception
//     std::cout << "\n🟢 Test 4: Out-of-bounds access" << std::endl;
//     try {
//         std::cout << "  ❌ Accessing arr[5]..." << std::endl;
//         std::cout << arr[5] << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "  ⚠️ Exception: " << e.what() << std::endl;
//     }

//     std::cout << "\n🏁 === Basic tests finished ===" << std::endl;
//     return 0;
// }
