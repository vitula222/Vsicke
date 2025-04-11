int x_ball = 64;
int y_ball = 32;

int speedX = 1;
int speedY = 1;

int r = 4;


void set_data() {
  x_ball = 64;
  y_ball = 32;
  speedX = 1;
  speedY = 1;
}

void plusSpeed(int sum_CH) {
  if (speedX < 0) {
    speedX += -sum_CH;
    speedY += -sum_CH;
  }
  if (speedX > 0) {
    speedX += sum_CH;
    speedY += sum_CH;
  }
}

// ball
int sum = 0;

bool flag_X = false;
bool flag_Y = false;



void ball() {

  int button = 1;

  x_ball += speedX;
  y_ball += speedY;

  if (x_ball <r || x_ball > 128-r)
  {
    speedX = -speedX;
    flag_X = true;
  }
  else{
    flag_X = false;
  }

  if (y_ball <r || y_ball > 64-r) { 
    speedY = -speedY; 
    flag_Y = true;
  }
  else{ 
    flag_Y = false;
  }

  display.clearDisplay();
  display.drawCircle(x_ball, y_ball, r, WHITE);

  if (flag_X && flag_Y) {
    sum += 1;
  }

  display.setCursor(0, 0);
  display.println(sum);


  display.display();




  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
  

}

//pinball

int player = 0;
int robot = 0;

int playerY = 0;
int playerX = 6;

int RS = 15;

int robotY = y_ball-4;
int robotX = 122;

void pinball() {
  int button = 1;

  bool up = !digitalRead(2);
  bool bown = !digitalRead(0);

  x_ball += speedX;
  y_ball += speedY;

  if (x_ball <r)
  {
    robot += 1;
    set_data();
  }
  if (x_ball > 128-r) {
    player += 1;
    set_data();
  }


  if (y_ball <r || y_ball > 64-r) { 
    speedY = -speedY; 
  }

  if (bown) {
    playerY += 2;
  }
  if (up) {
    playerY -= 2;
  }

  if (playerY < 0) {
    playerY = 0;
  }
  if (playerY > 54) {
    playerY = 54;
  }

  if (y_ball -r < playerY + RS&& y_ball +r > playerY+1) { 
    if (x_ball - r < playerX+1) {
      speedX = -speedX; 
    }
  }

  if (x_ball > 128-r*2-3) {
    speedX = -speedX; 
  }


  display.clearDisplay();
  
  display.drawLine(playerX, playerY, playerX, playerY + RS, WHITE);

  display.drawLine(robotX, y_ball-r-3, robotX, y_ball-r-3 + RS, WHITE);

  display.drawCircle(x_ball, y_ball, r, WHITE);

  display.setCursor(54, 1);
  display.println(player);

  display.setCursor(74, 1);
  display.println(robot);



  display.display();




  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
  

}
