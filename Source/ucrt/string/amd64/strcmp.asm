        page    ,132
        title   strcmp.asm - compare two strings
;***
;strcmp.asm - routine to compare two strings (for equal, less, or greater)
;
;       Copyright (c) Microsoft Corporation. All rights reserved.
;
;Purpose:
;       STRCMP compares two strings and returns an integer
;       to indicate whether the first is less than the second, the two are
;       equal, or whether the first is greater than the second, respectively.
;       Comparison is done byte by byte on an UNSIGNED basis, which is to
;       say that Null (0) is less than any other character (1-255).
;
;*******************************************************************************
include ksamd64.inc
        subttl  "strcmp"
;***
;strcmp - compare two strings, returning less than, equal to, or greater than
;
;Purpose:
;       Compares two string, determining their ordinal order.  Unsigned
;       comparison is used.
;
;       Algorithm:
;          int strcmp ( src , dst )
;                  unsigned char *src;
;                  unsigned char *dst;
;          {
;                  int ret = 0 ;
;
;                  while( ! (ret = *src - *dst) && *dst)
;                          ++src, ++dst;
;
;                  if ( ret < 0 )
;                          ret = -1 ;
;                  else if ( ret > 0 )
;                          ret = 1 ;
;
;                  return( ret );
;          }
;
;Entry:
;       const char * src - string for left-hand side of comparison
;       const char * dst - string for right-hand side of comparison
;
;Exit:
;       AX < 0, 0, or >0, indicating whether the first string is
;       Less than, Equal to, or Greater than the second string.
;
;Uses:
;       CX, DX
;
;Exceptions:
;
;*******************************************************************************

CHAR_TYPE EQU BYTE
CHAR_PTR EQU BYTE PTR
CHAR_SIZE = sizeof CHAR_TYPE

BLK_TYPE EQU QWORD
BLK_PTR EQU QWORD PTR
BLK_SIZE = sizeof BLK_TYPE

;PAGE_SIZE = 1000h
PAGE_MASK = PAGE_SIZE - 1       ; mask for offset in MM page
PAGE_SAFE_BLK = PAGE_SIZE - BLK_SIZE ; maximum offset for safe block compare

ifdef _CRT_FFS_BUILD
fname      TEXTEQU <strcmp_ffs>
else
fname      TEXTEQU <strcmp>
endif

LEAF_ENTRY_ARG2 fname, _TEXT$21, str1:ptr byte, str2:ptr byte

    OPTION PROLOGUE:NONE, EPILOGUE:NONE

; rcx = src
; rdx = dst

    sub     rdx, rcx
    test    cl, (BLK_SIZE - 1)
    jz      qword_loop_enter

comp_head_loop_begin:
    movzx   eax, CHAR_PTR[rcx]
    cmp     al, CHAR_PTR[rdx+rcx]
    jnz     return_not_equal

    inc     rcx

    test    al, al
    jz      return_equal

    test    cl, (BLK_SIZE - 1)
    jnz     comp_head_loop_begin

qword_loop_enter:

    mov     r11, 8080808080808080h
    mov     r10, 0fefefefefefefeffh

qword_loop_begin:
    lea     eax, [edx+ecx]
    and     eax, PAGE_MASK
    cmp     eax, PAGE_SAFE_BLK
    ja      comp_head_loop_begin

    mov     rax, BLK_PTR[rcx]
    cmp     rax, BLK_PTR[rdx+rcx]

; mismatched string (or maybe null + garbage after)
    jne     comp_head_loop_begin

; look for null terminator
    lea     r9, [rax + r10]
    not     rax
    add     rcx, BLK_SIZE
    and     rax, r9

    test    rax, r11       ; r11=8080808080808080h
    jz      qword_loop_begin

return_equal:
    xor     eax, eax ; gets all 64 bits
    ret

return_not_equal:
    sbb     rax, rax ; AX=-1, CY=1 AX=0, CY=0
    or      rax, 1
    ret

LEAF_END fname, _TEXT$21
end
