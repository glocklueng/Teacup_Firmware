#ifndef	_SERIAL_H
#define	_SERIAL_H

#include "config_wrapper.h"
#include	<stdint.h>


#ifdef USB_SERIAL
  #include "usb_serial.h"
  #define serial_init() usb_init()
  #define serial_rxchars() usb_serial_available()
  #define serial_popchar() usb_serial_getchar()
#else
  // initialise serial subsystem
  void serial_init(void);

  // return number of characters in the receive buffer,
  // and number of spaces in the send buffer
  uint8_t serial_rxchars(void);
  // uint8_t serial_txchars(void);

  // read one character
  uint8_t serial_popchar(void);
  // send one character
  void serial_writechar(uint8_t data);
#endif /* USB_SERIAL */

void serial_writestr(uint8_t *data);

// write from flash
void serial_writestr_F(const __flash char *data_F);

#endif	/* _SERIAL_H */
