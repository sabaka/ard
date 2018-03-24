//www.elegoo.com
//2016.12.08

int buzzer = 12;
void setup()
{
 pinMode(buzzer,OUTPUT);
}
void loop()
{
 unsigned char i;
 while(1)
 {
   //output an frequency
   for(i=0;i<468;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(468);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(468);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(0);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
  }
} 
