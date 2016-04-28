#include <Bounce2.h>

const byte pinPedale = A0;
const byte pinManette = A1;
const byte pinCommande = 3;
const byte pinSourceCommande = 2;
const byte pinTemoin = 4;

byte pinConsigne = pinPedale;

Bounce poussoirSourceCommande;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Proto sortie analogique");
  poussoirSourceCommande.attach(pinSourceCommande, INPUT_PULLUP);
  pinMode(pinTemoin, OUTPUT);
}

bool mode = false;

void loop() {
  poussoirSourceCommande.update();

  if (poussoirSourceCommande.fell()) mode = !mode;

  digitalWrite(pinTemoin, mode ? HIGH : LOW);
  pinConsigne = mode ? pinManette : pinPedale;
  
  word entree = analogRead(pinConsigne);
  Serial.println(entree);
  analogWrite(pinCommande, entree / 4);
}
