int Capteur= 2; 
void setup()
{
  pinMode(Capteur,INPUT); 
  //définir la pin 2 comme une entré Serial.begin(9600); }
  void loop() 
  {
    if(digitalRead(Capteur)==HIGH)
    { Serial.write(1); } 
      else{Serial.write(0); } 
        delay(200); }
    }
  }
}
