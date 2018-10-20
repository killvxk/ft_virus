#ifndef INFECT_H
# define INFECT_H

# include <stddef.h>
# include <stdint.h>
# include "crypto.h"
# include "elf64.h"
# include <elf.h>
# include <stdio.h>


extern char key[16];

//======================= WOODY ==============================

int encrypt_text_section(char *s, size_t n);

//=============================================================

int check_already_packed(char *s, size_t n, size_t virus_len);

typedef struct s_opt {
	char do_recur;
	char do_remote;
	char do_dns_remote;
	char print_msg;
} Opt;

int infect_dir(char *dirname, char *b, size_t bn, size_t crypt_off, size_t crypt_len, struct s_opt opt);
int infect(char *fname, char *outname, char *b, size_t bn, size_t crypt_off, size_t crypt_len, struct s_opt opt);

#endif