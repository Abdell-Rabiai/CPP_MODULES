/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:50:15 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/31 21:02:48 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &other)
{
    *this = other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
    if (this != &other) { }
    return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *data)
{
    return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
