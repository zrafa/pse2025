
utils.elf:     formato del fichero elf32-avr


Desensamblado de la sección .text:

00000000 <__vectors>:
   0:	0c 94 34 00 	jmp	0x68	; 0x68 <__ctors_end>
   4:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
   8:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
   c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  10:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  14:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  18:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  1c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  20:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  24:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  28:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  2c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  30:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  34:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  38:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  3c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  40:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  44:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  48:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  4c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  50:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  54:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  58:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  5c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  60:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
  64:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>

00000068 <__ctors_end>:
  68:	11 24       	eor	r1, r1
  6a:	1f be       	out	0x3f, r1	; 63
  6c:	cf ef       	ldi	r28, 0xFF	; 255
  6e:	d8 e0       	ldi	r29, 0x08	; 8
  70:	de bf       	out	0x3e, r29	; 62
  72:	cd bf       	out	0x3d, r28	; 61

00000074 <__do_copy_data>:
  74:	11 e0       	ldi	r17, 0x01	; 1

00000076 <.Loc.1>:
  76:	a0 e0       	ldi	r26, 0x00	; 0

00000078 <.Loc.2>:
  78:	b1 e0       	ldi	r27, 0x01	; 1

0000007a <.Loc.3>:
  7a:	e2 e6       	ldi	r30, 0x62	; 98

0000007c <.Loc.4>:
  7c:	f1 e0       	ldi	r31, 0x01	; 1

0000007e <.Loc.5>:
  7e:	02 c0       	rjmp	.+4      	; 0x84 <.L__do_copy_data_start>

00000080 <.L__do_copy_data_loop>:
  80:	05 90       	lpm	r0, Z+

00000082 <.Loc.7>:
  82:	0d 92       	st	X+, r0

00000084 <.L__do_copy_data_start>:
  84:	a6 30       	cpi	r26, 0x06	; 6

00000086 <.Loc.9>:
  86:	b1 07       	cpc	r27, r17

00000088 <.Loc.10>:
  88:	d9 f7       	brne	.-10     	; 0x80 <.L__do_copy_data_loop>

0000008a <L0^A>:
  8a:	0e 94 a4 00 	call	0x148	; 0x148 <main>
  8e:	0c 94 af 00 	jmp	0x15e	; 0x15e <_exit>

00000092 <__bad_interrupt>:
  92:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000096 <esperar>:
  96:	cf 93       	push	r28
  98:	df 93       	push	r29
  9a:	00 d0       	rcall	.+0      	; 0x9c <L0^A>

0000009c <L0^A>:
  9c:	00 d0       	rcall	.+0      	; 0x9e <L0^A>

0000009e <L0^A>:
  9e:	cd b7       	in	r28, 0x3d	; 61
  a0:	de b7       	in	r29, 0x3e	; 62
  a2:	19 82       	std	Y+1, r1	; 0x01
  a4:	1a 82       	std	Y+2, r1	; 0x02
  a6:	1b 82       	std	Y+3, r1	; 0x03
  a8:	1c 82       	std	Y+4, r1	; 0x04

000000aa <.L2>:
  aa:	89 81       	ldd	r24, Y+1	; 0x01
  ac:	9a 81       	ldd	r25, Y+2	; 0x02
  ae:	ab 81       	ldd	r26, Y+3	; 0x03
  b0:	bc 81       	ldd	r27, Y+4	; 0x04
  b2:	80 3d       	cpi	r24, 0xD0	; 208
  b4:	9d 4d       	sbci	r25, 0xDD	; 221
  b6:	a6 40       	sbci	r26, 0x06	; 6
  b8:	b1 05       	cpc	r27, r1
  ba:	38 f0       	brcs	.+14     	; 0xca <.L3>
  bc:	0f 90       	pop	r0
  be:	0f 90       	pop	r0
  c0:	0f 90       	pop	r0
  c2:	0f 90       	pop	r0
  c4:	df 91       	pop	r29
  c6:	cf 91       	pop	r28
  c8:	08 95       	ret

000000ca <.L3>:
  ca:	89 81       	ldd	r24, Y+1	; 0x01
  cc:	9a 81       	ldd	r25, Y+2	; 0x02
  ce:	ab 81       	ldd	r26, Y+3	; 0x03
  d0:	bc 81       	ldd	r27, Y+4	; 0x04
  d2:	01 96       	adiw	r24, 0x01	; 1
  d4:	a1 1d       	adc	r26, r1
  d6:	b1 1d       	adc	r27, r1
  d8:	89 83       	std	Y+1, r24	; 0x01
  da:	9a 83       	std	Y+2, r25	; 0x02
  dc:	ab 83       	std	Y+3, r26	; 0x03
  de:	bc 83       	std	Y+4, r27	; 0x04
  e0:	e4 cf       	rjmp	.-56     	; 0xaa <.L2>

000000e2 <led_init>:
  e2:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
  e6:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
  ea:	80 81       	ld	r24, Z
  ec:	8f 7d       	andi	r24, 0xDF	; 223
  ee:	80 83       	st	Z, r24
  f0:	e0 91 02 01 	lds	r30, 0x0102	; 0x800102 <ddr_b>
  f4:	f0 91 03 01 	lds	r31, 0x0103	; 0x800103 <ddr_b+0x1>
  f8:	80 81       	ld	r24, Z
  fa:	80 62       	ori	r24, 0x20	; 32
  fc:	80 83       	st	Z, r24
  fe:	08 95       	ret

00000100 <led_on>:
 100:	cf 93       	push	r28
 102:	df 93       	push	r29
 104:	0f 92       	push	r0
 106:	cd b7       	in	r28, 0x3d	; 61
 108:	de b7       	in	r29, 0x3e	; 62
 10a:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
 10e:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
 112:	80 81       	ld	r24, Z
 114:	80 62       	ori	r24, 0x20	; 32
 116:	89 83       	std	Y+1, r24	; 0x01
 118:	89 81       	ldd	r24, Y+1	; 0x01
 11a:	80 83       	st	Z, r24
 11c:	0f 90       	pop	r0
 11e:	df 91       	pop	r29
 120:	cf 91       	pop	r28
 122:	08 95       	ret

00000124 <led_off>:
 124:	cf 93       	push	r28
 126:	df 93       	push	r29
 128:	0f 92       	push	r0
 12a:	cd b7       	in	r28, 0x3d	; 61
 12c:	de b7       	in	r29, 0x3e	; 62
 12e:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
 132:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
 136:	80 81       	ld	r24, Z
 138:	8f 7d       	andi	r24, 0xDF	; 223
 13a:	89 83       	std	Y+1, r24	; 0x01
 13c:	89 81       	ldd	r24, Y+1	; 0x01
 13e:	80 83       	st	Z, r24
 140:	0f 90       	pop	r0
 142:	df 91       	pop	r29
 144:	cf 91       	pop	r28
 146:	08 95       	ret

00000148 <main>:
 148:	0e 94 71 00 	call	0xe2	; 0xe2 <led_init>

0000014c <.L2>:
 14c:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
 150:	0e 94 80 00 	call	0x100	; 0x100 <led_on>
 154:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
 158:	0e 94 92 00 	call	0x124	; 0x124 <led_off>
 15c:	f7 cf       	rjmp	.-18     	; 0x14c <.L2>

0000015e <_exit>:
 15e:	f8 94       	cli

00000160 <__stop_program>:
 160:	ff cf       	rjmp	.-2      	; 0x160 <__stop_program>
