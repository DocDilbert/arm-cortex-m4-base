file fm4.elf
target remote localhost:2331
monitor reset
load
break main
break _Reset
c
