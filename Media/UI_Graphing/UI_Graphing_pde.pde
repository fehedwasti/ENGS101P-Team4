/*
  UI Graphing
  Takes in 2 potentially different sets of data from Arduino/MSP in alternating fashion
  and graphs them into 2 separate line-graphs on the same axes
*/

import processing.serial.*;

Serial myPort;
float prevNaturalY = 0;
float newNaturalY;
float newAvgY = 0;
float prevAvgY;
int loopCount = 1;
int xValue = 1;


void setup() 
{
  size(800, 600);
  //frameRate(1); To plot the graph at 1 point per second 
  frameRate(10);
  drawLayout();
  myPort = new Serial (this, "COM6", 9600);
}

void draw() 
{
  String stringValue = myPort.readStringUntil('\n');
  if (stringValue != null)
  {
    loopCount++;
    stringValue =trim(stringValue);
    float floatValue = float(stringValue);
    strokeWeight(2);
    
    //draws a red line and blue line on alternate non-null inputs from the microcontroller
    newNaturalY = (height - floatValue) - 15;
    stroke(255, 0, 0);
    line( (xValue - 1), prevNaturalY, (xValue), newNaturalY);
    xValue = xValue + 1;
    
    prevNaturalY = newNaturalY;
    
    /*
    {
      newAvgY = (height - floatValue) - 15;
      stroke(0, 0, 255);
      if (loopCount > 3)
      {
        line( (4 * (xValue - 1)) , prevAvgY, (4 * xValue), newAvgY);
      }
      prevAvgY = newAvgY;
    }*/
  }
  
  //Refreshes the screen when edge of screen has been reached by graph
  if (xValue >= width) 
  {
    xValue = 1;
    drawLayout();
  }

}

/* Draws the background grid of the graph, including gridlines and axes of graph */
void drawLayout() 
{
  background(0);
  strokeWeight(1);
 
  //draws vertical gridlines and numbers them
  for (int i = 0; i <= width; i += 50) 
  {
    fill(0, 255, 0);
    text(i*3/50, i, height-15);
    stroke(255);
    line(i, height, i, 0);
  }
  
  //draws horiontal gridlines and numbers them
  for (int j = 0; j <= height; j += 50) 
  {
    fill(0, 255, 0);
    text((height - j), 0, j-15);
    stroke(255);
    line(0, j-15, width, j-15);
  }
  //labelling of axes
  fill(0, 255, 0);
  text("(brightness/lux)", 0, 15);
  text("(time/s)", width-50, height-5);
}