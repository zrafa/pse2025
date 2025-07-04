
#ifndef _SPEAKERDRV_H
#define _SPEAKERDRV_H
// Octava 4 (octava central del piano)
// Octava 2 (grave)
// Octava 2 (grave)
#define DO2 65    // C2
#define DOs2 69   // C#2
#define RE2 73    // D2
#define REs2 78   // D#2
#define MI2 82    // E2
#define FA2 87    // F2
#define FAs2 93   // F#2
#define SOL2 98   // G2
#define SOLs2 104 // G#2
#define LA2 110   // A2
#define LAs2 117  // A#2
#define SI2 123   // B2

// Octava 3
#define DO3 131   // C3
#define DOs3 139  // C#3
#define RE3 147   // D3
#define REs3 156  // D#3
#define MI3 165   // E3
#define FA3 175   // F3
#define FAs3 185  // F#3
#define SOL3 196  // G3
#define SOLs3 208 // G#3
#define LA3 220   // A3
#define LAs3 233  // A#3
#define SI3 247   // B3

// Octava 4 (central)
#define DO4 262   // C4
#define DOs4 277  // C#4
#define RE4 294   // D4
#define REs4 311  // D#4
#define MI4 330   // E4
#define FA4 349   // F4
#define FAs4 370  // F#4
#define SOL4 392  // G4
#define SOLs4 415 // G#4
#define LA4 440   // A4 (estándar 440Hz)
#define LAs4 466  // A#4
#define SI4 494   // B4

// Octava 5
#define DO5 523   // C5
#define DOs5 554  // C#5
#define RE5 587   // D5
#define REs5 622  // D#5
#define MI5 659   // E5
#define FA5 698   // F5
#define FAs5 740  // F#5
#define SOL5 784  // G5
#define SOLs5 831 // G#5
#define LA5 880   // A5
#define LAs5 932  // A#5
#define SI5 988   // B5

// Octava 6 (aguda)
#define DO6 1047   // C6
#define DOs6 1109  // C#6
#define RE6 1175   // D6
#define REs6 1245  // D#6
#define MI6 1319   // E6
#define FA6 1397   // F6
#define FAs6 1480  // F#6
#define SOL6 1568  // G6
#define SOLs6 1661 // G#6
#define LA6 1760   // A6
#define LAs6 1865  // A#6
#define SI6 1976   // B6

// Octava 7 (muy aguda)
#define DO7 2093   // C7
#define DOs7 2217  // C#7
#define RE7 2349   // D7
#define REs7 2489  // D#7
#define MI7 2637   // E7
#define FA7 2794   // F7
#define FAs7 2960  // F#7
#define SOL7 3136  // G7
#define SOLs7 3322 // G#7
#define LA7 3520   // A7
#define LAs7 3729  // A#7
#define SI7 3951   // B7

// Silencio
#define REST 0 // 0Hz (sin sonido)
void sound(volatile int frecuency, volatile int duration);
void sound_init();
#endif /* _UTILS_H */