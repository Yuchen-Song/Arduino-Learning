const int numCols=4;
const int numRows=4;
const char keymap[numRows][numCols]=
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
const int debounceTime = 20;
const int rowPins[numRows]={4,5,6,7};//左一：行一
const int colPins[numCols]={8,9,10,11};//右一：列四
void setup() {

  Serial.begin(9600);
  for(int i=0; i<numRows; i++)
  {
    pinMode(rowPins[i],OUTPUT);
    digitalWrite(rowPins[i],HIGH);
  }
  for(int i=0; i<numCols; i++)
  {
    pinMode(colPins[i],INPUT);
    digitalWrite(colPins[i],HIGH);
  }
}

void loop() {

  char key=getkey();
  if(key!=0)
  {
    Serial.print("Got key:");//这里print会怎样？会报错！
    Serial.println(key);
  }
}

char getkey()
{
  char key = 0;
  for (int row=0; row<numRows; row++)
  {
    digitalWrite(rowPins[row],LOW);
    for (int column =0; column<numCols; column++)
    {
      if (digitalRead(colPins[column])==LOW)
      {
        delay(debounceTime);
        while (digitalRead(colPins[column])==LOW)
        {
          key=keymap[row][column];
        }
      }
    }
    digitalWrite(rowPins[row],HIGH);
  }
  return key;
}
