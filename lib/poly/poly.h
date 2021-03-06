#ifndef POLY_H
# define POLY_H

int poly_generate(void **crypt, void **decrypt);
void poly_new_start(void *start, size_t push_off, size_t pop_off);
void generate_garb(char *pos, size_t len);

extern uint32_t ft_rand();

size_t edit_ins(unsigned char *ins);
void ploy_ins_add_end(char *data, size_t *i, char *ins, size_t ins_size);
void ploy_ins_add(char *data, size_t *i, char *ins, size_t ins_size);

#endif
