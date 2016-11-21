const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;
int led = 2;
//long interval = 600000;
long interval = 10000; // minute glass

void setup() {
  Serial.begin(9600);
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }  
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeInSec = currentTime/1000;
  
//  Serial.print("Time (s): ");
//  Serial.print(timeInSec);
  
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    
    digitalWrite(led, HIGH);
    led++;
    
    if(led == 7){
    }
  }
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite(x,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
  
  Serial.print("Time (s): ");
  Serial.print(timeInSec);
  Serial.print(", State: ");
  Serial.println(switchState);
  delay(1000); // print only one output per second
}
