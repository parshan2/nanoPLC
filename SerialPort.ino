
//initial serial ports
void SetupSerialPorts()
{
  Serial.begin(9600); //This pipes to the serial monitor
}

void Print(String value)
{
  Serial.println(value);
}

void Log(String value)
{
  if (!DEBUG_MODE)
    return;
  Serial.println(value);
}

// https://stackoverflow.com/questions/9072320/split-string-into-string-array
String GetStringPart(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}