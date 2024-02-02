/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:06:35 by arabiai           #+#    #+#             */
/*   Updated: 2024/02/01 16:26:34 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

class Base
{
    public:
        virtual ~Base() {};
};

class A : public Base {
    
};

class B : public Base {
    
};

class C : public Base {
    
};

Base * generatePointerOfBase();

void identifyTheTypeOfPointer(Base * p);

void identifyTheTypeOfReference(Base & p);