/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 02:07:05 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/25 12:08:24 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

void bit_handler(int sig)
{
    static char inv;
    static int bit;

    if (sig == SIGUSR1)
        inv |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &inv, 1);
        bit = 0;
        inv = 0;
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
    ft_printf("PID is : {%d}\n", pid);
    signal(SIGUSR1, bit_handler);
    signal(SIGUSR2, bit_handler);
    while (argc == 1)
        pause ();
    return (0);
}
