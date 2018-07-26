/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentD.cpp
 * Author: Medley
 * 
 * Created on July 25, 2018, 1:18 PM
 */

#include <VentFunctions.h>

struct termios VentD(struct termios options,int stream) {
    tcgetattr(stream, &options);
    options.c_cflag = B19200 | CS7 | PARODD | CLOCAL | CREAD | PARENB | PARODD;
    options.c_iflag = IGNPAR; // IGNPAR ignores parity errors, not parity itself
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(stream, TCIFLUSH);
    tcsetattr(stream, TCSANOW, &options);
    return options;
}