
led-test:     formato del fichero elf32-avr


Desensamblado de la sección .text:

00000000 <__vectors>:
   0:	0c 94 34 00 	jmp	0x68	; 0x68 <__ctors_end>
   4:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
   8:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
   c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  10:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  14:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  18:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  1c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  20:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  24:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  28:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  2c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  30:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  34:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  38:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  3c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  40:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  44:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  48:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  4c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  50:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  54:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  58:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  5c:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  60:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>
  64:	0c 94 51 00 	jmp	0xa2	; 0xa2 <__bad_interrupt>

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
  7a:	e2 e3       	ldi	r30, 0x32	; 50

0000007c <.Loc.4>:
  7c:	f2 e0       	ldi	r31, 0x02	; 2

0000007e <.Loc.5>:
  7e:	02 c0       	rjmp	.+4      	; 0x84 <.L__do_copy_data_start>

00000080 <.L__do_copy_data_loop>:
  80:	05 90       	lpm	r0, Z+

00000082 <.Loc.7>:
  82:	0d 92       	st	X+, r0

00000084 <.L__do_copy_data_start>:
  84:	ac 30       	cpi	r26, 0x0C	; 12

00000086 <.Loc.9>:
  86:	b1 07       	cpc	r27, r17

00000088 <.Loc.10>:
  88:	d9 f7       	brne	.-10     	; 0x80 <.L__do_copy_data_loop>

0000008a <__do_clear_bss>:
  8a:	21 e0       	ldi	r18, 0x01	; 1

0000008c <.Loc.1>:
  8c:	ac e0       	ldi	r26, 0x0C	; 12

0000008e <.Loc.2>:
  8e:	b1 e0       	ldi	r27, 0x01	; 1

00000090 <.Loc.3>:
  90:	01 c0       	rjmp	.+2      	; 0x94 <.Loc.5>

00000092 <.Loc.4>:
  92:	1d 92       	st	X+, r1

00000094 <.Loc.5>:
  94:	ad 30       	cpi	r26, 0x0D	; 13

00000096 <.Loc.6>:
  96:	b2 07       	cpc	r27, r18

00000098 <.Loc.7>:
  98:	e1 f7       	brne	.-8      	; 0x92 <.Loc.4>

0000009a <L0^A>:
  9a:	0e 94 f8 00 	call	0x1f0	; 0x1f0 <main>
  9e:	0c 94 17 01 	jmp	0x22e	; 0x22e <_exit>

000000a2 <__bad_interrupt>:
  a2:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

000000a6 <led_init>:
  a6:	e0 91 05 01 	lds	r30, 0x0105	; 0x800105 <port_b>
  aa:	f0 91 06 01 	lds	r31, 0x0106	; 0x800106 <port_b+0x1>
  ae:	80 81       	ld	r24, Z
  b0:	90 91 00 01 	lds	r25, 0x0100	; 0x800100 <led_pin>
  b4:	89 2b       	or	r24, r25
  b6:	80 83       	st	Z, r24
  b8:	e0 91 07 01 	lds	r30, 0x0107	; 0x800107 <ddr_b>
  bc:	f0 91 08 01 	lds	r31, 0x0108	; 0x800108 <ddr_b+0x1>
  c0:	80 81       	ld	r24, Z
  c2:	90 91 00 01 	lds	r25, 0x0100	; 0x800100 <led_pin>
  c6:	89 2b       	or	r24, r25
  c8:	80 83       	st	Z, r24
  ca:	08 95       	ret

000000cc <input_init>:
  cc:	e0 91 05 01 	lds	r30, 0x0105	; 0x800105 <port_b>
  d0:	f0 91 06 01 	lds	r31, 0x0106	; 0x800106 <port_b+0x1>
  d4:	90 81       	ld	r25, Z
  d6:	80 91 01 01 	lds	r24, 0x0101	; 0x800101 <button_pin>
  da:	80 95       	com	r24
  dc:	89 23       	and	r24, r25
  de:	80 83       	st	Z, r24
  e0:	e0 91 07 01 	lds	r30, 0x0107	; 0x800107 <ddr_b>
  e4:	f0 91 08 01 	lds	r31, 0x0108	; 0x800108 <ddr_b+0x1>
  e8:	90 81       	ld	r25, Z
  ea:	80 91 01 01 	lds	r24, 0x0101	; 0x800101 <button_pin>
  ee:	80 95       	com	r24
  f0:	89 23       	and	r24, r25
  f2:	80 83       	st	Z, r24
  f4:	e0 91 03 01 	lds	r30, 0x0103	; 0x800103 <pin_b>
  f8:	f0 91 04 01 	lds	r31, 0x0104	; 0x800104 <pin_b+0x1>
  fc:	80 81       	ld	r24, Z
  fe:	90 91 01 01 	lds	r25, 0x0101	; 0x800101 <button_pin>
 102:	89 2b       	or	r24, r25
 104:	80 83       	st	Z, r24
 106:	08 95       	ret

00000108 <count>:
 108:	80 91 02 01 	lds	r24, 0x0102	; 0x800102 <state>
 10c:	81 15       	cp	r24, r1
 10e:	69 f0       	breq	.+26     	; 0x12a <.L5>
 110:	80 91 0c 01 	lds	r24, 0x010C	; 0x80010c <contador>
 114:	8c 5f       	subi	r24, 0xFC	; 252
 116:	80 93 0c 01 	sts	0x010C, r24	; 0x80010c <contador>
 11a:	80 91 0c 01 	lds	r24, 0x010C	; 0x80010c <contador>
 11e:	90 91 09 01 	lds	r25, 0x0109	; 0x800109 <limit>
 122:	98 17       	cp	r25, r24
 124:	10 f4       	brcc	.+4      	; 0x12a <.L5>
 126:	10 92 0c 01 	sts	0x010C, r1	; 0x80010c <contador>

0000012a <.L5>:
 12a:	e0 91 05 01 	lds	r30, 0x0105	; 0x800105 <port_b>
 12e:	f0 91 06 01 	lds	r31, 0x0106	; 0x800106 <port_b+0x1>
 132:	90 81       	ld	r25, Z
 134:	80 91 09 01 	lds	r24, 0x0109	; 0x800109 <limit>
 138:	80 95       	com	r24
 13a:	89 23       	and	r24, r25
 13c:	80 83       	st	Z, r24
 13e:	e0 91 05 01 	lds	r30, 0x0105	; 0x800105 <port_b>
 142:	f0 91 06 01 	lds	r31, 0x0106	; 0x800106 <port_b+0x1>
 146:	80 81       	ld	r24, Z
 148:	90 91 0c 01 	lds	r25, 0x010C	; 0x80010c <contador>
 14c:	89 2b       	or	r24, r25
 14e:	80 83       	st	Z, r24
 150:	08 95       	ret

00000152 <read>:
 152:	6e e1       	ldi	r22, 0x1E	; 30
 154:	70 e0       	ldi	r23, 0x00	; 0
 156:	80 e0       	ldi	r24, 0x00	; 0
 158:	90 e0       	ldi	r25, 0x00	; 0
 15a:	0e 94 c7 00 	call	0x18e	; 0x18e <delay_ms>
 15e:	e0 91 03 01 	lds	r30, 0x0103	; 0x800103 <pin_b>
 162:	f0 91 04 01 	lds	r31, 0x0104	; 0x800104 <pin_b+0x1>
 166:	80 81       	ld	r24, Z
 168:	86 95       	lsr	r24
 16a:	80 93 02 01 	sts	0x0102, r24	; 0x800102 <state>
 16e:	80 91 02 01 	lds	r24, 0x0102	; 0x800102 <state>
 172:	80 91 00 01 	lds	r24, 0x0100	; 0x800100 <led_pin>
 176:	80 91 00 01 	lds	r24, 0x0100	; 0x800100 <led_pin>
 17a:	e0 91 05 01 	lds	r30, 0x0105	; 0x800105 <port_b>
 17e:	f0 91 06 01 	lds	r31, 0x0106	; 0x800106 <port_b+0x1>
 182:	80 81       	ld	r24, Z
 184:	90 91 02 01 	lds	r25, 0x0102	; 0x800102 <state>
 188:	89 2b       	or	r24, r25
 18a:	80 83       	st	Z, r24
 18c:	08 95       	ret

0000018e <delay_ms>:
 18e:	0f 93       	push	r16
 190:	1f 93       	push	r17
 192:	cf 93       	push	r28
 194:	df 93       	push	r29
 196:	00 d0       	rcall	.+0      	; 0x198 <L0^A>

00000198 <L0^A>:
 198:	00 d0       	rcall	.+0      	; 0x19a <L0^A>

0000019a <L0^A>:
 19a:	cd b7       	in	r28, 0x3d	; 61
 19c:	de b7       	in	r29, 0x3e	; 62
 19e:	9b 01       	movw	r18, r22
 1a0:	ac 01       	movw	r20, r24
 1a2:	19 82       	std	Y+1, r1	; 0x01
 1a4:	1a 82       	std	Y+2, r1	; 0x02
 1a6:	1b 82       	std	Y+3, r1	; 0x03
 1a8:	1c 82       	std	Y+4, r1	; 0x04
 1aa:	a2 ec       	ldi	r26, 0xC2	; 194
 1ac:	b1 e0       	ldi	r27, 0x01	; 1
 1ae:	0e 94 fd 00 	call	0x1fa	; 0x1fa <__muluhisi3>

000001b2 <.L2>:
 1b2:	09 81       	ldd	r16, Y+1	; 0x01
 1b4:	1a 81       	ldd	r17, Y+2	; 0x02
 1b6:	2b 81       	ldd	r18, Y+3	; 0x03
 1b8:	3c 81       	ldd	r19, Y+4	; 0x04
 1ba:	06 17       	cp	r16, r22
 1bc:	17 07       	cpc	r17, r23
 1be:	28 07       	cpc	r18, r24
 1c0:	39 07       	cpc	r19, r25
 1c2:	48 f0       	brcs	.+18     	; 0x1d6 <.L3>
 1c4:	0f 90       	pop	r0
 1c6:	0f 90       	pop	r0
 1c8:	0f 90       	pop	r0
 1ca:	0f 90       	pop	r0
 1cc:	df 91       	pop	r29
 1ce:	cf 91       	pop	r28
 1d0:	1f 91       	pop	r17
 1d2:	0f 91       	pop	r16
 1d4:	08 95       	ret

000001d6 <.L3>:
 1d6:	09 81       	ldd	r16, Y+1	; 0x01
 1d8:	1a 81       	ldd	r17, Y+2	; 0x02
 1da:	2b 81       	ldd	r18, Y+3	; 0x03
 1dc:	3c 81       	ldd	r19, Y+4	; 0x04
 1de:	0f 5f       	subi	r16, 0xFF	; 255
 1e0:	1f 4f       	sbci	r17, 0xFF	; 255
 1e2:	2f 4f       	sbci	r18, 0xFF	; 255
 1e4:	3f 4f       	sbci	r19, 0xFF	; 255
 1e6:	09 83       	std	Y+1, r16	; 0x01
 1e8:	1a 83       	std	Y+2, r17	; 0x02
 1ea:	2b 83       	std	Y+3, r18	; 0x03
 1ec:	3c 83       	std	Y+4, r19	; 0x04
 1ee:	e1 cf       	rjmp	.-62     	; 0x1b2 <.L2>

000001f0 <main>:
 1f0:	0e 94 53 00 	call	0xa6	; 0xa6 <led_init>
 1f4:	0e 94 66 00 	call	0xcc	; 0xcc <input_init>

000001f8 <.L2>:
 1f8:	ff cf       	rjmp	.-2      	; 0x1f8 <.L2>

000001fa <__muluhisi3>:
 1fa:	0e 94 08 01 	call	0x210	; 0x210 <__umulhisi3>

000001fe <.Loc.1>:
 1fe:	a5 9f       	mul	r26, r21

00000200 <.Loc.2>:
 200:	90 0d       	add	r25, r0

00000202 <.Loc.3>:
 202:	b4 9f       	mul	r27, r20

00000204 <.Loc.4>:
 204:	90 0d       	add	r25, r0

00000206 <.Loc.5>:
 206:	a4 9f       	mul	r26, r20

00000208 <.Loc.6>:
 208:	80 0d       	add	r24, r0

0000020a <.Loc.7>:
 20a:	91 1d       	adc	r25, r1

0000020c <.Loc.8>:
 20c:	11 24       	eor	r1, r1

0000020e <.Loc.9>:
 20e:	08 95       	ret

00000210 <__umulhisi3>:
 210:	a2 9f       	mul	r26, r18

00000212 <.Loc.1>:
 212:	b0 01       	movw	r22, r0

00000214 <.Loc.2>:
 214:	b3 9f       	mul	r27, r19

00000216 <.Loc.3>:
 216:	c0 01       	movw	r24, r0

00000218 <.Loc.4>:
 218:	a3 9f       	mul	r26, r19

0000021a <.Loc.5>:
 21a:	70 0d       	add	r23, r0

0000021c <.Loc.6>:
 21c:	81 1d       	adc	r24, r1

0000021e <.Loc.7>:
 21e:	11 24       	eor	r1, r1

00000220 <.Loc.8>:
 220:	91 1d       	adc	r25, r1

00000222 <.Loc.9>:
 222:	b2 9f       	mul	r27, r18

00000224 <.Loc.10>:
 224:	70 0d       	add	r23, r0

00000226 <.Loc.11>:
 226:	81 1d       	adc	r24, r1

00000228 <.Loc.12>:
 228:	11 24       	eor	r1, r1

0000022a <.Loc.13>:
 22a:	91 1d       	adc	r25, r1

0000022c <.Loc.14>:
 22c:	08 95       	ret

0000022e <_exit>:
 22e:	f8 94       	cli

00000230 <__stop_program>:
 230:	ff cf       	rjmp	.-2      	; 0x230 <__stop_program>
