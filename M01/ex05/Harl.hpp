/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:07 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:08 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
    private:
        void debug (void);
        void info (void);
        void warning (void);
        void error (void);
        void invalid (void);
    
    public:
        Harl(void);
        ~Harl(void);
        void complain( std::string level );
};

# endif // HARL_HPP