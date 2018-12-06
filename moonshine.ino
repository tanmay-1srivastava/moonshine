#define sensor A6
int sensorValue;  
int level;
int cal [25];
int aMax;
int i;
     int segment[11][8] = {{0,0,0,1,0,0,0,1},    // 0
                          { 0,1,1,1,1,1,0,1 },    // 1
                          { 0,0,1,0,0,0,1,1 },    // 2                
                          { 0,0,1,0,1,0,0,1 },    // 3
                          { 0,1,0,0,1,1,0,1 },    // 4
                          { 1,0,0,0,1,0,0,1 },    // 5
                          { 1,0,0,0,0,0,0,1 },    // 6
                          { 0,0,1,1,1,1,0,1 },    // 7
                          { 0,0,0,0,0,0,0,1 },    // 8
                          { 0,0,0,0,1,0,0,1 },     //9
                          {1,1,1,1,1,1,1,0}};   //blank
                                       
void output(int);


void setup() {    
  Serial.begin(9600); 
   pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);   
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
 pinMode(13,OUTPUT);
  pinMode(sensor, INPUT);  
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, LOW);
 for(i = 0; i < 20; i++){
    cal[i] = analogRead(A6);
    if(cal[i] >= aMax){
      aMax = cal[i];
    }
  }  
}


void loop() {

   sensorValue = analogRead(sensor);
   level = map(sensorValue, aMax, 1023, 0, 9);         
   
      Serial.print(sensorValue);
      Serial.print("  ");
      Serial.println(level);

output(level);
}

void output(int ans) 
{ 
if(ans>=3 ){
  int pin= 2;
  for (int j=0; j < 8; j++) {
   digitalWrite(pin, segment[ans][j]);  
   pin++;
  }
digitalWrite(13,LOW);
}
else{
   int pin= 2;
  for (int j=0; j < 8; j++) {
   digitalWrite(pin, segment[10][j]);  
   pin++;
  digitalWrite(13,HIGH);
  }
}

}

