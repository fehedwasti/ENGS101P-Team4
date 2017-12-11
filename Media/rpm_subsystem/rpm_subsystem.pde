import processing.serial.*;

import g4p_controls.*;

Serial myPort;
Serial myPort2;
GWindow window;
float prevNaturalY = 0;
float newNaturalY;
float newAvgY = 0;
float prevAvgY;
int loopCount = 1;
int xValue = 1;

public class MyData extends GWinData
{
  public void drawstuff() 
  {
    window.background(222);
    window.line(200,100,50,30);
    
    window.background(0);
    window.strokeWeight(1);
   
    //draws vertical gridlines and numbers them
    for (int i = 0; i <= window.width; i += 50) 
    {
      window.fill(0, 255, 0);
      window.text(i*5/50, i, window.height-15);
      window.stroke(255);
      window.line(i, window.height, i, 0);
    }
    
    //draws horiontal gridlines and numbers them
    for (int j = 0; j <= window.height; j += 30) 
    {
      window.fill(0, 255, 0);
      window.text(((window.height - j) * 5), 0, j-15);
      window.stroke(255);
      window.line(0, j-15, window.width, j-15);
    }
    //labelling of axes
    window.fill(0, 255, 0);
    window.text("(brightness/lux)", 0, 15);
    window.text("(time/s)", window.width-50, window.height-5);
  }
  
  float i, j, xValue, newy, oldy = 0;
}

public void setup()
{
  size(600, 400, JAVA2D);
  createGUI();
  customGUI();
  window = GWindow.getWindow(this, "My Window", 100, 50, 720, 480, JAVA2D);
  window.addDrawHandler(this, "windowDraw");
  window.addData(new MyData());
  window.addPreHandler(this, "windowPre");    
  myPort = new Serial (this, "COM6", 9600);
  myPort2 = new Serial (this, "COM3", 9600);
  
}

public void draw()
{
  background(230);
  
}
public void customGUI()
{

}

public void windowPre(PApplet appec, GWinData data)
{
  MyData myData = (MyData) data;
  if (myData.xValue == 0)
  {
    myData.drawstuff();
  }
}

  
public void windowDraw(PApplet app, GWinData data)
{
  MyData myData = (MyData) data;
  app.frameRate(1000);
  String stringValue = myPort2.readStringUntil('\n');
  /*app.line(myData.i + 50, myData.j + 50, myData.i - 50, myData.j - 50);  
  myData.i += float(stringValue);
  myData.j += float(stringValue);
  if (myData.i > 500)
  {
    myData.i -= 500;
    myData.j -= 500;
  }*/
  if (stringValue != null)
  {
    float floatValue = float(stringValue);
    app.strokeWeight(4);
    
    //draws a red line and blue line on alternate non-null inputs from the microcontroller
    myData.newy = (app.height - floatValue / 5);
    app.stroke(255, 0, 0);
    app.line( (myData.xValue), myData.oldy - 15, (myData.xValue + 1), myData.newy - 15);
    myData.xValue = myData.xValue + 1;
    
    myData.oldy = myData.newy;
    
  }
  if (myData.xValue > app.width) 
    {
      myData.xValue = 0;
      myData.drawstuff();
    }
  
  
  
  
  
  
}







  