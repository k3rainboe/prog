
;Write x86 ALP to find'
; 1.Number of Blanks spaces
; 2.Number of lines
; 3.Ocurrence of a particular characters. Accept the data from text file.




extern    far_proc     ; [ FAR PROCRDURE
                        ;   USING EXTERN DIRECTIVE ]

global    filehandle, char, buf, abuf_len

%include    "macro.asm"


section .data
    nline        db    10
    nline_len    equ    $-nline

    ano        db     10,10,10,10,"ML assignment 05 :- String Operation using Far Procedure"
            db           10,"---------------------------------------------------",10
    ano_len    equ    $-ano

    filemsg    db    10,"Enter filename for string operation    : "
    filemsg_len    equ    $-filemsg  
 
    charmsg    db    10,"Enter character to search    : "
    charmsg_len    equ    $-charmsg

    errmsg    db    10,"ERROR in opening File...",10
    errmsg_len    equ    $-errmsg

    exitmsg    db    10,10,"Exit from program...",10,10
    exitmsg_len    equ    $-exitmsg

;************************************************************
section .bss
    buf            resb    4096
    buf_len        equ    $-buf        ; buffer initial length

    filename        resb    50  
    char            resb    2  

    filehandle        resq    1
    abuf_len        resq    1        ; actual buffer length


;************************************************************
section .text
    global _start
      
_start:
        display    ano,ano_len        ;assignment no.

        display    filemsg,filemsg_len      
        accept     filename,50
        dec    rax
        mov    byte[filename + rax],0        ; blank char/null char

        display    charmsg,charmsg_len      
        accept     char,2
      
        fopen    filename            ; on succes returns handle
        cmp    rax,-1H            ; on failure returns -1
        jle    Error
        mov    [filehandle],rax  

        fread    [filehandle],buf, buf_len
        mov    [abuf_len],rax

        call    far_proc
        jmp    Exit

Error:    display    errmsg, errmsg_len

Exit:    display    exitmsg,exitmsg_len
  
    display nline,nline_len

    mov rax,60
 mov rdi,0
    syscall
    
;OUTPUT::
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ nasm -f elf64 file1.asm
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ nasm -f elf64 file2.asm
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ ld -o file1 file1.o file2.o 
;gescoe@gescoe-OptiPlex-3020:~/Desktop/44/v1$ ./file1




;ML assignment 05 :- String Operation using Far Procedure
;---------------------------------------------------

;Enter filename for string operation    : t.txt

;Enter character to search    : e

;No. of spaces are    : 0006
;No. of lines are    : 000A
;No. of character occurances are    : 0003

;Exit from program...

    
