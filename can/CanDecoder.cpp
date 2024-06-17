#include <stdlib.h>
#include "CanDecoder.h"

can_1512 CanDecoder :: decode1512(uint8_t data[]){
    can_1512 decodedData;
    decodedData.tps = (data[6] << 8) | (data[7]);
    decodedData.clt = (data[4] << 8) | (data[5]);
	decodedData.rpm = (data[2] << 8) | (data[3]);
    decodedData.map = (data[0] << 8) | (data[1]);
    return decodedData;
}

can_1513 CanDecoder :: decode1513(uint8_t data[]){

}

can_1514 CanDecoder :: decode1514(uint8_t data[]){

}

can_1515 CanDecoder :: decode1515(uint8_t data[]){

}

can_1516 CanDecoder :: decode1516(uint8_t data[]){

}