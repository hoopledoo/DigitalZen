#include <TVout.h>
#include <fontALL.h>
#include <stdlib.h>

TVout TV;

void setup() {
  // put your setup code here, to run once:
  TV.begin(NTSC,120,96);
  TV.select_font(font6x8);
  TV.println("Hello World. What's happenin'");
  TV.println(int(TV.hres()));
  TV.println(int(TV.vres()));
  TV.delay(2500);
}

void drawripple(int x, int y){
  for(int i=1;i<20;i++){
    //TV.draw_circle(x, y, 2*i, WHITE, WHITE);
    TV.draw_circle(x, y, 2*i, WHITE);
    TV.draw_circle(x, y, 2*(i-1), BLACK); 
    delay(25*i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  TV.clear_screen();
  //int x = rand()%TV.hres();
  //int y = rand()%TV.vres();
  //drawripple(x, y);
  drawripple(TV.hres()/2, TV.vres()/2);
  TV.clear_screen();
  TV.println("Wasn't that pretty?");
  delay(5000);
}
