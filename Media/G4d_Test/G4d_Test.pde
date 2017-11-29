import processing.serial.*;

import g4p_controls.*;

Serial myPort;

public void setup()
{
  size(600, 400, JAVA2D);
  createGUI();
  customGUI();
  myPort = new Serial (this, "COM6", 9600);
}

public void draw()
{
  background(230);
}
public void customGUI()
{

}