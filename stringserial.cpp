#include "stringserial.h"

nBlock_StringSerial::nBlock_StringSerial(PinName pinTX, PinName pinRX): _ser(pinTX, pinRX) {
    return;
}
void nBlock_StringSerial::triggerInput(uint32_t inputNumber, uint32_t value) { // inputNumber is ignored
    char * string_buf = (char *)(value);
	
	_ser.printf(string_buf);
}
void nBlock_StringSerial::endFrame(void) {
    if (_ser.readable()) {
        output[0] = _ser.getc();
        available[0] = 1;
    }
    return;
}

