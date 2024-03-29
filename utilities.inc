;========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3=========4=========5=========6=========7**
;System Title:  utilities, a macro file for X86 assembly programs
;Author: Craig Marroquin
;Email: CraigMarroquin@yahoo.com
;Status: Released for self-convenience and general use.
;This module file name: utilities.inc
;This module purpose: This file is an "include" file.  It allows the user to use the shortcuts defined in this file.
;Language: X86
;Syntax: Intel
;Date of last update: 2014-Apr-23
;Source file structure: width is 140 characters; detailed comments begin in column 61.
;Printing: best results are obtained using landscape orientation with 9 point (or less) monospaced font.
;
;Targeted user group: Assembly programmers enrolled in programming courses like CPSC240.
;
;Requirements: Include this file in the assembly program and make sure to link with when compiling. 
;=======================================================================================================================================================================

segment .data

segment .bss

align 64
savelocaldata resb 832

;================================= Macro: saveGPRs ================================================================================================================
%macro saveGPRs 0                                    ;Zero indicates that no data will be passed to this macro when it is called.
;Description: Backs up all the GPR values so that the program can use all the registers as if it was scratch space

  push       rbp                                              		;Save a copy of the stack base pointer
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
%endmacro-------------------------------------------------------------------------------------------------------------------------

;================================= Macro: restoreGPRs===============================================================================================================
%macro restoreGPRs 0                                    ;Zero indicated that no data will be passed to this macro when it is called.
;Description: Restores the GPR values taken from the start of the program and returns to the caller 

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
%endmacro-------------------------------------------------------------------------------------------------------------------------

;================================= Macro: saveSC ================================================================================================================
%macro saveSC 1                                    			;1 is the number of parameters being passed when calling this macro
;Description: Backs up the state components(SC) specified by the integer passed. 7 is the assumed integer being passed with will backup all the state components:
;FPU, SSE, and AVX.

    push rdx                                                ;Backup rdx as it will be used in this macro
    mov rdx, 0                                              ;rdx should be 0 for the backup to work
    mov rax, %1                                             ;Valid integers passed are 7, 2, and 1 as those define the three state components mentioned above
    pop rdx                                                 ;Restore rdx after the macro is done using it
    xsave [savelocaldata]				    ;Back up the state components
%endmacro-------------------------------------------------------------------------------------------------------------------------

;================================= Macro: restoreSC ================================================================================================================
%macro restoreSC 1                                    			;1 is the number of parameters being passed when calling this macro
;Description: Backs up the state components(SC) specified by the integer passed. 7 is the assumed integer being passed with will backup all the state components:
;FPU, SSE, and AVX.

    push rdx                                                ;Backup rdx as it will be used in this macro
    mov rdx, 0                                              ;rdx should be 0 for the backup to work
    mov rax, %1                                             ;Valid integers passed are 7, 2, and 1 as those define the three state components mentioned above
    pop rdx                                                 ;Restore rdx after the macro is done using it
    xrstor [savelocaldata]				    ;Restore the state components
%endmacro-------------------------------------------------------------------------------------------------------------------------

;================================= Macro: clockTime ==============================================================================================================
%macro clockTime 1							;1 is the number of parameters being passed when calling this macro
;Description: Takes the current time from the computer using the Time Stamp Counter. Result is in tics and will be in rdx:rax as it's 128 bits of data

  mov rax, 0								;clear the rax register as rdtsc uses this register
  mov rdx, 0								;clear the rdx register as rdtsc uses this register
  rdtsc									;Places the time in tics in rdx:rax

  shl rdx, 32								;Shift the lower half of rdx into the higher half so that the higher half of rax and 
									;be combined with it
  or rdx, rax								;Combine the higher half of rax into the lower half of rdx
  mov %1,rdx								;Preserve the information by placing it into the register that was passed
%endmacro-------------------------------------------------------------------------------------------------------------------------


