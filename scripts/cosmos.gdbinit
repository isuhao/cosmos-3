target remote :2331

set output-radix 16

monitor reset
#ddr_init
load
monitor reset halt

break main