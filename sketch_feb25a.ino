#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h> 
#include <Tcp.h>
#include <display.h>
#include <IR_send.h>




unsigned long timing;

bool b_1 = false;
bool b_2 = false;
bool b_3 = false;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800,60000);


void setup() {

  IrReceiver.begin(3);
  IrSender.begin(20);

  setup_oled();


  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  pinMode(20, INPUT);




  display.setTextSize(1);
  display.setTextColor(WHITE);


   // ---------------------------------------------------
  while (true) {
    int button = 3;
    if (mouse >button+1) {
      mouse = button+1;
    }
    if (mouse <2) {
      mouse = 2;
    }

    bool btnState2 = !digitalRead(2);
    if (btnState2 && !b_1) {  // обработчик нажатия
      b_1 = true;
      mouse -= 1;
    }
    if (!btnState2 && b_1) {  // обработчик отпускания
      b_1 = false;  
      //Serial.println("release");
    }

    bool btnState1 = !digitalRead(1);
    if (btnState1 && !b_2) {  // обработчик нажатия
      b_2 = true;
      if (mouse == 2) {
        Wifi_Connect("", "");
        timeClient.begin();
        timeClient.setTimeOffset(25200);
        return;
      }
      if (mouse == 3) {
        Wifi_Connect("", "");
        timeClient.begin();
        timeClient.setTimeOffset(25200);
        return;
      }
      if (mouse == 4) {
        return;
      }
    }
    if (!btnState1 && b_2) {  // обработчик отпускания
      b_2 = false;  
      //Serial.println("release");
    }

    bool btnState3 = !digitalRead(0);
    if (btnState3 && !b_3) {  // обработчик нажатия
      b_3 = true;
      mouse += 1;
    }
    if (!btnState3 && b_3) {  // обработчик отпускания
      b_3 = false;  
      //Serial.println("release");
    }

    display.clearDisplay();

    display.setCursor(6, 20);
    display.println("Home");
    display.setCursor(6, 30);
    display.println("Modile");
    display.setCursor(6, 40);
    display.println("No");

    display.setCursor(0, 10 * mouse );
    display.println(">");
    display.display();
  }
  //----------------------------------------------------------
}

bool btnState1 = false;

void loop() {
  Control();

  switch(screen)
  {
    case 0: 
        Menu();
        return;
    case 1: 
        Home_Control();
        return;
    case 2: 
        Hack();
        return;
    case 3: 
        mhz433_menu();
        return;
    case 4: 
        mhz433_RX();
        return;
    case 5: 
        mhz433_TX();
        return;
    case 6: 
        IR_menu();
        return;
    case 7:
        IR_RX();
        if (btnState1 == false) {
          IRRead();
        }
        else {
          delay(100);
        }
        return;
    case 8: 
        CD_card_menu();
        return;
    case 9: 
        Attac_NRF();
        return;
    case 10: 
        IR_TX();
        return;
    case 11: 
        Game_menu(); 
        return;
    case 12: 
        TV(); 
        return;
  }

}

void Wifi_Connect(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
  WiFi.setTxPower(WIFI_POWER_8_5dBm);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  } 
}

void Control() {  

  bool btnState2 = !digitalRead(2);
  if (btnState2 && !b_1) {  // обработчик нажатия
    b_1 = true;
    mouse -= 1;
  }
  if (!btnState2 && b_1) {  // обработчик отпускания
    b_1 = false;  
    //Serial.println("release");
  }

  btnState1 = !digitalRead(1);
  if (btnState1 && !b_2) {  // обработчик нажатия
    b_2 = true;
    screen_main();

  }
  if (!btnState1 && b_2) {  // обработчик отпускания
    b_2 = false;  
    //Serial.println("release");
  }

  bool btnState3 = !digitalRead(0);
  if (btnState3 && !b_3) {  // обработчик нажатия
    b_3 = true;
    mouse += 1;
  }
  if (!btnState3 && b_3) {  // обработчик отпускания
    b_3 = false;  
    //Serial.println("release");
  }



}

void time() {
  timeClient.update();

  hh = timeClient.getHours();
  mm = timeClient.getMinutes();
}

void screen_main() {
  if (screen == 0) {
    switch(mouse)
    {
      case 2: 
          screen = 1;
          return;
      case 3: 
          screen = 2;
          return;
      case 4: 
          screen = 8;
          return;
      case 5: 
          screen = 11;
          return;
    }
  }
  if (screen == 1) {
    switch(mouse)
    {
      case 2: 
          Send("");
          return;
      case 3: 
          Send("");
          return;
      case 4: 
          Send("");
          return;
      case 5: 
          screen = 0;
          return;
    }
  }
  if (screen == 2){
    switch(mouse)
    {
      case 2: 
          screen = 6;
          return;
      case 3: 
          screen = 3;
          return;
      case 4: 
          screen = 9;
          return;
      case 5: 
          screen = 0;
          return;
    }
  }
  if (screen == 3) {
    switch(mouse)
    {
      case 2: 
          screen = 4;
          return;
      case 3: 
          screen = 5;
          return;
      case 4: 
          screen = 2;
          return;
    }
  }
  if (screen == 4) {
    switch(mouse)
    {
      case 3: 
          screen = 3;
          return;
    }
  }

  if (screen == 5) {
    switch(mouse)
    {
      case 3: 
          screen = 3;
          return;
    }
  }

  if (screen == 6) {
    switch(mouse)
    {
      case 2: 
          screen = 7;
          return;
      case 3:
          screen = 10;
          return;
      case 4:
          screen = 3;
          return;

    }
  }

  if (screen == 7) {
    switch(mouse)
    {
      case 4: 
          IRReplay();
          return;
      case 5:
          screen = 6;
          return;
    }
  }

  if (screen == 8) {
    switch(mouse)
    {
      case 5: 
          screen = 0;
          return;
    }
  }

  if (screen == 9) {
    switch(mouse)
    {
      case 2: 
          screen = 0;
          return;
    }
  }

  if (screen == 10) {
    switch(mouse)
    {
      case 2: 
          //Send_IR_NEC(0x4, 0x8);
          screen = 12;
          return;
      case 3: 
          Send_IR_NEC(0xB7A0, 0xE9);
          return;
      case 4: 
          Send_IR_NEC(0x4E87, 0x17);
          return;
      case 5: 
          screen = 6;
          return;
    }
  }

  if (screen == 11) {

    switch(mouse)
    {
      case 5: 
          screen = 0;
          return;
    }
  }

  if (screen == 12) {
    if (scrol == 0) {
      switch(mouse)
      {
        case 2: 
            screen = 10;
            return;
        case 3: 
            Send_IR_NEC(0x4, 0x8);
            return;
        case 4: 
            Send_IR_NEC(0x4, 0x2);
            return;
        case 5: 
            Send_IR_NEC(0x4, 0x3);
            return;
      }
    }

    if (scrol == 1) {
      switch(mouse)
      {
        case 2: 
            Send_IR_NEC(0x4, 0x0);
            return;
        case 3: 
            Send_IR_NEC(0x4, 0x1);
            return;
      }
    }
  }
}


