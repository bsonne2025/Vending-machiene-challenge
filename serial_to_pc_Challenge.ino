int buttonA = 2;
int buttonB = 3;
int greenled = 4;
int redled = 5;
int button_stateA = 0;
int button_stateB = 0;


void setup() {
  // put your setup code here, to run once:
//setup lights
pinMode(greenled, OUTPUT);
pinMode(redled, OUTPUT);

//setup buttons
Serial.begin(9600);
pinMode(buttonA, INPUT);
pinMode(buttonB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_stateA = digitalRead(buttonA);
  button_stateB = digitalRead(buttonB);

  if (button_stateA == LOW && button_stateB == LOW)
    {
      Serial.print("Waiting...");
    }

   else if (button_stateA == HIGH && button_stateB == LOW)
    {
      Serial.println("Vending Soda");
      digitalWrite(greenled, HIGH);
      delay(1000);
      digitalWrite(greenled, LOW);
    }

    else if (button_stateA == LOW && button_stateB == HIGH)
      {
        Serial.println("Vending water");
        digitalWrite(greenled, HIGH);
        delay(1000);
        digitalWrite(greenled, LOW);
      }

    else if (button_stateA == HIGH && button_stateB == HIGH)
      {
        Serial.println("Product not available");
        digitalWrite(redled, HIGH);
        delay(1000);
        digitalWrite(redled, LOW); 
      }
}
