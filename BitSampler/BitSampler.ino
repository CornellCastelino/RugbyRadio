  
  
  int monoS_trig = 13;  //monostable trigger

  int outputLED1 = 8;  //LED to light up if minute marker/second

  int MSF = 12;        //fake MSF signal for testing 


  int pulse1 = 11;    //check monostable putput 1
  int pulse2 = 10;    //check monstable output 2
  
  int AND1 = 9;      //check the combined result

  int result1 =  0;   //monostable 1 output 
  int result2 =  0;   //monostable 2 output 


void setup() {
 
  Serial.begin(9600);

  //assigning pin Modes
  pinMode(monoS_trig, OUTPUT);  //output to trigger monstable

  pinMode(MSF, OUTPUT);         //fake msf signal for testing

  pinMode(pulse1, INPUT);       //take in monostable 1 output 
  pinMode(pulse2, INPUT);       //take in monostable 2 output

  pinMode(AND1, INPUT);         //get the combined result


}

void loop() {


    //Minute Marker test case

    //start a timer
    unsigned long currentMillis = millis();

    //trigger the monstables
    digitalWrite(monoS_trig, HIGH);
    digitalWrite(monoS_trig, LOW);

    //make the msf signal for the first 500ms
    digitalWrite(MSF, LOW); 
    
    //make the msf signal high for the second 500ms 
    if(currentMillis == 500){            
    digitalWrite(MSF, HIGH); 
    }


    //if within 501-510ms sample monostable 1
    if(currentMillis >> 501 && currentMillis << 510){
      result1 = digitalRead(pulse1);
      return;
    }

    //if within 510-520ms sampple monostable 2
    if(currentMillis >> 510 && currentMillis << 520){
      result2 = digitalRead(pulse2);
      return;
    }

    //if all the results correspond to the logic below we are in the minute marker
    //or we have detected a second
    if(result1 == 0 && result2 == 1 && MSF == 1){

    //print to the console and light up an LED
      Serial.print("Minute Marker // Or a Second");  
      digitalWrite(outputLED1, HIGH);
    }   
}
