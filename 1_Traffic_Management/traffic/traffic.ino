const int greenHorizontal1 = 13;
const int yellowHorizontal1 = 12;
const int redHorizontal1 = 11;

const int greenHorizontal2 = 10;
const int yellowHorizontal2 = 9;
const int redHorizontal2 = 8;


const int green3 = 7;
const int yellow3 = 6;
const int red3 = 5;


const int green4 = 14;
const int yellow4 = 15;
const int red4 = 16;


const int btnHorizontal = 19;
const int btnVertical = A0;

unsigned long waitTime = 0;
unsigned long currentTime = 0;


boolean horizontalGo = false;
boolean horizontalWait = true;
boolean verticalGo = true;
boolean verticalWait = true;

void setup() {

  pinMode(greenHorizontal1,  OUTPUT);
  pinMode(yellowHorizontal1,  OUTPUT);
  pinMode(redHorizontal1,  OUTPUT);

  pinMode(greenHorizontal2,  OUTPUT);
  pinMode(yellowHorizontal2,  OUTPUT);
  pinMode(redHorizontal2,  OUTPUT);


  pinMode(green3,  OUTPUT);
  pinMode(yellow3,  OUTPUT);
  pinMode(red3,  OUTPUT);


  pinMode(green4,  OUTPUT);
  pinMode(yellow4,  OUTPUT);
  pinMode(red4,  OUTPUT);


  pinMode(redHorizontal2,  OUTPUT);
  pinMode(redHorizontal2,  OUTPUT);


  pinMode(btnVertical,  INPUT);
  pinMode(btnHorizontal,  INPUT);


  Serial.begin(9600);

}

void loop() {

  if (horizontalGo == false) {
    goHorizontal();
  }


  if (horizontalWait == false) {
    waitHorizontal();
  }


  if (verticalGo == false) {
    goVertical();
  }


  if (verticalWait == false) {
    waitVertical();
  }





}


void goHorizontal() {

  if (waitTime == 0UL) {
    waitTime = millis();


    Serial.println("Go Horizontal.");

    digitalWrite(greenHorizontal1, HIGH);
    digitalWrite(greenHorizontal2, HIGH);

    digitalWrite(yellowHorizontal2, LOW);
    digitalWrite(yellowHorizontal1, LOW);

    digitalWrite(redHorizontal1, LOW);
    digitalWrite(redHorizontal2, LOW);


    digitalWrite(green3, LOW);
    digitalWrite(green4, LOW);

    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);


    digitalWrite(yellow3, LOW);
    digitalWrite(yellow4, LOW);

  } else {
    currentTime = millis();

    if ((currentTime - waitTime) > 5000UL) {


      Serial.println("Horizontal Done.");


      waitTime = 0;

      horizontalGo = true;
      horizontalWait = false;
      verticalGo = true;
      verticalWait = true;
    }
  }
}

void waitHorizontal() {

  if (waitTime == 0UL) {

    Serial.println("Wait Horizontal.");

    waitTime = millis();


    digitalWrite(yellowHorizontal1, HIGH);
    digitalWrite(greenHorizontal1, LOW);
    digitalWrite(redHorizontal1, LOW);


    digitalWrite(yellowHorizontal2, HIGH);
    digitalWrite(greenHorizontal2, LOW);
    digitalWrite(redHorizontal2, LOW);

  } else {
    currentTime = millis();

    if ((currentTime - waitTime) > 3000UL) {


      Serial.println("Wait Horizontal Done.");


      waitTime = 0;

      horizontalGo = true;
      horizontalWait = true;
      verticalGo = false;
      verticalWait = true;
    }

  }
}


void waitVertical() {


  if (waitTime == 0UL) {
    waitTime = millis();


    Serial.println("Wait Vertical.");

    digitalWrite(yellow3, HIGH);
    digitalWrite(green3, LOW);
    digitalWrite(red3, LOW);

    digitalWrite(yellow4, HIGH);
    digitalWrite(green4, LOW);
    digitalWrite(red4, LOW);

  } else {
    currentTime = millis();

    if ((currentTime - waitTime) > 3000UL) {


      Serial.println("Wait Vertical Done.");


      waitTime = 0;

      horizontalGo = false;
      horizontalWait = true;
      verticalGo = true;
      verticalWait = true;
    }

  }

}

void goVertical() {

  if (waitTime == 0UL) {
    waitTime = millis();

    Serial.println("Go Vertical.");

    digitalWrite(greenHorizontal1, LOW);
    digitalWrite(greenHorizontal2, LOW);

    digitalWrite(yellowHorizontal2, LOW);
    digitalWrite(yellowHorizontal1, LOW);

    digitalWrite(redHorizontal1, HIGH);
    digitalWrite(redHorizontal2, HIGH);


    digitalWrite(green3, HIGH);
    digitalWrite(green4, HIGH);

    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);

    digitalWrite(yellow3, LOW);
    digitalWrite(yellow4, LOW);



  } else {
    currentTime = millis();

    if ((currentTime - waitTime) > 5000UL) {


      Serial.println("Horizontal Done.");


      waitTime = 0;

      horizontalGo = true;
      horizontalWait = true;
      verticalGo = true;
      verticalWait = false;
    }

  }
}
