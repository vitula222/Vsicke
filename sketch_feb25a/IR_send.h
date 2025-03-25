#include <IRremote.hpp>

void Send_IR_NEC(uint16_t adress, uint16_t date) {
  IrSender.sendNEC(adress, date, 0);
}


void IRRead() {
  if (IrReceiver.decode()) {
    command = IrReceiver.decodedIRData.command;
    Adress = IrReceiver.decodedIRData.address;
    Date = IrReceiver.decodedIRData.decodedRawData;
    protocolInt = IrReceiver.decodedIRData.protocol;
    //Date = IrReceiver.decodedIRData.decodedRawData;
    switch(protocolInt)
    {
      case 1: 
          protocol = "NEC";
          break;
      case 2: 
          protocol = "SONY";
          break;
      case 3: 
          protocol = "RC5";
          break;
      case 4: 
          protocol = "RC6";
          break;
      case 5: 
          protocol = "DISH";
          break;
      case 6: 
          protocol = "SHARP";
          break;
      case 7: 
          protocol = "PANASONIC";
          break;
      case 8: 
          protocol = "NEC";
          break;
      case 9: 
          protocol = "SANYO";
          break;
      case 10: 
          protocol = "MITSUBISHI";
          break;
    }
    IrReceiver.resume();
    delay(300);
  }
  
}

void IRReplay() {

  switch(protocolInt)
  {
    case 1: 
        IrSender.sendNEC(Adress, command, 0);
        break;
    case 2: 
        IrSender.sendSony(Adress, command, 0);
        break;
    case 3: 
        IrSender.sendRC5(Adress, command, 0);
        break;
    case 4: 
        IrSender.sendRC6(Adress, command, 0);
        break;
    case 5: 
        IrSender.sendNEC(Adress, command, 0);
        break;
    case 6: 
        IrSender.sendSharp(Adress, command, 0);
        break;
    case 7: 
        IrSender.sendPanasonic(Adress, command, 0);
        break;
    case 8: 
        IrSender.sendNEC(Adress, command, 0);
        break;
    case 9: 
        IrSender.sendSony(Adress, command, 0);
        break;
    case 10: 
        IrSender.sendNEC(Adress, command, 0);
        break;
  }

  
}

