/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:28 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:28 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon; // reference to a Weapon object (composition)
    
    public:
     
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
        std::string get_name() const;
};