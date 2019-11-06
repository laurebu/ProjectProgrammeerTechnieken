#include "MK64F12.h"
void delay() {
for (long i = 0; i < 1000000; i++) {
}
}
int main(void) {
SIM->SCGC5 |= 0x400; //enable Port B Clock Gate Control
PORTC->PCR[12] = 0x100; //blue led, configured as Alternative 1 (GPIO)
GPIOB->PDDR |= (1 << 12); //setting the bit 21 of the port B as output
GPIOB->PDOR |= (1 << 12); //turn off red led
GPIOB->PDOR = (0 << 12); //turn off blue led

while (1) {
GPIOB->PDOR = (0 << 12); //turn off blue led
delay();
GPIOB->PDOR = (1 << 12); //turn on blue led
delay();
}
return 0;
}
