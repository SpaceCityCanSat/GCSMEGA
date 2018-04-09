/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int nogotop = 2;
int gortop = 3;
int gorbot = 4;
int nogobot = 5;
int golbot = 6;
int goltop = 7;
int nogomid = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

//initiating push button to pin 13
int PB =  1;
int pb = LOW;

//initiating the position vaitables for digit 1 Left top (lt1), left bottom (lb1), right top 1 (rt1) and right bottom (rb1) 
int lt1 =0  ;
int lb1 =0;
int rt1 =0;
int rb1 =0;
int t1 =0;
int m1 =0;
int b1 =0;
// initiating the vertical varibles for digit 2
int lt2 =0;
int lb2 =0;
int rt2 =0;
int rb2 =0;
int t2 =0;
int m2 =0;
int b2 =0;

int lt3 =0;
int lb3 =0;
int rt3 =0;
int rb3 =0;
int t3 =0;
int m3 =0;
int b3 =0;

int lt4 =0;
int lb4 =0;
int rt4 =0;
int rb4 =0;
int t4 =0;
int m4 ;
int b4 =0;

//Initiating .csv variables
int TEAMID=6198;                 
int MISSIONTIME=132;
int PACKETCOUNT=0;
int ALTITUDE=103;
int PRESSURE=0;
int TEMP=15;
int VOLTAGE=6;
int GPSTIME=0;
int GPSLATITUDE=0;
int GPSLONGITUDE=0;
int GPSALTITUDE=0;
int TILTX=0;
int TILTY=0;
int TILTZ=0;
int SOFTWARESTATE="tops";




// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(nogotop, OUTPUT);     
  pinMode(gortop, OUTPUT);     
  pinMode(gorbot, OUTPUT);     
  pinMode(nogobot, OUTPUT);     
  pinMode(golbot, OUTPUT);     
  pinMode(goltop, OUTPUT);     
  pinMode(nogomid, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);    

// assigning pushbutton as an input
  pinMode(PB ,INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
 
//defining go-nogo conditions and assigning position variable value. 1 or 0
// digit 1
  if (TEAMID == 6198)
    {
      lt1 = 1;
     }
    else
      {
        lt1=0;
        t1 = 1;
       }
  if (MISSIONTIME > 0)
    {
      rt1 = 1;
     }
    else 
      {
        t1 = 1;
       }
  if (PACKETCOUNT == 0 )
    { 
      lb1 = 1;
     }
    else       
      {
        b1 = 1;
       }
  if  (SOFTWARESTATE == "goal" ||SOFTWARESTATE== "tops")
    {
      rb1 = 1;
     }
    else
      { 
        b1  = 1;
       }
 
// digit 2
  if (ALTITUDE >= 0)
    {
      lt2 = 1;
     }
    else
      {
        t2 = 1;
       }
  if (TEMP > 10)
    {
      rt2 = 1;
     }
    else 
      {
        t2 = 1;
       }
  if (PRESSURE == 0 )
    { 
      lb2 = 1;
     }
    else       
      {
        b2 = 1;
       }
  if  (VOLTAGE >=3.3 && VOLTAGE <= 6.2)
    {
      rb2 = 1;
     }
    else
      { 
        b2  = 1;
       }

  pb = digitalRead(PB);
  if (pb == HIGH)
  {
    TEAMID=1234;
  }
    else 
      {
        TEAMID=6198;
      }
  
  
  //turning on the segments using the segment variables
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
  
  digitalWrite(nogotop, t1);   
  digitalWrite(gortop, rt1);   
  digitalWrite(gorbot, rb1);   
  digitalWrite(nogobot, b1);   
  digitalWrite(golbot, lb1);   
  digitalWrite(goltop,  lt1);   
  digitalWrite(nogomid, m1);   
  delay(1);               // wait for a second
  
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
  
  digitalWrite(nogotop, t2);   
  digitalWrite(gortop, rt2);   
  digitalWrite(gorbot, rb2);   
  digitalWrite(nogobot, b2);   
  digitalWrite(golbot, lb2);   
  digitalWrite(goltop,  lt2);   
  digitalWrite(nogomid, m2);   
  delay(1);               // wait for a second
  
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
  
  digitalWrite(nogotop, t3);   
  digitalWrite(gortop, rt3);   
  digitalWrite(gorbot, rb3);   
  digitalWrite(nogobot, b3);   
  digitalWrite(golbot, lb3);   
  digitalWrite(goltop, lt3);   
  digitalWrite(nogomid, m3);     
  delay(1);               // wait for a second

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 

  digitalWrite(nogotop, t4);   
  digitalWrite(gortop, rt4);   
  digitalWrite(gorbot, rb4);   
  digitalWrite(nogobot, b4);   
  digitalWrite(golbot, lb4);   
  digitalWrite(goltop, lt4);   
  digitalWrite(nogomid, m4);     
  delay(1);

}
