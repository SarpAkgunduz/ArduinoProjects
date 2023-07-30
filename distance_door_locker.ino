#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int trigPin = 4;
const int echoPin = 3;
const int servoPin = 7;
float duration, distance;  
String State;

LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo;

float sensor_Distance(){
//Read sensor value and calculate distance. Returns Distance
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration*.0343)/2;  
  Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);
  return distance;
}

String LCD_print(){
//Set LCD cursor to proper position and write current state with distance. Returns State 
  lcd.setCursor(0,0); 
  lcd.print("Distance: ");
  lcd.setCursor(10,0); 
  lcd.print(distance);
  if (distance >= 100){
    lcd.setCursor(0,1); 
    lcd.print("close");
    delay(500);
    lcd.clear();
    State = "close";
  }
  if (distance <= 100){
    lcd.setCursor(0,1); 
    lcd.print("open");
    delay(500);
    lcd.clear();
    State = "open";
  }
  return State;
}

void servo_State(){
//Set servo 0 to 180 degree with State variable from previous function.
  if (State.equals("open")){
    myservo.write(180);
  }
  if (State.equals("close")){
    myservo.write(0);
  }
}


void setup() {
  //hcsr04 setup
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
  Serial.begin(9600);

  //lcd setup
  lcd.init();
  lcd.backlight();

  //servo motor setup
  myservo.attach(servoPin);
  myservo.write(0);
}
 
void loop() {
  
  sensor_Distance();
  LCD_print();
  servo_State();
	
}
