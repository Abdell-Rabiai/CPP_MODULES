/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:48:37 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/15 10:32:23 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{
    //A string variable initialized to "HI THIS IS BRAIN".
    std::string name = "HI THIS IS BRAIN";
    // A pointer to the string.
    std::string *stringPTR = &name;
    // A reference to the string.
    std::string &stringREF = name;
    
    std::cout << "Address of the string: " << &name << std::endl;
    std::cout << "Address of the string: " << stringPTR << std::endl;
    std::cout << "Address of the string: " << &stringREF << std::endl;

    std::cout << "the value using string: " << name << std::endl;
    std::cout << "the value using pointer: " << *stringPTR << std::endl;
    std::cout << "the value using reference: " << stringREF << std::endl;
    return 0;
}