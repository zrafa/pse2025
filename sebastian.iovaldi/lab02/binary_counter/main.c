
#include "utils.h"

int main(void)
{	
	init();
	unsigned char counter = 0;
	unsigned long frame = 0;
	while(not_pushed())
	{
		wait(1000);
		if(!((++frame)%50))
			set_leds((++counter)%16);
	}

	while(1);
}
