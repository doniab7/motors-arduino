                     //                                  ______________________
#define M1P1 3       // moteur 1 pin 1                   |       front        |                    ^
#define M1P2 4       // moteur 1 pin 2              M1 (   )                (   ) M4               |    sens 1
#define M2P1 7       // moteur 2 pin 1                   |                    | 
#define M2P2 8       // moteur 2 pin 2                   |                    |       
#define M3P1 9       // moteur 3 pin 1                   |                    |                    |    sens 2
#define M3P2 10      // moteur 3 pin 2              M2 (   )                (   ) M3               v
#define M4P1 11      // moteur 4 pin 1                   |_______back_________| 
#define M4P2 12      // moteur 4 pin 2 


// rq: carte relais active a letat bas


char val = 0;


void setup(){

pinMode(M1P1, OUTPUT);  
pinMode(M1P2, OUTPUT);  
pinMode(M2P1, OUTPUT);  
pinMode(M2P2, OUTPUT);  
pinMode(M3P1, OUTPUT);  
pinMode(M3P2, OUTPUT);  
pinMode(M4P1, OUTPUT);  
pinMode(M4P2, OUTPUT);  
Serial.begin(9600);

}



void loop(){
  

 		 while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'Z')     // Forward
    {
      digitalWrite(M1P1, LOW);        // M1 tourne dans le sens 1
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);       // M2 ne tourne pas
      digitalWrite(M2P2, HIGH); 
      digitalWrite(M3P1, HIGH);       // M3 ne tourne pas
      digitalWrite(M3P2, HIGH);
      digitalWrite(M4P1, LOW);        // M4 tourne dans le sens 1
      digitalWrite(M4P2, HIGH);  
    }

  else if(val == 'S') // Backward
    {
      digitalWrite(M1P1, HIGH);        // M1 ne tourne pas
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);        // M2 tourne dans le sens 2
      digitalWrite(M2P2, LOW); 
      digitalWrite(M3P1, HIGH);        // M3 tourne dans le sens 2
      digitalWrite(M3P2, LOW);
      digitalWrite(M4P1, HIGH);        // M4 ne tourne pas
      digitalWrite(M4P2, HIGH);  
    }
  
    else if(val == 'Q')  //Left    
    {
      digitalWrite(M1P1, LOW);         // M1 tourne dans le sens 1
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);        // M2 ne tourne pas
      digitalWrite(M2P2, HIGH); 
      digitalWrite(M3P1, HIGH);        // M3 ne tourne pas
      digitalWrite(M3P2, HIGH);
      digitalWrite(M4P1, HIGH);        // M4 ne tourne pas
      digitalWrite(M4P2, HIGH); 
    }
    else if(val == 'D') //Right
    {
      digitalWrite(M1P1, HIGH);        // M1 ne tourne pas
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);        // M2 ne tourne pas
      digitalWrite(M2P2, HIGH); 
      digitalWrite(M3P1, HIGH);        // M3 ne tourne pas
      digitalWrite(M3P2, HIGH);
      digitalWrite(M4P1, LOW);        // M4 tourne dans le sens 1
      digitalWrite(M4P2, HIGH);
    }
    
 





    //optional: reculer et tourner en meme temps

      else if(val == 'K') //Left
    {
      digitalWrite(M1P1, HIGH);        // M1 ne tourne pas
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);        // M2 tourne dans le sens 2
      digitalWrite(M2P2, LOW); 
      digitalWrite(M3P1, HIGH);        // M3 ne tourne pas
      digitalWrite(M3P2, HIGH);
      digitalWrite(M4P1, HIGH);         // M4 ne tourne pas
      digitalWrite(M4P2, HIGH);
    }
        else if(val == 'M') //Right
    {
      digitalWrite(M1P1, HIGH);        // M1 ne tourne pas
      digitalWrite(M1P2, HIGH);
      digitalWrite(M2P1, HIGH);        // M2 ne tourne pas
      digitalWrite(M2P2, HIGH); 
      digitalWrite(M3P1, HIGH);        // M3 tourne dans le sens 2
      digitalWrite(M3P2, LOW);
      digitalWrite(M4P1, HIGH);        // M4 ne tourne pas
      digitalWrite(M4P2, HIGH);
    }
  
}



