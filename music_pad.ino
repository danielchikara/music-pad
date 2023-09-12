#include <Keypad.h>
int buzzerPin = 11;

// Frecuencias de sonido
int cNote = 261;
int c_Note = 277;
int dNote = 293;
int d_Note = 311;
int eNote = 329;
int fNote = 349;
int f_Note = 369;
int gNote = 392;
int g_Note = 415;
int aNote = 440;
int a_Note = 466;
int bNote = 493;
int cMNote = 523;

const byte row = 4;
const byte col = 4;
char kpad[row][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinRow[] = {1, 2, 4, 5};
byte pinCol[] = {7, 8, 9, 10};

int frequencies[] = {cNote, c_Note, dNote, d_Note, eNote, fNote, f_Note,gNote,g_Note,aNote,a_Note,bNote,cMNote};


Keypad customKeypad = Keypad(makeKeymap(kpad), pinRow, pinCol, row, col);

void setup() {
  // Configurar el pin del buzzer como salida
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Leer el teclado numérico personalizado
  char key = customKeypad.getKey();
  if (key) {
    for (int i = 0; i < 16; i++) {
      if (key == kpad[i / 4][i % 4]) {
        playSound(frequencies[i]);
        break;
      }
    }
  }
}

void playSound(int frequency) {
  int delayTime = 200;
  tone(buzzerPin, frequency);
  delay(delayTime);
  noTone(buzzerPin);
 
}