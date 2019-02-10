String WaitForInput() {
  Serial.print("Enter Command:");
  
  while(!Serial.available()) {
    // wait for input
  }
  String out = Serial.readString();
  return out; 
}

void manualCmd(char command)
{
  switch (command)
  {
    
    case 'm': 
      startSafe();
      Serial.println("Roomba in Safe mode");
      BT1.print("Roomba BT Ctrl OK - Safe mode");
      BT1.println('\n');
      command = 'f';
      playSound (3);
      break;
 
    case 'f': 
      driveStop(); //turn off both motors
      writeLEDs ('s', 't', 'o', 'p');
      Serial.println("STOP");
      state = command;
      break;

    case 'w':  
      drive (motorSpeed, 0); 
      writeLEDs (' ', 'g', 'o', ' ');
      Serial.println("Moving Forward");
      state = command;  
      break;

    case 'd':     
      driveRight(motorSpeed);
      writeLEDs ('r', 'i', 'g', 'h');
      Serial.println("Turning Right");
      break;

   case 'a': 
      driveLeft(motorSpeed);
      writeLEDs ('l', 'e', 'f', 't');
      Serial.println("Turning Left");
      break;
    
    case 's':  
      drive (-motorSpeed, 0);
      writeLEDs ('b', 'a', 'c', 'k');
      Serial.println("Going Backwards");
      state = command;
      break;

    case '+': 
      if (state == 'w')
      {
        motorSpeed = motorSpeed + 10;
        if (motorSpeed > MAX_SPEED) 
        { 
          motorSpeed = MAX_SPEED;
        }  
        command = 'w';
      } else {command = state;}
      break;

    case '-': 
 
      if (state == 'w')
      {
        motorSpeed = motorSpeed - 10;
      }     
      if (motorSpeed < MIN_SPEED ) 
      { 
        motorSpeed = MIN_SPEED;
      }
      Serial.println(motorSpeed); 
      command = state;
      break;
  }
}
