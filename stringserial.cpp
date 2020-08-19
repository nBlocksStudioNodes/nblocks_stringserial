#include "stringserial.h"

nBlock_StringSerial::nBlock_StringSerial(PinName pinTX, PinName pinRX): _ser(pinTX, pinRX) {
    return;
}
void nBlock_StringSerial::triggerInput(nBlocks_Message message) {
	_ser.printf(message.stringValue);
}
void nBlock_StringSerial::endFrame(void) {
    if (_ser.readable()) {
        output[0] = _ser.getc();
        available[0] = 1;
    }
    return;
}

