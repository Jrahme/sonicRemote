/** This is using a samsung remote controle the model of TV and
* and remote is unknown. This is for memory bank A currently
**/
#include <IRremote.h>


#define a_dt 4105841032
#define a_fu 1752382022
#define a_fd 2209452902
#define a_fr 1595074756
#define a_fl 412973352

int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value);
    Serial.println(" ");
    switch(results.value)
   {
     //VLC pause / Play
     case a_dt: //double tap button
       {
          Serial.println("Double tap button");
          Keyboard.set_key1(KEY_SPACE);
          Keyboard.send_now();
          Keyboard.set_key1(0);
          Keyboard.send_now();
          //delay 200 as the remote sends the signal 3 times
          delay(200);
          break;
       }
     //VLC volume up
     case a_fu: //flick up
       {
          Serial.println("flick up");
          Keyboard.set_key1(KEY_UP);
          Keyboard.set_modifier(MODIFIERKEY_CTRL);
          Keyboard.send_now();
          Keyboard.set_key1(0);
          Keyboard.set_modifier(0);
          Keyboard.send_now();
          //delay 200 as the remote sends the signal 3 times
          delay(200);
          break; 
       }
       //VLC volume Down
      case a_fd: //flick down
       {
           Serial.println("flick down");
           Keyboard.set_key1(KEY_DOWN);
           Keyboard.set_modifier(MODIFIERKEY_CTRL);
           Keyboard.send_now();
           Keyboard.set_key1(0);
           Keyboard.set_modifier(0);
           Keyboard.send_now();
           //delay 200 as the remote sends the signal 3 times
          delay(200);
           break;
       }
       //VLC next
       case a_fr: //flick right
       {
           Serial.println("flick right");
           Keyboard.set_key1(KEY_N);
          Keyboard.send_now();
          Keyboard.set_key1(0);
          Keyboard.send_now();
          //delay 200 as the remote sends the signal 3 times
          delay(200);
           break;
       }
       //VLC previous
       case a_fl: //flick left
       {
            Serial.println("Flick Left");
            Keyboard.set_key1(KEY_P);
          Keyboard.send_now();
          Keyboard.set_key1(0);
          Keyboard.send_now();
          //delay 200 as the remote sends the signal 3 times
          delay(200);
            break;
       }

    }
    
    irrecv.resume();
  }
}
