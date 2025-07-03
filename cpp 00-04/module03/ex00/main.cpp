/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:29:22 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:23 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap defaultClap;
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("SC4V-TP");
    ClapTrap clap3(clap1);
    
    std::cout << "\n--- ASSIGNMENT OPERATOR ---" << std::endl;
    ClapTrap clap4;
    clap4 = clap2;
    
    std::cout << "\n--- NORMAL ATTACK ---" << std::endl;
    clap1.attack("Bandit");
    clap2.attack("Skag");
    
    std::cout << "\n--- TAKE DAMAGE ---" << std::endl;
    clap1.takeDamage(3);
    clap2.takeDamage(5);
    
    std::cout << "\n--- REPAIR ---" << std::endl;
    clap1.beRepaired(2);
    clap2.beRepaired(3);
    
    std::cout << "\n--- WITHOUT HIT POINTS ---" << std::endl;
    clap4.takeDamage(10);
    clap4.attack("Enemy");
    clap4.beRepaired(5);
    clap4.takeDamage(5);
    
    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return (0);
}
