
;Write  X86/64  ALP  to  perform  multiplication  of  two  8-bit  hexadecimal  numbers. 
;Use successive addition and add and shift method. 


%macro read 2
	mov rdx,%2
	mov rsi,%1
	mov rdi,0
	mov rax,0
	syscall
%endmacro

%macro write 2
	mov rdx,%2
	mov rsi,%1
	mov rdi,1
	mov rax,1
	syscall
%endmacro

%macro exit 0
mov rax,60
syscall
%endmacro	

section .data	
	
		msg db 'Enter 1st Number :'
		len equ $-msg
		
		msg1 db 'Enter 2nd number :'
		len1 equ $-msg1
		
		msg2 db 'The muliplication using successive addition is :',10,13
		len2 equ $-msg2
		
		msg3 db '',10,13
		len3 equ $-msg3



section .bss

	n1 resb 14
	n2 resb 14
	m1 resb 14
	m2 resb 14

	 
section .txt
global _start
	_start:
	
	 write msg,len
 	 read n1,3
 	 mov rsi,n1
 	 call accept
 	 mov [m1],bl
 	 
 	write msg1,len1
 	 read n2,3
 	 mov rsi,n2
 	 call accept
 	 mov [m2],bl
 	 
 	 mov bl,00
 	 
 	 mov al,[m1]
 	 mov cl,[m2]
 	 
 	 
      l5:add bl,al
 	 dec cl
 	 jnz l5
 	 
 	write msg2,len2
 	 call display
 	 
exit
         
accept: 	 
	mov bl,00
	mov rcx,02
	
     l1: rol bl,4	
        mov al,[esi]
        cmp al,39h
        
        jbe l2
        sub al,07h
     
     l2:sub al,30h
        add bl,al
        inc rsi
        dec rcx
        jnz l1
ret

display: 	 
	mov rcx,04
	mov rdi,n2
	
	
     l3: rol bx,04	
        mov al,bl
        and al,0Fh
        cmp al,09h
        jbe l4
        add al,07h
     l4: add al,30h
        mov [rdi],al
        inc rdi
        dec rcx
        jnz l3
        
         write n2,4
 	write msg3,len3
        
ret


;OUTPUT::
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ nasm -f elf64 pr42.nasm
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ ld -o pr42 pr42.o 
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ ./pr42
;Enter 1st Number :06
;Enter 2nd number :02
;The muliplication using successive addition is :
;000C
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ 
