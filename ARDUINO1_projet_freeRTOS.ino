#define BOUTON 7

void setup() {
    Serial.begin(9600);  // Communication série
    pinMode(BOUTON, INPUT_PULLUP); 
}

void loop() {
    bool boutonPresse = (digitalRead(BOUTON) == LOW); 
    Serial.println(boutonPresse ? "1" : "0"); 
    delay(200); // Petit délai pour éviter l'envoi trop rapide
}
