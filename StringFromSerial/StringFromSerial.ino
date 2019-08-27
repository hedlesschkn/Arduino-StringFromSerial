String readString;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Seral String Input");
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
    int n = readString.toInt();  //convert readString into a number

    readString=""; //empty for next input
  } 
}
