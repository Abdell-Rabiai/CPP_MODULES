/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:36:28 by arabiai           #+#    #+#             */
/*   Updated: 2024/01/30 13:27:00 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main()
{
    try
    {
        Intern inter;
        Bureaucrat tabi3a("tabi3a", 30);
        AForm* f;
        // f = someRandomIntern.makeForm("sss request", "tabi3a");
        f = inter.makeForm("presidential request", "tabi3a");
        std::cout << *f << std::endl;
        f->execute(tabi3a);
        delete f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}