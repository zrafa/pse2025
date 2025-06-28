#ifndef _PIN_CONFIG_H
#define _PIN_CONFIG_H


void make_input_DDRB(unsigned char pin);
void make_input_DDRB_PUP(unsigned char pin);
void make_output_DDRB(unsigned char pin);
void write_signal_B(unsigned char pin, unsigned char signal);
int read_signal_B(unsigned char pin);

void make_input_DDRC(unsigned char pin);
void make_output_DDRC(unsigned char pin);
void write_signal_C(unsigned char pin, unsigned char signal);
int read_signal_C(unsigned char pin);

void make_input_DDRD(unsigned char pin);
void make_output_DDRD(unsigned char pin);
void write_signal_D(unsigned char pin, unsigned char signal);
int read_signal_D(unsigned char pin);

#endif /* _PIN_CONFIG_H */