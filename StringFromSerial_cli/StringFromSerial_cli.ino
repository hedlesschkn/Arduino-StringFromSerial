String readString;

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
    
    if(readString.substring(0,3) == "get"){
      if(readString.substring(4,5) == "S"){
        Serial.println("Get Speed");
      }
      else if(readString.substring(4,5) == "D"){
        Serial.println("Get Direction");
      }
      else{
        Serial.println("Unknown Get command");
      }
    }
    else if(readString.substring(0,3) == "set"){
      if(readString.substring(4,5) == "S"){
        Serial.println("Set Speed");
      }
      else if(readString.substring(4,5) == "D"){
        Serial.println("Set Direction");
      }
      else{
        Serial.println("Unknown Set command");
      }
    }
    else{
      Serial.println("Unknown command");
    }

    Serial.print("cmd: ");
    Serial.println(readString.substring(0,3));

    Serial.print("type: ");
    Serial.println(readString.substring(4,5));

    Serial.print("number: ");
    int n = readString.substring(5).toInt();  //convert readString into a number
    Serial.println(n);
    
    readString=""; //empty for next input
  } 
}
