//         <<<KAÇAN ROBOT>>
  const int motorA1  = 6;   //  IN3 Girişi
  const int motorA2  = 10;  //  IN1 Girişi
  const int motorB1  = 9;   //  IN2 Girişi
  const int motorB2  = 5;   //  IN4 Girişi

  int durum; //Bluetooth cihazından gelecek sinyalin değişkeni  

void setup() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
    Serial.begin(9600);
}

void loop() {
    if(Serial.available() > 0){     
      durum = Serial.read();   
    }
  //İleri
  //Gelen veri 'F' ise araba ileri gider.
    if (durum == 'F') {
      analogWrite(motorA1, 255); analogWrite(motorA2, 0);
        analogWrite(motorB1, 255);      analogWrite(motorB2, 0); 
    }
                    //İleri sol
  //Gelen veri 'G' ise araba ileri sol(çapraz) gider.
    else if (durum == 'G') {
      analogWrite(motorA1,255 ); analogWrite(motorA2, 0);  
        analogWrite(motorB1, 255);    analogWrite(motorB2, 0); 
    }
                    //İleri Sağ
  //Gelen veri 'I' ise araba ileri sağ(çapraz) gider.
    else if (durum == 'I') {
        analogWrite(motorA1, 255); analogWrite(motorA2, 0); 
        analogWrite(motorB1, 255);      analogWrite(motorB2, 0); 
    }
                       //Geri
  //Gelen veri 'B' ise araba geri gider.
    else if (durum == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 255); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 255); 
    }
                      //Geri Sol
  //Gelen veri 'H' ise araba geri sol(çapraz) gider
    else if (durum == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 255); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 255); 
    }
                      //Geri Sağ
  //Gelen veri 'J' ise araba geri sağ(çapraz) gider
    else if (durum == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 255); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 255); 
    }
                        //Sol
  //Gelen veri 'L' ise araba sola gider.
    else if (durum == 'L') {
      analogWrite(motorA1, 255);   analogWrite(motorA2, 255); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
                        //Sağ
  //Gelen veri 'R' ise araba sağa gider
    else if (durum == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 255);   analogWrite(motorB2, 255);     
    }

                       //Stop
  //Gelen veri 'S' ise arabayı durdur.
    else if (durum == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }  
}
