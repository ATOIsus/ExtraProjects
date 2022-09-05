
void setup() {
  Serial.begin(9600);
  pinMode(D1, INPUT);
  pinMode(D4, OUTPUT);
}

void loop() {



  byte val = digitalRead(D1);
  
  Serial.println(val);

  if(val == HIGH){
      digitalWrite(D4, LOW);
    }    
  else{
      digitalWrite(D4, HIGH);                      
   }             
}
