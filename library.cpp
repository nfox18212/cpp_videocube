/*
 * library.cpp
 *
 *  Created on: Apr 27, 2024
 *      Author: nfox
 */



char *addrtostring(uint32_t addr) {
  // converts a address to a hexadecimal string to print it out - bounded with a max of 8 characters for a 4 byte address
  char *string = "";
  // first two characters are 0x
  uint8_t filter = 0xF;
  string[0] = '0';
  string[1] = 'x';

  int i = 0;
  for (i = 2; i < 9; i++) {
    uint32_t num = addr & filter;  // pull targeted nibble out
    num = num >> i;                // force it to be smallest nibble, so 0xA0 would turn into 0x0A
    char numc;                     // num but character verison
    if (num < 10) {
      numc = 0x30 + num;  // the ascii versions of 0-9 is 0x30 + 0-9
    } else if (10 <= num <= 15) {
      // here we need to use A-F, which will be 0x37 + num.  0xA + 0x37 = 0x41 for example
      numc = 0x37 + num;
    }
    string[i] = numc;
  }

  return string;
}


