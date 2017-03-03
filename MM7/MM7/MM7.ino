#include <krnl.h>
// one task loops and blink
// k_sleep is used for delay - and ensure no busy waiting
// if delay(...) is used then you use cpu time 

struct k_t *p, *p2;
char stak[100];
char stak2[100];


void t1()
{
  while (1) 
  {
    Serial.print("Blinking at: "); Serial.println(millis());
    //k_sleep(500);
    digitalWrite(13,HIGH);

    //k_sleep(100);
    digitalWrite(13,LOW);

  }
} // T1

void t2()
{
  while(1)
  {
    Serial.print("Sleeping at: "); Serial.println(millis());
    k_sleep(50);
  }
} // T2

void setup()
{
  pinMode(13,OUTPUT);
  k_init(2,0,0);  // init with space for one task
  Serial.begin(250000);
  while(!Serial);

  // priority low number higher priority than higher number
  p  = k_crt_task(t1,1,stak,sizeof(stak)); // t1 as task, priority 10, 100 B stak
  p2 = k_crt_task(t2,1,stak2,sizeof(stak2)); // t1 as task, priority 10, 100 B stak
  k_start(1); // 1 milli sec tick speed
}

void loop() {
}

