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
    } else if(canID == 1520){
        retCode = decode1520(frame->data, decodedData);
    } else if(canID == 1521){
        retCode = decode1521(frame->data, decodedData);
    } else if(canID == 1522){
        retCode = decode1522(frame->data, decodedData);
    } else if(canID == 1523){
        retCode = decode1523(frame->data, decodedData);
    } else if(canID == 1524){
        retCode = decode1524(frame->data, decodedData);
    } else if(canID == 1525){
        retCode = decode1525(frame->data, decodedData);
    } else if(canID == 1526){
        retCode = decode1526(frame->data, decodedData);
    } else if(canID == 1527){
        retCode = decode1527(frame->data, decodedData);
    } else if(canID == 1528){
        retCode = decode1528(frame->data, decodedData);
    } else if(canID == 1529){
        retCode = decode1529(frame->data, decodedData);
    } else if(canID == 1530){
        retCode = decode1530(frame->data, decodedData);
    } else if(canID == 1531){
        retCode = decode1531(frame->data, decodedData);
    } else if(canID == 1532){
        retCode = decode1532(frame->data, decodedData);
    } else if(canID == 1533){
        retCode = decode1533(frame->data, decodedData);
    } else if(canID == 1534){
        retCode = decode1534(frame->data, decodedData);
    } else if(canID == 1535){
        retCode = decode1535(frame->data, decodedData);
    } else if(canID == 1536){
        retCode = decode1536(frame->data, decodedData);
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

//needs more work
uint8_t CanDecoder :: decode1520(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["seconds"] = ((data[6] << 8) | (data[7]));
    (*decodedData)["seconds_set"] = 1;
    (*decodedData)["pw1"] = ((data[4] << 8) | (data[5]))/1000.0;
    (*decodedData)["pw1_set"] = 1;
    (*decodedData)["pw2"] = ((data[2] << 8) | (data[3]))/1000.0;
    (*decodedData)["pw2_set"] = 1;
    (*decodedData)["rpm"] = ((data[0] << 8) | (data[1]));
    (*decodedData)["rpm_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1521(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["adv_deg"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["adv_deg_set"] = 1;
    (*decodedData)["squirt"] = (data[5]);
    (*decodedData)["squirt_set"] = 1;
    (*decodedData)["engine"] = (data[4]);
    (*decodedData)["engine_set"] = 1;
    (*decodedData)["afrtgt1"] = (data[3])/10.0;
    (*decodedData)["afrtgt1_set"] = 1;
    (*decodedData)["afrtgt2"] = (data[2])/10.0;
    (*decodedData)["afrtgt2_set"] = 1;
    (*decodedData)["wbo2_en1"] = | (data[1]);
    (*decodedData)["wbo2_en1_set"] = 1;
    (*decodedData)["wbo2_en2"] = (data[1]);
    (*decodedData)["wbo2_en2_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1522(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["baro"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["baro_set"] = 1;
    (*decodedData)["map"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["map_set"] = 1;
    (*decodedData)["mat"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["mat_set"] = 1;
    (*decodedData)["clt"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["clt_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1523(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["tps"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["tps_set"] = 1;
    (*decodedData)["batt"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["batt_set"] = 1;
    (*decodedData)["afr1_old"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["afr1_old_set"] = 1;
    (*decodedData)["afr2_old"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["afr2_old_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1524(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["knock"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["knock_set"] = 1;
    (*decodedData)["egocor1"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["egocor1_set"] = 1;
    (*decodedData)["egocor2"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["egocor2_set"] = 1;
    (*decodedData)["aircor"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["aircor_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1525(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["warmcor"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["warmcor_set"] = 1;
    (*decodedData)["tpsaccel"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["tpsaccel_set"] = 1;
    (*decodedData)["tpsfuelcut"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["tpsfuelcut_set"] = 1;
    (*decodedData)["barocor"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["barocor_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1526(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["totalcor"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["totalcor_set"] = 1;
    (*decodedData)["ve1"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["ve1_set"] = 1;
    (*decodedData)["ve2"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["ve2_set"] = 1;
    (*decodedData)["iacstep"] = ((data[0] << 8) | (data[1]));
    (*decodedData)["iacstep_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1527(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["cold_adv_deg"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["cold_adv_deg_set"] = 1;
    (*decodedData)["TPSdot"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["TPSdot_set"] = 1;
    (*decodedData)["MAPdot"] = ((data[2] << 8) | (data[3]));
    (*decodedData)["MAPdot_set"] = 1;
    (*decodedData)["RPMdot"] = ((data[0] << 8) | (data[1]));
    (*decodedData)["RPMdot_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1528(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["MAFload"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["MAFload_set"] = 1;
    (*decodedData)["fuelload"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["fuelload_set"] = 1;
    (*decodedData)["fuelcor"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["fuelcorset"] = 1;
    (*decodedData)["MAF"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["MAF_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1529(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["egoV1"] = ((data[6] << 8) | (data[7]))/100.0;
    (*decodedData)["egoV1_set"] = 1;
    (*decodedData)["egoV2"] = ((data[4] << 8) | (data[5]))/100.0;
    (*decodedData)["egoV2_set"] = 1;
    (*decodedData)["dwell"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["dwell_set"] = 1;
    (*decodedData)["dwell_trl"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["dwell_trl_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1530(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["status1"] = (data[7]);
    (*decodedData)["status1_set"] = 1;
    (*decodedData)["status2"] = (data[6]);
    (*decodedData)["status2_set"] = 1;
    (*decodedData)["status3"] = (data[5]);
    (*decodedData)["status3_set"] = 1;
    (*decodedData)["status4"] = (data[4]);
    (*decodedData)["status4set"] = 1;
    (*decodedData)["status5"] = (data[2] << 8 | (data[1]));
    (*decodedData)["status5_set"] = 1;
    (*decodedData)["status6"] = (data[1]);
    (*decodedData)["status6_set"] = 1;
    (*decodedData)["status7"] = (data[0]);
    (*decodedData)["status7_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1531(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["fuelload2"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["fuelload2_set"] = 1;
    (*decodedData)["ignload "] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["ignload _set"] = 1;
    (*decodedData)["ignload2"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["ignload2_set"] = 1;
    (*decodedData)["airtemp"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["airtemp_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1532(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["wallfuel1"] = ((data[4] << 24) | (data[5] << 16 |) | (data[6] << 8) | (data[7]))/100.0;
    (*decodedData)["wallfuel1_set"] = 1;
    (*decodedData)["wallfuel2"] = ((data[4] << 24) | (data[5] << 16 |) | (data[6] << 8) | (data[7]))/100.0;
    (*decodedData)["wallfuel2_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1533(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["sensors1"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["sensors1_set"] = 1;
    (*decodedData)["sensors2"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["sensors2_set"] = 1;
    (*decodedData)["sensors3"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["sensors3_set"] = 1;
    (*decodedData)["sensors4"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["sensors4_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1534(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["sensors5"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["sensors5_set"] = 1;
    (*decodedData)["sensors6"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["sensors6_set"] = 1;
    (*decodedData)["sensors7"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["sensors7_set"] = 1;
    (*decodedData)["sensors8"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["sensors8_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1535(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["sensors9"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["sensors9_set"] = 1;
    (*decodedData)["sensors10"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["sensors10_set"] = 1;
    (*decodedData)["sensors11"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["sensors11_set"] = 1;
    (*decodedData)["sensors12"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["sensors12_set"] = 1;
    return 0;
}

uint8_t CanDecoder :: decode1536(uint8_t data[], std::map<std::string,float>* decodedData){
    (*decodedData)["sensors13"] = ((data[6] << 8) | (data[7]))/10.0;
    (*decodedData)["sensors13_set"] = 1;
    (*decodedData)["sensors14"] = ((data[4] << 8) | (data[5]))/10.0;
    (*decodedData)["sensors14_set"] = 1;
    (*decodedData)["sensors15"] = ((data[2] << 8) | (data[3]))/10.0;
    (*decodedData)["sensors15_set"] = 1;
    (*decodedData)["sensors16"] = ((data[0] << 8) | (data[1]))/10.0;
    (*decodedData)["sensors16_set"] = 1;
    return 0;
}