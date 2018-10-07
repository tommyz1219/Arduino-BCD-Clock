long i;

//input pins
void setup()
{
  for (i = 0; i < 13; i++)
  {  
    pinMode (i, OUTPUT);
  }
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
}

//output pins
byte minuteone = 0;
byte minuteten = 0;
byte hourone = 0;
byte hourten = 0;
long delayTime = 0;
int Fast_Slow;

void loop()
{

  digitalWrite (0 , bitRead  (minuteone, 0));
  digitalWrite (1 , bitRead  (minuteone, 1));
  digitalWrite (2 , bitRead  (minuteone, 2));
  digitalWrite (3 , bitRead  (minuteone, 3)); 
  digitalWrite (4 , bitRead  (minuteten, 0));
  digitalWrite (5 , bitRead  (minuteten, 1));
  digitalWrite (6 , bitRead  (minuteten, 2));
  digitalWrite (7 , bitRead  (hourone  , 0));
  digitalWrite (8 , bitRead  (hourone  , 1));
  digitalWrite (9 , bitRead  (hourone  , 2));
  digitalWrite (10, bitRead  (hourone  , 3));
  digitalWrite (11, bitRead  (hourten  , 0));
  digitalWrite (12, bitRead  (hourten  , 1));
  
  minuteone ++;
  
  if (minuteone == 10)
  {
     minuteone = 0;
     minuteten ++;
  }
  
  if (minuteten == 6)
  {
    minuteten = 0;
    hourone ++;
  }
  
  if (hourone == 10)
  {
    hourone = 0;
    hourten ++;
  }

  if (hourten == 2 && hourone == 3)
  {
    hourten == 0;
  }  

   for(i = 0; i < 60000; i = i + delayTime)
   {
      Fast_Slow = digitalRead(A0);
      if(Fast_Slow == HIGH)
      {
        delayTime = 10;
      }
      else
      {
         delayTime = 60000;
      }
       Fast_Slow = digitalRead(A1);
      if(Fast_Slow == LOW)
      {
        delayTime = 1000; 
      }
        delay(10); 
   }
}


/*monitors the state of each button, and speeds up if either is pressed

   for(long i = 0; i < 60000; i = i + delayTime){
      Fast_Slow = digitalRead(A0);
      if(Fast_Slow == HIGH){
        delayTime = 10;
      }
      else{
         delayTime = 60000;
      }
       Fast_Slow = digitalRead(A1);
      if(Fast_Slow == LOW){
        delayTime = 1000; 
      }
        delay(10); 
    }
