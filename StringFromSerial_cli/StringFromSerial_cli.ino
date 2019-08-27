String readString;
int Dir = 0;
int Spd = 20;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Serial String Input");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.print("input: ");
    Serial.println(readString);  //so you can see the captured string
    //for strings formatted "get S" or "set S 100"    
    int n = readString.substring(5).toInt();  //convert readString into a number
    
    if(readString.substring(0,3) == "get"){
      if(readString.substring(4,5) == "S"){
        Serial.print("Get Speed: ");
        Serial.println(Spd);
      }
      else if(readString.substring(4,5) == "D"){
        Serial.print("Get Direction: ");
        Serial.println(Dir);
      }
      else{
        Serial.println("Unknown Get command");
      }
    }
    else if(readString.substring(0,3) == "set"){
      if(readString.substring(4,5) == "S"){
        Serial.println("Set Speed");
        Spd = n;
      }
      else if(readString.substring(4,5) == "D"){
        Serial.println("Set Direction");
        Dir = n;
      }
      else{
        Serial.println("Unknown Set command");
      }
    }
    else{
      Serial.println("Unknown command");
    }

    //diagnostic prinout
    Serial.print("cmd: ");
    Serial.println(readString.substring(0,3));

    Serial.print("type: ");
    Serial.println(readString.substring(4,5));

    Serial.print("number: ");
    Serial.println(n);
    //end diagnostic prinout
    
    readString=""; //empty for next input
  } 
}
