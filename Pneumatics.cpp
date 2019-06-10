//
// Created by kirill on 15.02.19.
//

#include "Pneumatics.h"

uint16_t Pneumatics::regState = 0x0000;

Pneumatics::Pneumatics(SP::SerialPort *sp, std::string addr) :
CTRL_RA_153_16::ControllerRA153_16(sp, addr) {
    for(int i=0;i<VALVE_COUNT;i++){
       // states[i] = false;
    }
    setFreq(1000);
    disableFreq();
    //setRegister(0x0000);
    setRegister(regState);
    std::cout << std::hex << "0x" << getRegister() << "\n";
}

Pneumatics::~Pneumatics() {

}

void Pneumatics::setRegister(uint16_t reg) {
    command_packet.code = 'N';
    command_packet.data[0] = (char)(reg & 0xff);
    command_packet.data[1] = (char)((reg & 0xff00) >> 8);
    command_packet.data[2] = '0'; command_packet.data[3] = '1';
    SendCommand(&command_packet);
    enableFreq();
}

uint16_t Pneumatics::getRegister() {
    uint16_t retvalue = 0;
    char buffer[4];
    bzero(buffer,4);
    command_packet.code = 'R';
    strcpy(command_packet.data,"0000");
    // Send command and get data to buffer from device
    SendCommand(&command_packet,buffer,4);
    retvalue = (uint16_t)(buffer[0] & 0xff);
    retvalue|= (uint16_t)((buffer[1] & 0xff) << 8);
    return retvalue;
}

bool Pneumatics::getState(int number) {
    return ((regState >> number)&0xfffe) ? true : false;
}

void Pneumatics::setValve(int number, bool stat) {
    if(stat){
        regState |= (1<<number);
    }else{
        regState  &= ~(1<<number);
    }
    setRegister(regState);
}
