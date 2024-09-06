#include <stdlib.h>
#include "CanDecoder.h"

uint8_t CanDecoder :: decode1512(uint8_t data[], can_1512* decodedData){
    decodedData->tps = ((data[6] << 8) | (data[7]))/10.0;
    decodedData->clt = ((data[4] << 8) | (data[5]))/10.0;
    decodedData->rpm = (data[2] << 8) | (data[3]);
    decodedData->map = ((data[0] << 8) | (data[1]))/10.0;
    return 1;
}

uint8_t CanDecoder :: decode1513(uint8_t data[], can_1513* decodedData){
    decodedData->adv_deg = ((data[6] << 8) | (data[7]))/10.0;
    decodedData->mat = ((data[4] << 8) | (data[5]))/10.0;
    decodedData->pw2 = ((data[2] << 8) | (data[3]))/1000.0;
    decodedData->pw1 = ((data[0] << 8) | (data[1]))/1000.0;
    return 1;
}

uint8_t CanDecoder :: decode1514(uint8_t data[], can_1514* decodedData){
    decodedData->pwseq1 = ((data[6] << 8) | (data[7]))/1000.0;
    decodedData->egt1 = ((data[4] << 8) | (data[5]))/10.0;
    decodedData->egocor1 = ((data[2] << 8) | (data[3]))/10.0;
    decodedData->AFR1 = ((data[1]))/10.0;
    decodedData->afrtgt1 = ((data[0]))/10.0;
    return 1;
}

uint8_t CanDecoder :: decode1515(uint8_t data[], can_1515* decodedData){
    decodedData->knk_rtd = ((data[7]))/10.0;
    decodedData->sensors2 = ((data[4] << 8) | (data[5]))/100.0;
    decodedData->sensors1 = ((data[2] << 8) | (data[3]))/100.0;
    decodedData->batt = ((data[0] << 8) | (data[1]))/10.0;
    return 1;
}

uint8_t CanDecoder :: decode1516(uint8_t data[], can_1516* decodedData){
    decodedData->launch_timing = ((data[4] << 8) | (data[5]))/10.0;
    decodedData->tc_retard = ((data[2] << 8) | (data[3]))/10.0;
    decodedData->VSS1 = ((data[0] << 8) | (data[1]))/10.0;
    return 1;
}

uint8_t CanDecoder :: decode_can_frame(can_frame* frame, std::map<std::string,float>* decodedData){
    uint32_t canID = frame->can_id;
    uint8_t retCode;
    if(canID == 1512){
        retCode = decode1512(frame->data, decodedData);
    } else if(canID == 1513){
        retCode = decode1513(frame->data, decodedData);
    } else if(canID == 1514){
        retCode = decode1514(frame->data, decodedData);
    } else if(canID == 1515){
        retCode = decode1515(frame->data, decodedData);
    } else if(canID == 1516){
        retCode = decode1516(frame->data, decodedData);
    }
    return retCode;
}

uint8_t CanDecoder :: decode1512(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["tps"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["tps_set"] = 1;
    (*decodedData)["clt"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["clt_set"] = 1;
    (*decodedData)["rpm"] = (data[2] << 8) | (data[3]);
    (*decodedData)["rpm_set"] = 1;
    (*decodedData)["map"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["map_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1513(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["adv_deg"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["adv_deg_set"] = 1;
    (*decodedData)["mat"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["mat_set"] = 1;
    (*decodedData)["pw2"] = ((data[2] << 8) | (data[3]))/1000.0;
    (*decodedData)["pw2_set"] = 1;
    (*decodedData)["pw1"] = ((data[0] << 8) | (data[1]))/1000.0;
    (*decodedData)["pw1_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1514(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["pwseq1"] = ((data[6] << 8) | (data[7]))/1000.0;
    (*decodedData)["pwseq1_set"] = 1;
    (*decodedData)["egt1"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["egt1_set"] = 1;
    (*decodedData)["egocor1"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["egocor1_set"] = 1;
    (*decodedData)["AFR1"] = ((data[1]))/10.0;
    (*decodedData)["AFR1_set"] = 1;
    (*decodedData)["afrtgt1"] = ((data[0]))/10.0;
    (*decodedData)["afrtgt1_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1515(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["knk_rtd"] = ((data[7]))/10.0;
    (*decodedData)["knk_rtd_set"] = 1;
    (*decodedData)["sensors2"] = ((data[4] << 8) | (data[5]))/100.0;
    (*decodedData)["sensors2_set"] = 1;
    (*decodedData)["sensors1"] = ((data[2] << 8) | (data[3]))/100.0;
    (*decodedData)["sensors1_set"] = 1;
    (*decodedData)["batt"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["batt_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1516(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["launch_timing"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["launch_timing_set"] = 1;
    (*decodedData)["tc_retard"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["tc_retard_set"] = 1;
    (*decodedData)["VSS1"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["VSS1_set"] = 1;
    return 0;
}
