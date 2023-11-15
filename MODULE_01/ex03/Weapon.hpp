/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:13 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/14 19:21:19 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>


class Weapon
{
    private:
        std::string	type;
          
    public:
        Weapon(); // default constructor
        Weapon(std::string type); // parameterized constructor
        ~Weapon(); // destructor
        const std::string &get_type();
        void set_type(std::string type);    
};

#endif // WEAPON_HPP