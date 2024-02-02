/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyType.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:50:15 by arabiai           #+#    #+#             */
/*   Updated: 2024/02/01 16:30:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "identifyType.hpp"

// Function to randomly generate an instance of A, B, or C and return it as a Base pointer

Base * generatePointerOfBase()
{
    srand(time(NULL));
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
        std::cout << "the type of the object pointed to by p is {A}" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
        std::cout << "the type of the object pointed to by p is {B}" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "the type of the object pointed to by p is {C}" << std::endl;
    else
        std::cout << "the type of the object pointed to by p is unknown" << std::endl;
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
        std::cout << "the type of the object referenced by p is {A}" << std::endl;
        (void)Aref;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &Bref = dynamic_cast<B&>(p);
            std::cout << "the type of the object referenced by p is {B}" << std::endl;
            (void)Bref;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &Cref = dynamic_cast<C&>(p);
                std::cout << "the type of the object referenced by p is {C}" << std::endl;
                (void)Cref;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}