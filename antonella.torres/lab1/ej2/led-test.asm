
led-test:     formato del fichero elf32-avr


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
  76:	a0 e0       	ldi	r26, 0x00	; 0
  78:	b1 e0       	ldi	r27, 0x01	; 1
  7a:	ec e2       	ldi	r30, 0x2C	; 44
  7c:	f1 e0       	ldi	r31, 0x01	; 1
  7e:	02 c0       	rjmp	.+4      	; 0x84 <__do_copy_data+0x10>
  80:	05 90       	lpm	r0, Z+
  82:	0d 92       	st	X+, r0
  84:	a6 30       	cpi	r26, 0x06	; 6
  86:	b1 07       	cpc	r27, r17
  88:	d9 f7       	brne	.-10     	; 0x80 <__do_copy_data+0xc>
  8a:	0e 94 89 00 	call	0x112	; 0x112 <main>
  8e:	0c 94 94 00 	jmp	0x128	; 0x128 <_exit>

00000092 <__bad_interrupt>:
  92:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000096 <esperar>:
  96:	cf 93       	push	r28
  98:	df 93       	push	r29
  9a:	00 d0       	rcall	.+0      	; 0x9c <esperar+0x6>
  9c:	00 d0       	rcall	.+0      	; 0x9e <esperar+0x8>
  9e:	cd b7       	in	r28, 0x3d	; 61
  a0:	de b7       	in	r29, 0x3e	; 62
  a2:	19 82       	std	Y+1, r1	; 0x01
  a4:	1a 82       	std	Y+2, r1	; 0x02
  a6:	1b 82       	std	Y+3, r1	; 0x03
  a8:	1c 82       	std	Y+4, r1	; 0x04
  aa:	89 81       	ldd	r24, Y+1	; 0x01
  ac:	9a 81       	ldd	r25, Y+2	; 0x02
  ae:	ab 81       	ldd	r26, Y+3	; 0x03
  b0:	bc 81       	ldd	r27, Y+4	; 0x04
  b2:	80 3d       	cpi	r24, 0xD0	; 208
  b4:	9d 4d       	sbci	r25, 0xDD	; 221
  b6:	a6 40       	sbci	r26, 0x06	; 6
  b8:	b1 05       	cpc	r27, r1
  ba:	60 f4       	brcc	.+24     	; 0xd4 <esperar+0x3e>
  bc:	89 81       	ldd	r24, Y+1	; 0x01
  be:	9a 81       	ldd	r25, Y+2	; 0x02
  c0:	ab 81       	ldd	r26, Y+3	; 0x03
  c2:	bc 81       	ldd	r27, Y+4	; 0x04
  c4:	01 96       	adiw	r24, 0x01	; 1
  c6:	a1 1d       	adc	r26, r1
  c8:	b1 1d       	adc	r27, r1
  ca:	89 83       	std	Y+1, r24	; 0x01
  cc:	9a 83       	std	Y+2, r25	; 0x02
  ce:	ab 83       	std	Y+3, r26	; 0x03
  d0:	bc 83       	std	Y+4, r27	; 0x04
  d2:	eb cf       	rjmp	.-42     	; 0xaa <esperar+0x14>
  d4:	0f 90       	pop	r0
  d6:	0f 90       	pop	r0
  d8:	0f 90       	pop	r0
  da:	0f 90       	pop	r0
  dc:	df 91       	pop	r29
  de:	cf 91       	pop	r28
  e0:	08 95       	ret

000000e2 <led_init>:
  e2:	e0 91 02 01 	lds	r30, 0x0102	; 0x800102 <ddr_b>
  e6:	f0 91 03 01 	lds	r31, 0x0103	; 0x800103 <ddr_b+0x1>
  ea:	80 81       	ld	r24, Z
  ec:	80 62       	ori	r24, 0x20	; 32
  ee:	80 83       	st	Z, r24
  f0:	08 95       	ret

000000f2 <led_on>:
  f2:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
  f6:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
  fa:	80 81       	ld	r24, Z
  fc:	80 62       	ori	r24, 0x20	; 32
  fe:	80 83       	st	Z, r24
 100:	08 95       	ret

00000102 <led_off>:
 102:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
 106:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
 10a:	80 81       	ld	r24, Z
 10c:	8f 7d       	andi	r24, 0xDF	; 223
 10e:	80 83       	st	Z, r24
 110:	08 95       	ret

00000112 <main>:
 112:	0e 94 71 00 	call	0xe2	; 0xe2 <led_init>
 116:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
 11a:	0e 94 79 00 	call	0xf2	; 0xf2 <led_on>
 11e:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
 122:	0e 94 81 00 	call	0x102	; 0x102 <led_off>
 126:	f7 cf       	rjmp	.-18     	; 0x116 <main+0x4>

00000128 <_exit>:
 128:	f8 94       	cli

0000012a <__stop_program>:
 12a:	ff cf       	rjmp	.-2      	; 0x12a <__stop_program>
