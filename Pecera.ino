#include <Servo.h>
#include <Time.h>
#include <TimeAlarms.h>
Servo motorServo;
int ang = 0;
int anguloInicio = 360; // angulo de inicio
int anguloFin = 1; // hasta un maximo de 180
int numeroDeTazones = 3; //cuantos giros d el cubilete
void setup(){
  setTime(0,0,0,9,20,11);
  motorServo.attach(9);
  pinMode(13, OUTPUT);
  Alarm.alarmRepeat(6,0,0, servirComida);
  Alarm.alarmRepeat(12,0,0, servirComida);
  //Alarm.alarmRepeat(18,0,0, servirComida);
  Alarm.timerOnce(3, servirComida);
}
void loop() {
  Alarm.delay(1000); // wait one second between clock display
}
void servirComida() {
  delay(1000);
  for(int tazon = 0; tazon < numeroDeTazones; tazon ++) {
    digitalWrite(13, HIGH);
    for(ang = anguloInicio; ang > anguloFin; ang -= 3) {
      motorServo.write(ang);
      delay(10);
    }
    digitalWrite(13, LOW);
    delay(2000);
  }
}
