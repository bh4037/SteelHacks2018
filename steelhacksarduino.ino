int ax,ay,az;

float sound, light1, light2;
int a = 0;
int b = 0;
int c = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {

sound = analogRead(1);
sound = map(sound, 0, 1023, 0 , 255);
light1 = analogRead(2);
light1  = map(light1, 32, 1023, 0 , 255);
light2 = analogRead(3);
light2  = map(light2, 32, 1023, 0 , 255);



if(a == 1)
{
Serial.print((int)sound);
Serial.print(",");
Serial.print((int)light1);
Serial.print(",");
Serial.println((int)light2);
delay(10);
}

//Serial.println("preswitch");
//Serial.println(digitalRead(4));
//Serial.println(a);
if(digitalRead(4) == HIGH && a ==0)
{
  a = 1;
  //Serial.println("a = 1");
  delay(1000);
}
else if(digitalRead(4) == HIGH && a ==1)
{
  a = 0;
  //Serial.println("a = 0");
  delay(1000);
}
if(digitalRead(3) == HIGH && a ==0)
{
  a = 1;
  //Serial.println("a = 1");
  delay(1000);
}
else if(digitalRead(3) == HIGH && a ==1)
{
  a = 0;
  //Serial.println("a = 0");
  delay(1000);
}
}
