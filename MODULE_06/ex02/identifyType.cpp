/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyType.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:50:15 by arabiai           #+#    #+#             */
/*   Updated: 2024/02/01 10:17:26 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "identifyType.hpp"

// Function to randomly generate an instance of A, B, or C and return it as a Base pointer

Base * generatePointerOfBase()
{
    int randomNumber = rand() % 3;
    if (randomNumber == 0){
        Base *Aptr = new A();
        return (Aptr);
    }
    else if (randomNumber == 1){
        Base *Bptr = new B();
        return (Bptr);
    }
    else {
        Base *Cptr = new C();
        return (Cptr);
    }
}

// Function to identify the actual type of the object pointed to by p (using a pointer)

void identifyTheTypeOfPointer(Base * p)
{
    // if it did cast successfully, dynamic_cast returns a success value
    // if it did not cast successfully, dynamic_cast returns a null pointer
    if (dynamic_cast<A*>(p)){
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Function to identify the actual type of the object in reference

void identifyTheTypeOfReference(Base & p)
{
    // here its a little bit different, we need to use try and catch
    // if it did cast successfully, dynamic_cast returns a success value
    // if it did not cast successfully, dynamic_cast throws an exception
    try
    {
        A &Aref = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)Aref;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &Bref = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)Bref;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &Cref = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)Cref;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}