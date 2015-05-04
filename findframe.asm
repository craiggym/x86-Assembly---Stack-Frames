global findframe
extern printf
extern scanf
extern c1
extern c2
extern c3
extern c4
extern c5

;=== including the debug file and my macro file (called utilities.inc) ===
%include "utilities.inc"			;Author's macro file
%include "debug.inc"				;Professors debugger file
;=========================================================================

segment .data

;--FORMATS--
hex: db "0x%016lx", 0

segment .bss

segment .text
;================================= PROGRAM START =================================================================================================================
findframe:

;===== Save the General Purpose Registers ==================================================================================
  push rbp
  mov        r9, rsp                                       		;Backing up the base pointer into register r9
  mov        rbp, rsp                                       		;We do this in order to be 100% compatible with C and C++.
  push       rbx                                             		;Back up rbx
  push       rcx                                             		;Back up rcx
  push       rdx                                             		;Back up rdx
  push       rsi                                            		;Back up rsi
  push       rdi                                            		;Back up rdi
  push       r8                                             		;Back up r8
  push       r9                                             		;Back up r9
  push       r10                                            		;Back up r10
  push       r11                                            		;Back up r11
  push       r12                                           		;Back up r12
  push       r13                                           		;Back up r13
  push       r14                                            		;Back up r14
  push       r15                                          		;Back up r15
  pushf                                                   		;Back up rflags
;---------------------------------------------------------------------------------------------------------------------------

;===== Back up the state components ===============================================================================
saveSC 4							;Backing up the State Components
;------------------------------------------------------------------------------------------------------------------

;mov r9, rbp					      	;Securing the rbp value
;mov rbp, rsp						;The starting address for dumpstack must be in rsp: This ruins the nice link list.
dumpstack 0, 0, 22
showregisters 15
;========================================================= Loop for displaying rbp ===============================================================================

;topofloop:

mov rax, 0
mov rdi, hex
mov rsi, r9
call printf


;===== Restore the General Purpose Registers =============================================================================
  popf                                                       		;Restore rflags
  pop        r15                                              		;Restore r15
  pop        r14                                              		;Restore r14
  pop        r13                                              		;Restore r13
  pop        r12                                              		;Restore r12
  pop        r11                                              		;Restore r11
  pop        r10                                              		;Restore r10
  pop        r9                                               		;Restore r9
  pop        r8                                               		;Restore r8
  pop        rdi                                              		;Restore rdi
  pop        rsi                                              		;Restore rsi
  pop        rdx                                              		;Restore rdx
  pop        rcx                                              		;Restore rcx
  pop        rbx                                              		;Restore rbx
  pop        rbp                                              		;Restore rbp
;-------------------------------------------------------------------------------------------------------------------------

ret						;Return to the caller
