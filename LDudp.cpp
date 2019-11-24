/*
  LDudp.h - library for sending simple udp log - implementation
  started from Test.cpp example
  Copyright (c) 2019 Trip-g.com LLC.  All right reserved.
*/

// include nothing


// include this library's description file
#include "LDudp.h"

// include description files for other libraries used (if any)
WiFiUDP tg_udp;

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

LDudp::LDudp(IPAddress lip,IPAddress mlip, int lp, int mlp,IPAddress sip)
{
  // initialize this instance's variables
  _logip = lip;
  _multicastadd = mlip;
  _logport = lp;
  _multicastport = mlp;
  _selfip = sip;


  // do whatever is required to initialize the library

}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

uint8_t LDudp::logD_UDP(char data[], const char c_from[], char f_msg[])
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  if (!tg_udp.beginPacket(_logip, _logport)){
    Log.warning("FAILED! UDP beginpacket Called From:%S f_msg:%S" CR , c_from, f_msg);
    return 0;
  } 
  tg_udp.write(data);
  _ldu_status = tg_udp.endPacket();
  if (!_ldu_status) {
    Log.warning("FAILED! UDP endPacket Called From:%S f_msg:%S" CR , c_from, f_msg);
  } else {
    Log.notice("SUCCESS! UDP endPacket Called From:%S f_msg:%S" CR , c_from, f_msg);
  }
  return _ldu_status;
}


  // it can also call private functions of this library



uint8_t LDudp::logM_UDP(char data[], const char c_from[], char f_msg[])
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  tg_udp.beginPacketMulticast(_multicastadd, _multicastport, _selfip);
  tg_udp.print(data);
  return tg_udp.endPacket();
  // it can also call private functions of this library

}
// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library


