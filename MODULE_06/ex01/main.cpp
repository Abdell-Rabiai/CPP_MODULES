/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:18:42 by arabiai           #+#    #+#             */
/*   Updated: 2024/02/01 16:26:02 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->alive = true;

    uintptr_t mySerializedInteger = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(mySerializedInteger);

    std::cout << "data->alive: " << std::boolalpha << data->alive << std::endl;
    std::cout << "data2->alive: " << std::boolalpha << data2->alive << std::endl;

    delete data;
    return (0);
}