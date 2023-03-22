/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:07:05 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/22 02:40:34 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void bit_handler(int sig)
{
    static char i;
    static int bit;

    if (sig == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &i, 1);
        bit = 0;
        i = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    (void)argv;
    i = 0;
    if (argc != 1)
    {
        ft_putstr_fd("Wrong data format (No arguments needed) !\n", 2);
        exit(0);
    }
    pid = getpid();
    printf("PID is : {%d}\n", pid);
    signal(SIGUSR1, bit_handler);
    signal(SIGUSR2, bit_handler);
    while (argc == 1)
        pause ();
    return (0);
}
