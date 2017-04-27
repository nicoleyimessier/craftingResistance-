int led = 3;
int led2 = 1; 
int transistor = A1; 
int transistorValue = 0; 
int counter = 0; 
int offCounter = 0; 
int offWindow = 10; 
int timeFrame = 10; 
int timeFrame2 = 40; 

void setup() {
  pinMode(led, OUTPUT); 
  pinMode(led2, OUTPUT); 
}

void loop() {
  
  transistorValue = analogRead(transistor); 

  if(!transistorValue){
    counter++;
    offCounter = 0; 
    delay(500);  
  } else {
    offCounter++;
    digitalWrite(led,LOW);
    digitalWrite(led2,LOW);  
    delay(500); 
  }

  if(offCounter>offWindow){
      counter = 0; 
  }
  
  if(counter>timeFrame){
    digitalWrite(led, HIGH); 
  } 

  if(counter>timeFrame2){
   digitalWrite(led2, HIGH); 
  }
  
  
}
