/*
  LDudp.h - library for sending simple udp log - implementation
  started from Test.cpp example
  Copyright (c) 2019 Trip-g.com LLC.  All right reserved.
*/

// ensure this library description is only included once
#ifndef LDudp_h
#define LDudp_h

// include types & constants WiFiUdp core API
#include "WiFiUdp.h"
#include <ArduinoLog.h>
// library interface description


class LDudp
{
  // user-accessible "public" interface
  public:
    LDudp(IPAddress lip = IPAddress(192,168,4,2),IPAddress mlip = IPAddress(224, 0, 1, 3), int lp = 239, int mlp = 8888, IPAddress sip = IPAddress(192,168,4,1));
    uint8_t logD_UDP(char data[], const char c_from[] = "Oh FUCK", char f_msg[] = "IT FAILED");
    uint8_t logM_UDP(char data[], const char c_from[] = "Oh FUCK", char f_msg[] = "IT FAILED");
  // library-accessible "private" interface
  private:
    IPAddress _logip;
    IPAddress _multicastadd;
    IPAddress _selfip;
    int _logport;
    int _multicastport;
    int _ldu_status;
};

#endif

