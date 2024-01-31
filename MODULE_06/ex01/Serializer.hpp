/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:50:25 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/31 21:02:38 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>


struct Data
{
    bool alive;
};

class Serializer
{
    private:
        Serializer();

    public:
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
        ~Serializer();

        static uintptr_t serialize(Data *data);
        static Data *deserialize(uintptr_t raw);
};