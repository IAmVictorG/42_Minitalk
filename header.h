#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

#define WAITING 60

typedef struct nbpow
{
    int nb;
    int power;
}   t_nbpow;
