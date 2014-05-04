#include <Keypad.h>

/*  
*Katherine Stasaski, Terrence Lewis, Ehren Wong
*This project allows the user to input a 4 digit key and
*notifies if it is correct or incorrect
 *
 */


const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
int led = 13; //LED pin for the arduino's built in LED
char code[4] = {'1','2','3','4'}; //Correct combination
byte rowPins[ROWS] = { 2, 6, 9, 8 }; //pins the rows are connected to
byte colPins[COLS] = { 10, 11, 12 }; //pins the columns are connected to
char input[4]; //array to store the input
int test = 0; //tracks how many numbers are correct
int counter = 0; //counts how many numbers have been entered


// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup()
{
  //sets led as output
  pinMode(led, OUTPUT); 
  
  pinMode (11, INPUT);//Column 1
pinMode (12, INPUT);//Column 2
pinMode (10, INPUT);//Column 3

//this implements the columns as a weak pull up resistor
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
//begins the serial monitor
  Serial.begin(9600);
}

void loop()
{
  //gets a key from the user
  char key = kpd.getKey();
  //if the key is found
  if(key)  
  {
    //stores the input
    input[counter] = key;
    //increments the counter
    counter++;
    //if a 4 digit code has been put in
    if(counter == 4)
    {
      //checks if the code is correct
      for(int i = 0; i < 4; i++)
      {

        if(input[i] == code[i])
        {
          test++;
        }
      }
     // if the code is correct, blinks 5 times
      if(test == 4)
      {
        Serial.print("right combo");
         digitalWrite(led, HIGH);  
         delay(1000);
         digitalWrite(led, LOW);  
         delay(1000);
         digitalWrite(led, HIGH);  
         delay(1000);
         digitalWrite(led, LOW); 
         delay(1000);
         digitalWrite(led, HIGH);  
         delay(1000);
         digitalWrite(led, LOW); 
         delay(1000);
         digitalWrite(led, HIGH);  
         delay(1000);
         digitalWrite(led, LOW); 
         //resets values
         input[0] = NULL;
     input[1] = NULL;
     input[2] = NULL;
     input[3] = NULL;
      }    
      //if code is incorrect, blinks once
      else
       {
                 Serial.print("wrong combo");

         digitalWrite(led, HIGH);  
         delay(1000);
         digitalWrite(led, LOW); 
         input[0] = NULL;
     input[1] = NULL;
     input[2] = NULL;
     input[3] = NULL;
       } 
     //resets values
     counter = 0;
     test = 0;
    }
    //prints key
    Serial.println(key);
    
  }
}
//old code that was used to code getting the user's key before the
//keypad library was found.
/*
void loop() {
// read row 1
digitalWrite(row1, LOW); // activate row 1
value = digitalRead(col1); // read row 1 & col 1 = button 1
if(value == 0) { // if the button is pressed...
Serial.println("Button 1 Pressed");
delay(1000);
}
digitalWrite(row1, HIGH); // deactivate row 1

// repeat above for buttons 2 - 12 (i.e. rows 1 - 4 and cols 1 - 3)

digitalWrite(row1, LOW);
value = digitalRead(col2);
if(value == 0) {
Serial.println("Button 2 Pressed");
delay(1000);
}
digitalWrite(row1, HIGH);


digitalWrite(row1, LOW);
value = digitalRead(col3);
if(value == 0) {
Serial.println("Button 3 Pressed");
delay(1000);
}
digitalWrite(row1, HIGH);


digitalWrite(row2, LOW);
value = digitalRead(col1);
if(value == 0) {
Serial.println("Button 4 Pressed");
delay(1000);
}
digitalWrite(row2, HIGH);


digitalWrite(row2, LOW);
value = digitalRead(col2);
if(value == 0) {
Serial.println("Button 5 Pressed");
delay(1000);
}
digitalWrite(row2, HIGH);


digitalWrite(row2, LOW);
value = digitalRead(col3);
if(value == 0) {
Serial.println("Button 6 Pressed");
delay(1000);
}
digitalWrite(row2, HIGH);


digitalWrite(row3, LOW);
value = digitalRead(col1);
if(value == 0) {
Serial.println("Button 7 Pressed");
delay(1000);
}
digitalWrite(row3, HIGH);


digitalWrite(row3, LOW);
value = digitalRead(col2);
if(value == 0) {
Serial.println("Button 8 Pressed");
delay(1000);
}
digitalWrite(row3, HIGH);


digitalWrite(row3, LOW);
value = digitalRead(col3);
if(value == 0) {
Serial.println("Button 9 Pressed");
delay(1000);
}
digitalWrite(row3, HIGH);


digitalWrite(row4, LOW);
value = digitalRead(col1);
if(value == 0) {
Serial.println("Button * Pressed");
delay(1000);
}
digitalWrite(row4, HIGH);


digitalWrite(row4, LOW);
value = digitalRead(col2);
if(value == 0) {
Serial.println("Button 0 Pressed");
delay(1000);
}
digitalWrite(row4, HIGH);


digitalWrite(row4, LOW);
value = digitalRead(col3);
if(value == 0) {
Serial.println("Button # Pressed");
delay(1000);
}
digitalWrite(row4, HIGH);

}*/
