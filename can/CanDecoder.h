#include <cstdint>
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

class CanDecoder {
    public:
        static uint8_t decode1512(uint8_t data[], can_1512* decodedData);
        static uint8_t decode1513(uint8_t data[], can_1513* decodedData);
        static uint8_t decode1514(uint8_t data[], can_1514* decodedData);
        static uint8_t decode1515(uint8_t data[], can_1515* decodedData);
        static uint8_t decode1516(uint8_t data[], can_1516* decodedData);
};
