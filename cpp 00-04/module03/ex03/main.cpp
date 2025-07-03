/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:30:20 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:30:21 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "--- DEFAULT DIAMONDTRAP ---" << std::endl;
    DiamondTrap diamond;

    diamond.whoAmI();
    diamond.attack("citizens");
    diamond.takeDamage(90);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.takeDamage(40);
    diamond.attack("citizens");
    
    std::cout << "\n--- SPECIFIC DIAMONDTRAP ---" << std::endl;
    DiamondTrap secondDiamond("Troll");
    
    secondDiamond.whoAmI();
    secondDiamond.attack("citizens");
    secondDiamond.takeDamage(18);
    secondDiamond.beRepaired(153);
    secondDiamond.guardGate();
    secondDiamond.highFivesGuys();
    secondDiamond.takeDamage(240);
    secondDiamond.attack("citizens");
    
    std::cout << "\n--- COPY DIAMONDTRAP ---" << std::endl;
    DiamondTrap thirdDiamond(secondDiamond);
    
    thirdDiamond.whoAmI();
    thirdDiamond.attack("citizens");
    
    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return 0;
}
