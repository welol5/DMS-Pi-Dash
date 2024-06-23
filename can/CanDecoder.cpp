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
    decodedData.adv_deg = (data[6] << 8) | (data[7]);
    decodedData.mat = (data[4] << 8) | (data[5]);
    decodedData.pw2 = (data[2] << 8) | (data[3]);
    decodedData.pw1 = (data[0] << 8) | (data[1]);
    return decodedData;
}

can_1514 CanDecoder :: decode1514(uint8_t data[]){
    can_1514 decodedData;
    decodedData.pwseq1 = (data[6] << 8) | (data[7]);
    decodedData.egt1 = (data[4] << 8) | (data[5]);
    decodedData.egocor1 = (data[2] << 8) | (data[3]);
    decodedData.AFR1 = (data[1]);
    decodedData.afrtgt1 = (data[0]);
    return decodedData;
}

can_1515 CanDecoder :: decode1515(uint8_t data[]){
    can_1515 decodedData;
    decodedData.knk_rtd = (data[7]);
    decodedData.sensors2 = (data[4] << 8) | (data[5]);
    decodedData.sensors1 = (data[2] << 8) | (data[3]);
    decodedData.batt = (data[0] << 8) | (data[1]);
    return decodedData;
}

can_1516 CanDecoder :: decode1516(uint8_t data[]){
    can_1516 decodedData;
    decodedData.launch_timing = (data[4] << 8) | (data[5]);
    decodedData.tc_retard = (data[2] << 8) | (data[3]);
    decodedData.VSS1 = (data[0] << 8) | (data[1]);
    return decodedData;
}
