const int analogInPin = A3; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;

int sensor_pin = A0;
int output_value;

int val;
int tempPin = 3;

const int ledPin = 3;
const int ldrPin = A1;

void setup() {
  pinMode(2, OUTPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(ldrPin, INPUT);
  pinMode(A1, INPUT);
  
  Serial.begin(9600);
  Serial.println("Reading From the Sensors ...");
  Serial.println("--------------------------");
}

void loop() {

  //soil moisture sensor
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,0,0,100);
  Serial.println(output_value);
  if (output_value > 20){
  digitalWrite(2, HIGH); 
  }
  else{
  digitalWrite(2, LOW);   
  }
   
  //LDR sensor
  int ldrStatus = analogRead(ldrPin);
  if (ldrStatus <= 200) {
  digitalWrite(ledPin, LOW);
  Serial.println("Bad Intensity");
  } else {
  digitalWrite(ledPin, HIGH);
  Serial.println("Good Intensity");
  }

  //pH Sensor
  for(int i=0;i<10;i++) 
  { 
  buf[i]=analogRead(analogInPin);
  }
  for(int i=0;i<9;i++)
  {
  for(int j=i+1;j<10;j++)
  {
  if(buf[i]>buf[j])
  {
  temp=buf[i];
  buf[i]=buf[j];
  buf[j]=temp;
  }
  }
  }
  avgValue=0;
  for(int i=2;i<8;i++)
  avgValue+=buf[i];
  float pHVol=(float)avgValue*5.0/1024/6;
  float phValue = -5.70 * pHVol + 21.34;
  Serial.println(phValue);

  //temperature Sensor
  val = analogRead(tempPin);
  float cel = ((val * 4.88) / 10) - 273;
  Serial.print(cel);
  Serial.println();

  Serial.println("--------------------------");
  delay(1000);
}
