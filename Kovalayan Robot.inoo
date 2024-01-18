#include<NewPing.h>           
#include<Servo.h>             
#include<AFMotor.h>           

#define SAG A2                // Sağ IR sensör A2 analog pinine bağlı.
#define SOL A3                // Sol IR sensör A3 analog pinine bağlı.
#define TRIG_PIN A1           // Trig pini A1 analog pinine bağlı.
#define ECHO_PIN A0           // Echo pin  A0 analog pinine bağlı.
#define MAX_MESAFE 200        // Max mesafe .

int mesafe = 0;         //Ultrasonik sensörün ölçtüğü mesafe için değişken.
int mz80_sagdeger = 0;  //1. mz80 sensörünün değerini tutacak değişken.
int mz80_soldeger = 0;  //2. mz80 sensörünün değerini tutacak değişken.
  
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_MESAFE);  

AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

Servo servo;     //Servo motoru tanımlıyoruz.
int   pos=0;     //Servo motorun konumunun değerini tutan kod satırı.

void setup() 
{   
   Serial.begin(9600); 
   myservo.attach(10); // servo 10. dijital pine bağlı.
{
for(pos = 90; pos <= 180; pos += 1){    // 90 dereceden 180 dereceye döner.
  myservo.write(pos);                  
  delay(15);                            
  } 
for(pos = 180; pos >= 0; pos-= 1) {     // 180 dereceden 0 dereceye döner.
  myservo.write(pos);                   
  delay(15);                            
  }
for(pos = 0; pos<=90; pos += 1) {       // 0 dereceden 90 dereceye döner.
  myservo.write(pos);                   
  delay(15);                            
  }
}
   pinMode(SAG, INPUT);  
   pinMode(SOL, INPUT);  
}

void loop() {     

distance = sonar.ping_cm();                     //Gecikme gönderip mesafeyi cm olarak alıcaz.
Serial.print("MESAFE");                   
Serial.println(mesafe);                         // mesafe değerini ekrana yazdır.

mz80_sagdeger = digitalRead(SAG);               // Sağdaki mz80'nin dijital değerini oku.
mz80_soldeger = digitalRead(SOL);               // Soldaki mz80'nin dijital değerini oku.
 
Serial.print("SAĞ");                      
Serial.println(mz80_sagdeger);                      //Sağ mz80'nin dijital değerini serial monitöre yazdır.
Serial.print("SOL");                       
Serial.println(mz80_soldeger);                      //Sol mz80'nin dijital değerini serial monitöre yazdır.

if((mesafe > 1) && (mesafe < 50)){            //HC-SR04 sensörünün değerinin 1 ile 15 arasında ise aşağıdaki kod satırını çalıştır.
                                              //Koşul doğru ise aşağıdaki kod satırları çalışır.
                                              //Eğer araç yavaş veya hızlı hareket ediyorsa 130 yazan değeri 0-255 aralığında arttırıp veya azaltabilirsiniz.
  //İleri                                           
  Motor1.setSpeed(130);  //1. Motorun hızını PWM aralığında 130 değerinde bir voltaj yolla.
  Motor1.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  Motor2.setSpeed(130);  //2. Motorun hızını PWM aralığında 130 değerinde bir voltaj yolla.
  Motor2.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  Motor3.setSpeed(130);  //3. Motorun hızını PWM aralığında 130 değerinde bir voltaj yolla.
  Motor3.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  Motor4.setSpeed(130);  //4. Motorun hızını PWM aralığında 130 değerinde bir voltaj yolla.
  Motor4.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  
}else if((mz80_sagdeger==0) && (mz80_soldeger==1)) {   ///Koşul doğru ise aşağıdaki kod satırları çalışır.
  
  //Sol Tarafa dön                                          
  Motor1.setSpeed(150);  //1. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor1.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  Motor2.setSpeed(150);  //2. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor2.run(FORWARD);   ///Motoru ileri tarafa yönlendir.
  Motor3.setSpeed(150);  //3. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor3.run(BACKWARD);  //Motoru geri tarafa yönlendir.
  Motor4.setSpeed(150);  //4. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor4.run(BACKWARD);  //Motoru geri tarafa yönlendir.
  
}else if((mz80_sagdeger==1)&&(mz80_soldeger==0)) {     ///Koşul doğru ise aşağıdaki kod satırları çalışır.
  
  //Sağ Tarafa dön
  Motor1.setSpeed(150);  //1. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor1.run(BACKWARD);  //Motoru geri tarafa yönlendir.
  Motor2.setSpeed(150);  //1. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor2.run(BACKWARD);  //Motoru geri tarafa yönlendir.
  Motor3.setSpeed(150);  //1. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor3.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  Motor4.setSpeed(150);  //1. Motorun hızını PWM aralığında 150 değerinde bir voltaj yolla.
  Motor4.run(FORWARD);   //Motoru ileri tarafa yönlendir.
  
}else if(mesafe > 200) {                          ///Koşul doğru ise aşağıdaki kod satırları çalışır.

  //Dur
  Motor1.setSpeed(0);    //1. Motorun hızını PWM aralığında 0 değerinde bir voltaj yolla.
  Motor1.run(RELEASE);   //Motoru durdur.
  Motor2.setSpeed(0);    //2. Motorun hızını PWM aralığında 0 değerinde bir voltaj yolla.
  Motor2.run(RELEASE);   //Motoru durdur.
  Motor3.setSpeed(0);    //3. Motorun hızını PWM aralığında 0 değerinde bir voltaj yolla.
  Motor3.run(RELEASE);   //Motoru durdur.
  Motor4.setSpeed(0);    //4. Motorun hızını PWM aralığında 0 değerinde bir voltaj yolla.
  Motor4.run(RELEASE);   //Motoru durdur.
}
}
