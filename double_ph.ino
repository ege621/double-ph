unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10], buf2[10] ,temp;
int i,j,k,m;
unsigned long int avgValue2;
#define SensorPin1 0
#define SensorPin2 1


void setup() {
  Serial.begin(9600);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
  // put your setup code here, to run once:

}

void loop() {
for (i = 0; i < 10; i++) //Get 10 sample value from the sensor for smooth the value
  {
    buf[i] = analogRead(SensorPin1);
  
  }
  for (i = 0; i < 9; i++) //sort the analog from small to large
  {
    for (j = i + 1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (i = 2; i < 8; i++)               //take the average value of 6 center sample
    avgValue += buf[i];
  float phValue1 = (float)avgValue * 5.0 / 1024 / 6; //convert the analog into millivolt
  phValue1 = 3.5 * phValue1+0.3;                //convert the millivolt into pH value
  // Serial.print("    pH:");
  

  
for (i = 0; i < 10; i++) //Get 10 sample value from the sensor for smooth the value
  {
    buf[i] = analogRead(SensorPin2);
  
  }
  for (i = 0; i < 9; i++) //sort the analog from small to large
  {
    for (j = i + 1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (i = 2; i < 8; i++)               //take the average value of 6 center sample
    avgValue += buf[i];
  float phValue2 = (float)avgValue * 5.0 / 1024 / 6; //convert the analog into millivolt
  phValue2 = 3.5 * phValue2 +0.15;                //convert the millivolt into pH value
  
Serial.print(phValue1);
Serial.print(" ");
Serial.println(phValue2);
delay(1000);  
}
