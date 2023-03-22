/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:30:40 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/22 02:40:47 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void message_sender(int pid, char s)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (s & (0x01 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}

int main (int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i])
        {
            message_sender(pid, argv[2][i]);
            i++;
        }
        message_sender(pid, '\n');
    }
    else
    {
        ft_putstr_fd("Wrong data format (2 arguments needed) !\n", 2);
        exit(0);
    }
    return (0);
}