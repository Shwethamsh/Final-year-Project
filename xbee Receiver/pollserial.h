#ifndef PSERIAL_H
#define PSERIAL_H

#include <inttypes.h>
#include "Print.h"

typedef struct {
	uint8_t head;
	uint8_t tail;
	unsigned char * buffer;
} rbuffer;

//define a void function() return type.
typedef void (*pt2Funct)();

class pollserial : public Print {
	public:
		pt2Funct begin(long);
		void end();
		uint8_t available(void);
		int read(void);
		void flush(void);
		virtual size_t write(uint8_t);	//		virtual void write(uint8_t);
		using Print::write; // pull in write(str) and write(buf, size) from Print
};

void USART_recieve();
#endif
