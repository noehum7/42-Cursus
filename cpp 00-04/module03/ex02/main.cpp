/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:29:55 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:56 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "--- CONSTRUCTORS ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    FragTrap firstRobot;
    FragTrap secondRobot("FragHyperX");
    FragTrap thirdRobot(secondRobot);
    
    std::cout << "\n--- ATTACKS ---" << std::endl;
    clap.attack("Bandit");
    firstRobot.attack("invasors");
    secondRobot.attack("monsters");
    thirdRobot.attack("traitors");
    
    std::cout << "\n--- TAKING DAMAGE ---" << std::endl;
    clap.takeDamage(3);
    firstRobot.takeDamage(9);
    secondRobot.takeDamage(78);
    thirdRobot.takeDamage(25);
    
    std::cout << "\n--- REPAIR ---" << std::endl;
    clap.beRepaired(2);
    firstRobot.beRepaired(5);
    secondRobot.beRepaired(89);
    thirdRobot.beRepaired(15);
    
    std::cout << "\n--- HIGH FIVES GUYS ---" << std::endl;
    firstRobot.highFivesGuys();
    secondRobot.highFivesGuys();
    thirdRobot.highFivesGuys();
    
    std::cout << "\n--- WITHOUT HIT POINTS ---" << std::endl;
    firstRobot.takeDamage(100);
    firstRobot.attack("traitors");
    firstRobot.beRepaired(50);
    firstRobot.takeDamage(5);
    firstRobot.highFivesGuys();

    std::cout << "\n--- WITHOUT ENERGY POINTS ---" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        thirdRobot.attack("traitors");
    }
    thirdRobot.attack("traitors");
    thirdRobot.beRepaired(5);
    thirdRobot.highFivesGuys();
    
    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return (0);
}
