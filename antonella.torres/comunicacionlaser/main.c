

#include "laser.h"
int main(void)
{

while (1){


    // Inicializar el láser
    laser_init();

    sendByte(0xFF);
  
}
    return 0;
}