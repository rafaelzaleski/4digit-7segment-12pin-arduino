/*
 * Author: Rafael Zaleski
 *
 * The selector pin (common cathode for each digit) changes every 5ms to display 
 * different numbers using the common pins 'a' to 'g' in the display. 
 *
 * Don't forget that you have to change the code if your display is common anode
 */

int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, dp = 8;

int d1 = 9, d2 = 10, d3 = 11, d4 = 12;

int time = 100; //speed of the counter 

void setup() {
  int i = 1;
  for(; i<13; i++)
    pinMode(i, OUTPUT);
    
}

void loop() {
  offd(d1);
  offd(d2);
  offd(d3);
  offd(d4);
  
  int i, j;
  for(i = 0; i<10000; i++) {
    for(j = 0; j <= (time/20); j++) {
      ond(d1);
      num(i%10);
      delay(5);
      offd(d1);
      
      ond(d2);
      num(i/10 - 10*(i/100));
      delay(5);
      offd(d2);
      
      ond(d3);
      num(i/100 - 10*(i/1000));
      delay(5);
      offd(d3);
      
      ond(d4);
      num(i/1000);
      delay(5);
      offd(d4);    
    }

    
    
  }
  
  
}

void on(int i) {
  digitalWrite(i, HIGH);
}

void off(int i){
 digitalWrite(i, LOW); 
}

void ond(int i) {
  digitalWrite(i, LOW);
}

void offd(int i){
 digitalWrite(i, HIGH); 
}

void num(int n) {
 
 if(n < 0)
  n = 0; 
  
 switch(n) {
 
   case 0:
     on(a);
     on(b);
     on(c);
     on(d);
     on(e);
     on(f);
     off(g);
     break;
   case 1:
     off(a);
     on(b);
     on(c);
     off(d);
     off(e);
     off(f);
     off(g);
     break;
   case 2:
     on(a);
     on(b);
     off(c);
     on(d);
     on(e);
     off(f);
     on(g);
     break;
   case 3:
     on(a);
     on(b);
     on(c);
     on(d);
     off(e);
     off(f);
     on(g);
     break;
   case 4:
     off(a);
     on(b);
     on(c);
     off(d);
     off(e);
     on(f);
     on(g);
     break;
   case 5:
     on(a);
     off(b);
     on(c);
     on(d);
     off(e);
     on(f);
     on(g);
     break;
   case 6:
     on(a);
     off(b);
     on(c);
     on(d);
     on(e);
     on(f);
     on(g);
     break;
   case 7:
     on(a);
     on(b);
     on(c);
     off(d);
     off(e);
     off(f);
     off(g);
     break;
   case 8:
     on(a);
     on(b);
     on(c);
     on(d);
     on(e);
     on(f);
     on(g);
     break;
   case 9:
     on(a);
     on(b);
     on(c);
     on(d);
     off(e);
     on(f);
     on(g);
     break;
 
   
 }
 
  
}
