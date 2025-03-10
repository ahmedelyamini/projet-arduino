#define potpin A0
#define BP 3 // Utiliser une pin qui supporte attachInterrupt (pins 2 ou 3 sur la plupart des cartes Arduino)

volatile bool miseAJour = false;
volatile int choix = 0;
int seconde = 0;
int minute = 0;
int heure = 0;

void setup() {
  pinMode(potpin, INPUT);
  pinMode(BP, INPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(BP), changerTemps, RISING);
}

void loop() {
  if (miseAJour) {
    int valeurPot = analogRead(potpin); 
    choix = map(valeurPot, 0, 1023, 0, 2); 

    switch (choix) {
      case 0:
        heure = (heure + 1) % 24;
        break;
      case 1:
        minute = (minute + 1) % 60;
        break;
      case 2:
        seconde = (seconde + 1) % 60;
        break;
    }

    Serial.print("Heure mise à jour : ");
    Serial.print(heure);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(seconde);

    miseAJour = false; // Réinitialiser le drapeau
  }

  delay(1000);
  seconde++;

  if (seconde == 60) {
    seconde = 0;
    minute++;
  }
  if (minute == 60) {
    minute = 0;
    heure++;
  }
  if (heure == 24) {
    heure = 0;
  }

  Serial.print("Temps actuel : ");
  Serial.print(heure);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(seconde);
}

void changerTemps() {
  miseAJour = true;
}