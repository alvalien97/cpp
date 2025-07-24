/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <alvalien@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:27:10 by hzsurf            #+#    #+#             */
/*   Updated: 2025/07/08 12:56:18 by hzsurf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void to_uppercase(char c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;  
    std::cout << c;
}

int main(int argc, char **argv)
{
    int j = 0;
    int i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            to_uppercase(argv[i][j]);
            j++;
        }
        i++;
    }
    std::cout << "\n";
    return(0);
}
