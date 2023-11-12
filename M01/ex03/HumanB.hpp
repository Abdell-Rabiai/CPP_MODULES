/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:24 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:24 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon; // pointer to a Weapon object (composition)
    
    public:
     
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void set_weapon(Weapon *weapon);
        std::string get_name() const;
};