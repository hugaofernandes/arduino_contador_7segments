//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Contador
// 
// Made by hugo medeiros fernandes
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/2134679-contador


int contar = 12;
int zerar = 13;

byte seven_seg_digits[16][7] = {{1,1,1,1,1,1,0},  // = Digito 0
                                {0,1,1,0,0,0,0},  // = Digito 1
                                {1,1,0,1,1,0,1},  // = Digito 2
                                {1,1,1,1,0,0,1},  // = Digito 3
                                {0,1,1,0,0,1,1},  // = Digito 4
                                {1,0,1,1,0,1,1},  // = Digito 5
                                {1,0,1,1,1,1,1},  // = Digito 6
                                {1,1,1,0,0,0,0},  // = Digito 7
                                {1,1,1,1,1,1,1},  // = Digito 8
                                {1,1,1,0,0,1,1},  // = Digito 9
                                {1,1,1,0,1,1,1},  // = Digito A
                                {0,0,1,1,1,1,1},  // = Digito B
                                {1,0,0,1,1,1,0},  // = Digito C
                                {0,1,1,1,1,0,1},  // = Digito D
                                {1,0,0,1,1,1,1},  // = Digito E
                                {1,0,0,0,1,1,1}}; // = Digito F

void sevenSegWrite(byte digit){
  
  byte pin = 2;
  Serial.println();
  //Serial.println(digit);
  for (byte segCount = 0; segCount < 7; segCount++){
    //Serial.print(pin);
    //Serial.print(seven_seg_digits[digit][segCount]);
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(contar, INPUT);
  pinMode(zerar, INPUT);
}

void loop() {
  
  if (digitalRead(contar) == HIGH){
    for (byte count = 0; count <= 9; count++){
      if (digitalRead(zerar) == LOW){
       delay(1000);
       sevenSegWrite(count);
      }
      else {
      	count = -1;
      }
    }
    delay(4000);
  }
}
