#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint16_t command;
uint16_t protocolInt;
uint16_t Adress;
String protocol;

int mouse = 2;

int screen = 0;

int scrol = 0;


int hh;
int mm;





void setup_oled() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;); // Don't proceed, loop forever
  }
}


void Menu() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(100, 0);
  display.println(hh + ":" + mm);
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 20);
  display.println("home_Control");
  display.setCursor(6, 30);
  display.println("Apps");
  display.setCursor(6, 40);
  display.println("CD card");
  display.setCursor(6, 50);
  display.println("Game");


  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
  

}



void Home_Control() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 20);
  display.println("PC");
  display.setCursor(6, 30);
  display.println("Led");
  display.setCursor(6, 40);
  display.println("fan");
  display.setCursor(6, 50);
  display.println("Exit");


  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
  
}


void Hack() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 20);
  display.println("IR");
  display.setCursor(6, 30);
  display.println("433mhz");
  display.setCursor(6, 40);
  display.println("NRF");
  display.setCursor(6, 50);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
  
}

void mhz433_menu() {
  int button = 3;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 20);
  display.println("RX");
  display.setCursor(6, 30);
  display.println("TX");
  display.setCursor(6, 40);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}


void mhz433_TX() {
  int button = 2;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");


  
  display.setCursor(6, 30);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}



void mhz433_RX() {
  int button = 2;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 30);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}


void IR_menu() {
  int button = 3;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");
  
  display.setCursor(6, 20);
  display.println("RX");
  display.setCursor(6, 30);
  display.println("TX");
  display.setCursor(6, 40);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}

void IR_RX() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");



  display.setCursor(6, 20);
  display.println(protocol);
  display.setCursor(40, 20);
  display.println("0x");
  display.setCursor(52, 20);
  display.println(Adress, HEX);
  display.setCursor(80, 20);
  display.println("0x");
  display.setCursor(92, 20);
  display.println(command, HEX);

  display.setCursor(6, 40);
  display.println("Replay");
  display.setCursor(6, 50);
  display.println("Exit");



  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}

void IR_TX() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");



  display.setCursor(6, 20);
  display.println("TV");
  display.setCursor(6, 30);
  display.println("Led");
  display.setCursor(6, 40);
  display.println("2_7");
  display.setCursor(6, 50);
  display.println("Exit");


  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}



void Attac_NRF() {
  int button = 1;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Runing ");
  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}

void CD_card_menu() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");



  display.setCursor(6, 50);
  display.println("Exit");


  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}

void Game_menu() {
  int button = 4;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");


  display.setCursor(6, 20);
  display.println("Ball");
  display.setCursor(6, 30);
  display.println("PinBall");

  
  display.setCursor(6, 50);
  display.println("Exit");


  display.display();

  if (mouse >button+1) {
    mouse = button+1;
  }
  if (mouse <2) {
    mouse = 2;
  }
}


void TV() {
  int button = 4;
  int scrol_N = 1;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(WiFi.localIP());
  display.setCursor(100, 0);
  display.println(scrol);
  display.setCursor(0, 5);
  display.println("_____________________");
  display.setCursor(0, 10 * mouse);
  display.println(">");

  if (scrol == 0) {
    button = 4;
    display.setCursor(6, 20);
    display.println("Exit");
    display.setCursor(6, 30);
    display.println("POWER");
    display.setCursor(6, 40);
    display.println("LOV+");
    display.setCursor(6, 50);
    display.println("LOW-");
  }
  if (scrol == 1) {
    button = 2;
    display.setCursor(6, 20);
    display.println("CH+");
    display.setCursor(6, 30);
    display.println("CH-");
  }




  display.display();

  if (mouse >button+1) {
    scrol += 1;
    mouse = button+1;
  }
  if (mouse <2) {
    scrol -= 1;
    mouse = 2;
  }

  if (scrol < 0) {
    scrol = 0;
  }
  if (scrol_N < scrol) {
    scrol = scrol_N;
  }
}







