#define LEDB 4
#define LEDV 3
#define LEDR 2
#define tempin A0
int valeur=0;
void setup()
{
  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valeur=analogRead(tempin);
  valeur=map(valeur,0,1023,0,5000);
  valeur=(valeur-500)/10.0;
  Serial.print("temp: ");
  Serial.println(valeur);
  switch(valeur){
  case 18:
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDV,LOW);
    digitalWrite(LEDR,LOW);
    break;
  case 25:
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDV,HIGH);
    digitalWrite(LEDR,LOW);
    break;
  case 32:
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDV,LOW);
    digitalWrite(LEDR,HIGH);
    break;
  default: 
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDV,LOW);
    digitalWrite(LEDR,LOW);
  }
}  
   