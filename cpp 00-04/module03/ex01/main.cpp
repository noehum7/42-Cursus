/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:29:35 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:36 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- CONSTRUCTORS ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap firstRobot;
    ScavTrap secondRobot("Scav3000");
    ScavTrap thirdRobot(secondRobot);
    
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
    
    std::cout << "\n--- GUARD GATE ---" << std::endl;
    firstRobot.guardGate();
    secondRobot.guardGate();
	thirdRobot.guardGate();
    
    std::cout << "\n--- WITHOUT HIT POINTS ---" << std::endl;
    firstRobot.takeDamage(100);
    firstRobot.attack("traitors");
    firstRobot.beRepaired(50);
    firstRobot.takeDamage(5);
    firstRobot.guardGate();

    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return (0);
}
