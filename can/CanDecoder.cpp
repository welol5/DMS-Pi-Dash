#include <stdlib.h>
#include "CanDecoder.h"

can_1512 CanDecoder :: decode1512(uint8_t data[]){
    can_1512 decodedData;
    decodedData.tps = (data[6] << 8) | (data[7]);
    decodedData.clt = (data[4] << 8) | (data[5]);
    decodedData.rpm = (data[2] << 8) | (data[3]);
    decodedData.map = (data[0] << 8) | (data[1]);
    
//    decodedData.tps = (uint16_t*)&data[6];
//    decodedData.clt = (uint16_t*)&data[4];
//    decodedData.rpm = (uint16_t*)&data[2];
//    decodedData.map = (uint16_t*)&data[0];
    
    return decodedData;
}

can_1513 CanDecoder :: decode1513(uint8_t data[]){
    can_1513 decodedData;
    decodedData.adv_deg = (uint16_t*)&data[6];
    decodedData.mat = (uint16_t*)&data[4];
    decodedData.pw2 = (uint16_t*)&data[2];
    decodedData.pw1 = (uint16_t*)&data[0];
    return decodedData;
}

can_1514 CanDecoder :: decode1514(uint8_t data[]){
    can_1514 decodedData;
    decodedData.pwseq1 = (uint16_t*)&data[6];
    decodedData.egt1 = (uint16_t*)&data[4];
    decodedData.egocor1 = (uint16_t*)&data[2];
    decodedData.AFR1 = (uint8_t*)&data[1];
    decodedData.afrtgt1 = (uint8_t*)&data[0];
    return decodedData;
}

can_1515 CanDecoder :: decode1515(uint8_t data[]){
    can_1515 decodedData;
    decodedData.knk_rtd = (uint8_t*)&data[6];
    decodedData.sensors2 = (uint16_t*)&data[4];
    decodedData.sensors1 = (uint16_t*)&data[2];
    decodedData.batt = (uint16_t*)&data[0];
    return decodedData;
}

can_1516 CanDecoder :: decode1516(uint8_t data[]){
    can_1516 decodedData;
    decodedData.launch_timing = (uint16_t*)&data[4];
    decodedData.tc_retard = (uint16_t*)&data[2];
    decodedData.VSS1 = (uint16_t*)&data[0];
    return decodedData;
}
