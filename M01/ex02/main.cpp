/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:37 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/12 20:48:38 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{
    //A string variable initialized to "HI THIS IS BRAIN".
    std::string name = "HI THIS IS BRAIN";
    // A pointer to the string.
    std::string *ptr = &name;
    // A reference to the string.
    std::string &ref = name;
    // print the address of the string. then the adress of the pointer. then the adress of the reference.
    std::cout << "Address of the string: " << &name << std::endl;
    std::cout << "Address of the pointer: " << ptr << std::endl;
    std::cout << "Address of the reference: " << &ref << std::endl;
    // print the string, then the value pointed by the pointer, then the value pointed by the reference.
    std::cout << "String: " << name << std::endl;
    std::cout << "Pointer: " << *ptr << std::endl;
    std::cout << "Reference: " << ref << std::endl;
    return 0;
}