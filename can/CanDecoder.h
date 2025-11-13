#include <cstdint>
#include <map>
#include <string>
#include <linux/can.h>

struct can_1512{
    float tps;
    float clt;
    uint16_t rpm;
    float map;
};

struct can_1513{
    float adv_deg;
    float mat;
    float pw2;
    float pw1;
};

struct can_1514{
    float pwseq1;
    float egt1;
    float egocor1;
    float AFR1;
    float afrtgt1;
};

struct can_1515{
    float knk_rtd;
    float sensors2;
    float sensors1;
    float batt;
};

struct can_1516{
    float launch_timing;
    float tc_retard;
    float VSS1;
};

//Requires advanced can data

struct can_1520{
    uint16_t seconds;
    float pw1;
    float pw2;
    uint16_t rpm;
}

struct can_1521{
    float adv_deg;
    uint8_t squirt;
    uint8_t engine;
    uint8_t afrtgt1;
    uint8_t afrtgt2;
    uint8_t wbo2_en1;
    uint8_t wbo_en2;
}

struct can_1522{
    float baro;
    float map;
    float mat;
    float clt;
}

struct can_1523{
    float tps;
    float batt;
    float afr1_old;
    float afr2_old;
}

struct can_1524{
    float knock;
    float egocor1;
    float egocor2;
    float aircor;
}

struct can_1525{
    float warmcor;
    float tpsaccel;
    float tpsfuelcut;
    float barocor;
}

struct can_1526{
    float totalcor;
    float ve1;
    float ve2;
    float iavstep;
}

struct can_1527{
    float cold_adv_deg;
    uint8_t TPSdot;
    uint8_t MAPdot;
    float RPMdot;
}

struct can_1528{
    float MAFload;
    float fuelload;
    float fuelcor;
    float MAF;
}

struct can_1529{
    float egoV1;
    float egoV2;
    float dwell;
    float dwell_trl;
}

struct can_1530{
    uint8_t status1;
    uint8_t status2;
    uint8_t status3;
    uint8_t status4;
    uint8_t status5;
    uint8_t status6;
    uint8_t status7;
}

struct can_1531{
    float fuelload2;
    float ignload;
    float ifnload2;
    float airtemp;
}

struct can_1532{
    double wallfuel1;
    double wallfuel2;
}

struct can_1533{
    float sensor1;
    float sensor2;
    float sensor3;
    float sensor4;
}

struct can_1534{
    float sensor5;
    float sensor6;
    float sensor7;
    float sensor8;
}

struct can_1535{
    float sensor9;
    float sensor10;
    float sensor11;
    float sensor12;
}

struct can_1536{
    float sensor13;
    float sensor14;
    float sensor15;
    float sensor16;
}

class CanDecoder {
    public:
        static uint8_t decode1512(uint8_t data[], can_1512* decodedData);
        static uint8_t decode1513(uint8_t data[], can_1513* decodedData);
        static uint8_t decode1514(uint8_t data[], can_1514* decodedData);
        static uint8_t decode1515(uint8_t data[], can_1515* decodedData);
        static uint8_t decode1516(uint8_t data[], can_1516* decodedData);

        //these are not being used 
        // static uint8_t decode1520(uint8_t data[], can_1520* decodedData);
        // static uint8_t decode1521(uint8_t data[], can_1521* decodedData);
        // static uint8_t decode1522(uint8_t data[], can_1522* decodedData);
        // static uint8_t decode1523(uint8_t data[], can_1523* decodedData);
        // static uint8_t decode1524(uint8_t data[], can_1524* decodedData);
        // static uint8_t decode1525(uint8_t data[], can_1525* decodedData);
        // static uint8_t decode1526(uint8_t data[], can_1526* decodedData);
        // static uint8_t decode1527(uint8_t data[], can_1527* decodedData);
        // static uint8_t decode1528(uint8_t data[], can_1528* decodedData);
        // static uint8_t decode1529(uint8_t data[], can_1529* decodedData);
        // static uint8_t decode1530(uint8_t data[], can_1530* decodedData);
        // static uint8_t decode1531(uint8_t data[], can_1531* decodedData);
        // static uint8_t decode1532(uint8_t data[], can_1532* decodedData);
        // static uint8_t decode1533(uint8_t data[], can_1533* decodedData);
        // static uint8_t decode1534(uint8_t data[], can_1534* decodedData);
        // static uint8_t decode1535(uint8_t data[], can_1535* decodedData);
        // static uint8_t decode1536(uint8_t data[], can_1536* decodedData);

        static uint8_t decode_can_frame(can_frame* frame, std::map<std::string,float>* decodedData);

    private:
        static uint8_t decode1512(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1513(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1514(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1515(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1516(uint8_t data[], std::map<std::string,float>* decodedData);

        static uint8_t decode1520(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1521(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1522(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1523(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1524(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1525(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1526(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1527(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1528(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1529(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1530(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1531(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1532(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1533(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1534(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1535(uint8_t data[], std::map<std::string,float>* decodedData);
        static uint8_t decode1536(uint8_t data[], std::map<std::string,float>* decodedData);
};
