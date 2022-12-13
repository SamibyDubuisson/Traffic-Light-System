/*
 * TrafficLightSystem.cpp
 *
 * Created: 11/2/2022 1:17:26 AM
 * Author : Dubuisson Samuel
 */ 

#include <avr/io.h>
#include <util/delay.h>

uint8_t stopwalk = 0b00001001; //9
uint8_t stop = 0b00001000;  //8
uint8_t caution = 0b00000100; //4
uint8_t go = 0b00000010; // 2
uint8_t clear = 0b00001111;

int main(void)
{
	// setting b and d register to output 
	DDRB |= 0b00001111;
	DDRD |= 0b00001111;
    /* Replace with your application code */
    while (1) 
    {
		//Clear Everything
		PORTB &= ~(clear);
		PORTD &= ~(clear);
		//NS stopwalk, EW go
		PORTB |= (stopwalk);
		PORTD |= (go);
		_delay_ms(3000);
		//Only changing NS to stop
		PORTB &= ~(clear);
		PORTB |= (stop);
		_delay_ms(1000);
		//Only changing EW to caution
		PORTD &= ~(clear);
		PORTD |= (caution);
		_delay_ms(1000);
		//Clear Everything
		PORTB &= ~(clear);
		PORTD &= ~(clear);
		//EW stopwalk, NS go
		PORTD |= (stopwalk);
		PORTB |= (go);
		_delay_ms(3000);
		//Only changing EW to stop
		PORTD &= ~(clear);
		PORTD |= (stop);
		_delay_ms(1000);
		//Only changing NS to caution
		PORTB &= ~(clear);
		PORTB |= (caution);
		_delay_ms(1000);
    }
}

