
//inicijalizacija i deklarisanje promenljivih
const int pingPin = 12;
const int echoPin = 11;
const int piezoPin = 8;
int pitch;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// funkcija koja uključuje određen broj dioda i menja način zujanja zujalice u zavisnosti od razdaljine
void light(long cm){
  pitch = map(cm, 0, 30, 50, 4000);
  if (cm >= 24){
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  
  else if (cm >= 20){
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
    for (int i = 0; i < 5; ++i) {
      tone(piezoPin, pitch, 24);
      delay (6);
    }
  }
  
  else if (cm >= 16){
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);    
    for (int i = 0; i < 10; ++i) {
      tone(piezoPin, pitch, 20);
      delay (5);
    }
  }
  
  else if (cm >= 12){
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    for (int i = 0; i < 15; ++i) {
      tone(piezoPin, pitch, 16);
      delay (4);
    }
  }
  
   else if (cm >= 8){
    digitalWrite(7, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);    
    for (int i = 0; i < 20; ++i) {
      tone(piezoPin, pitch, 12);
      delay (3);
      }
   }
  
   else if (cm >= 5){
    digitalWrite(7, LOW); 
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);    
    for (int i = 0; i < 25; ++i) {
      tone(piezoPin, pitch, 8);
      delay (2);
  }
  }
  
   else {
    digitalWrite(7, HIGH); 
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    for (int i = 0; i < 30; ++i) {
      tone(piezoPin, pitch, 5);
      delay (1);
  }
  delay(10);
}
}
// dobijanje vrednosti sa senzora i poyivanje funkcije light
void loop() {
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 29 / 2);
  Serial.println(cm);
  light(cm);
  
}
