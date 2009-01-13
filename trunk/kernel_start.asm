[BITS 32]
[global start]
[extern kmain] ; this is in the c file

start:
  call kmain

  cli  ; stop interrupts
  hlt ; halt the CPU

