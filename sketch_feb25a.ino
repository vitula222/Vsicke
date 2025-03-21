#include <WiFi.h>
#include <Tcp.h>
#include <display.h>
#include <IR_send.h>



unsigned long timing;

bool b_1 = false;
bool b_2 = false;
bool b_3 = false;

void setup() {
  IrReceiver.begin(3);
  IrSender.begin(20);

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  pinMode(20, INPUT);



  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;); // Don't proceed, loop forever
  }

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
        Wifi_Connect("X", "X");
        return;
      }
      if (mouse == 3) {
        Wifi_Connect("X", "X");
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
void loop() {
  Control();

  if (screen == 0) {
    Menu();
  }
  if (screen == 1) {
    Home_Control();
  }
  if (screen == 2) {
    Hack();
  }
  if (screen == 3) {
    mhz433_menu();
  }
  if (screen == 4){
    mhz433_RX();
  }
  if (screen == 5){
    mhz433_TX();
  }
  if (screen == 6) {
    IR_menu();
  }
  if (screen == 7) {
    IR_RX();
    IRRead();
  }
  if (screen == 8) {
    CD_card_menu();
  }
  if (screen == 9) {
    Attac_NRF();
  }
  if (screen == 10) {
    IR_TX();
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

  bool btnState1 = !digitalRead(1);
  if (btnState1 && !b_2) {  // обработчик нажатия
    b_2 = true;
    if (screen == 0) {
      if (mouse == 2) {
        screen = 1;
        return;
      }
      if (mouse == 3) {
        screen = 2;
        return;
      }
      if (mouse == 4) {
        screen = 8;
        return;
      }
    }
    if (screen == 1) {
      if (mouse == 2) {
        Send("PC");
      }
      if (mouse == 3) {
        Send("led");
      }
      if (mouse == 4) {
        Send("fan");
      }
      if (mouse == 5) {
        screen = 0;
      }
    }
    if (screen == 2){
      if (mouse == 2) {
        screen = 6;
        return;
      }
      if (mouse == 3) {
        screen = 3;
        return;
      }
      if (mouse == 4) {
        screen = 9;
        return;
      }
      if (mouse == 5) {
        screen = 0;
        return;
      }
    }
    if (screen == 3) {
      if (mouse == 2) {
        //mySwitch.enableReceive(4); 
        screen = 4;
        return;
      }
      if (mouse == 3) {
        screen = 5;
        return;
      }
      if (mouse == 4) {
        screen = 0;
        return;
      }
    }
    if (screen == 4) {
      if (mouse == 3) {
        screen = 3;
        return;
      }
    }

    if (screen == 5) {
      if (mouse == 3) {
        screen = 3;
        return;
      }
    }

    if (screen == 6) {
      if (mouse == 2) {
        screen = 7;
        return;
      }
      if (mouse == 3) {
        screen = 10;
        return;
      }
      if (mouse == 4) {
        screen = 3;
        return;
      }
    }

    if (screen == 7) {
      if (mouse == 4) {
        IRReplay();
      }
      if (mouse == 5) {
        screen = 0;
        return;
      }
    }

    if (screen == 8) {
      if (mouse == 5) {
        screen = 0;
        return;
      }
    }
    if (screen == 9) {
      if (mouse == 2) {
        screen = 0;
        return;
      }
    }
    if (screen == 10) {
      if (mouse == 2) {
        Send_IR_NEC(0x4, 0x8);
        return;
      }
      if (mouse == 3) {
        Send_IR_NEC(0xB7A0, 0xE9);
        return;
      }
      if (mouse == 4) {
        Send_IR_NEC(0x1308, 0x60);
        return;
      }
      if (mouse == 5) {
        screen = 6;
        return;
      }
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



}

