/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:58 by arabiai           #+#    #+#             */
/*   Updated: 2023/11/02 12:21:50 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

/*conver the string gotten from te user into uppercase*/
int main(int argc, char **argv)
{
    std::string input;
    std::string error = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    if (argc == 1)
    {
        std::cout << error;
        return 0;
    }
    for (int i = 1; i < argc; i++)
        input.append(argv[i]);
    for (size_t i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);
    std::cout << input << "\n";
    return 0;
}
