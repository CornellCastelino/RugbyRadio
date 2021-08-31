  
  int monoS_trig = 13; //monostable trigger

  int outputLED = 8;  //output LED

  int MSF = 12;       //fake msf signal for testing


  int pulse1 = 11;  //check monostable putput 1
  int pulse2 = 10;  //check monstable output 2
  
  int AND1 = 9;      //check the combined result

  int result1 =  0;   //monostable 1 output
  int result2 =  0;   //monostable 2 output


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //assigning pin Modes
  pinMode(monoS_trig, OUTPUT);

  pinMode(MSF, OUTPUT);

  pinMode(pulse1, INPUT);
  pinMode(pulse2, INPUT);

  pinMode(AND1, INPUT);


}

void loop() {

    //start a timer
    unsigned long currentMillis = millis();
    
    //trigger the monostables
    digitalWrite(monoS_trig, HIGH);
    digitalWrite(MSF, LOW); 
    

    //pulse the Bit A part of the MSF signal
    if(currentMillis == 300){            
    digitalWrite(MSF, HIGH); 
    }

    //get the monstable 1 output
    if(currentMillis >> 301 && currentMillis << 310){
      result1 = digitalRead(pulse1);
      return;
    }

    //get the moinostable 2 output
    if(currentMillis >> 310 && currentMillis << 380){
      result2 = digitalRead(pulse2);
      return;
    }


    //if the outputs correspond to the logic below we can sample bit A
    if(result1 == 0 && result2 == 1 && MSF == 1){


    //print to the console and light up an LED
      Serial.print("Bit A");
      digitalWrite(outputLED, HIGH);
    }

}
