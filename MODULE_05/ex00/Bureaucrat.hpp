/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:32 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 13:32:53 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade; // 1 the highest, 150 the lowest
        // two user defined Exceptions are thrown when trying to create a Bureaucrat with a grade
        // is too high ==> means that the grade is below 1 and we will throw GradeTooHighException
        // or too low ==> means that the grade is above 150 and we will throw GradeTooLowException
        // the two exceptions are thrown by the constructor and caught by the main
        // we call them user defined exceptions because we define them ourselves and they are not part of the standard library
        // the two exceptions are derived from the std::exception class because we want to use the what() function of the base class
        // we are goint pt override the what() function in the derived classes to return a string that describes the error
        // this is called polymorphism based on inheritance (runtime polymorphism)
        // we use nested classes because we want to keep the exceptions within the Bureaucrat class and not expose them to the outside world
        // virtual const char * what() const throw();
        // the what() function is declared as virtual in the base class and we override it in the derived classes
        // the throw() at the end of the declaration means that the function will not throw any exceptions
        // you may ask me why we are not using the what() function of the std::exception class directly
        // the answer is that we want to return a different string for each exception
        // if we use the what() function of the std::exception class directly, we will return the same string for both exceptions
        // we can also use the what() function of the std::exception class directly and return a different string for each exception
        // but we will have to use a different function name for each exception
        // like this:
        // virtual const char * whatGradeTooHigh() const throw();
        // virtual const char * whatGradeTooLow() const throw();
        // but in this case we will have to use two different catch blocks in the main
        // like this:
        // catch (Bureaucrat::GradeTooHighException & e)
        // catch (Bureaucrat::GradeTooLowException & e)
        // but we want to use only one catch block in the main and catch both exceptions with it
        // like this:
        // catch (Bureaucrat::Exception & e) : e is a reference to the exception object thrown
        
        // you may ask me why we add throw() at the end of the declaration of the what() function
        // the answer is that we want to tell the compiler that the what() function will not throw any exceptions
        // if we don't add throw() at the end of the declaration of the what() function, the compiler will assume that the what() function will throw any exceptions
        // and it will not allow us to catch the exceptions in the main.
    
    public:
        Bureaucrat();
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & rhs);
        ~Bureaucrat();
        Bureaucrat & operator=(Bureaucrat const & rhs);
        
        // getters
        std::string const & getName() const;
        int getGrade() const;

        // setters
        void setGrade(int grade);
        
        // methods
        void incrementGrade();
        void decrementGrade();

        class BureaucratException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooHighException : public BureaucratException
        {
            public:
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public BureaucratException
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & rhs);
