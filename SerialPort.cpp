//
// Created by kirill on 15.02.19.
//

#include "SerialPort.h"
#include <iostream>
#include <mutex>

using namespace SP;

bool SerialPort::busy = false;

std::mutex mux;

SerialPort::SerialPort(const char *path) {
    sp = new boost::asio::serial_port(ios,path);
    sp->set_option(boost::asio::serial_port::baud_rate(baud_rate));
}

SerialPort::~SerialPort() {
    delete sp;
}

/* method for readwrite to controller */
void SerialPort::readwrite(char *req, char *res, size_t *size_req, size_t *size_res){
    //while(busy==true);
    //busy = true;

    mux.lock();
    // just sleep for wait device
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 200000000;  //200 ms delay
    nanosleep(&ts,NULL);

    std::cout << "send data\n";

    // request, return the number of write bytes
    if(*size_req!=0) *size_req = sp->write_some(boost::asio::buffer(req, *size_req));
    //if(*size_req!=0) sp->async_write_some(boost::asio::buffer(req, *size_req),handler);
    // responsabal, return the number of read bytes
    char tmp = '\x00';
    //sp->async_read_some(boost::asio::buffer(res, *size_res),handler);
    //sp->read_some(boost::asio::buffer(res, *size_res));


    for(int i=0;i<*size_res;i++){
        if(sp->read_some(boost::asio::buffer(&tmp, 1))<=0) break;
        //sp->async_read_some(boost::asio::buffer(&tmp, 1),handler);
        res[i] = tmp;
    }
    mux.unlock();
}


void SerialPort::handler(const boost::system::error_code &error, std::size_t bytes_transferred){
    std::cout << "bytes: " << bytes_transferred;
    return;
}

/* methods for set and get private baud_rate */
void SerialPort::setBaudRate(int br) {
    baud_rate = br;
    sp->set_option(boost::asio::serial_port::baud_rate(baud_rate));
}

int SerialPort::getBaudRate() {
    return baud_rate;
}

/* method for close port */
void SerialPort::Close(){
    sp->close();
}
