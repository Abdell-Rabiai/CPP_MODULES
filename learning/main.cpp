/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:58 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/07 18:30:36 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

class Log {
    private:
        Log() = delete;
    public:
        static void write(std::string message) {
            std::cout << message << std::endl;
        } 
};

class point {
    public:
        int x;
        int y;
        
        point() {
            this->x = 0;
            this->y = 0;
        }
        
        point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        
        void print() {
            std::cout << x << ", " << y << std::endl;
        }
};

int main()
{
    // point p;
    // // p.print();
    // std::cout << p.x << ", " << p.y << std::endl;
    // p.print();
    // std::cin.get();
    // log::write("Hello World!");
    Log::write("Hello World!");
    Log l;
    l.write("Hello World!");
    // l.write("Hello World!");
    return (0);
}
