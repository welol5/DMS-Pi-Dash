#include <cstdint>
#include <linux/can.h>

union can_1512{
    uint16_t *tps;
    uint16_t *clt;
    uint16_t *rpm;
    uint16_t *map;
};

struct can_1513{
    uint16_t *adv_deg;
    uint16_t *mat;
    uint16_t *pw2;
    uint16_t *pw1;
};

struct can_1514{
    uint16_t *pwseq1;
    uint16_t *egt1;
    uint16_t *egocor1;
    uint8_t *AFR1;
    uint8_t *afrtgt1;
};

struct can_1515{
    uint8_t *knk_rtd;
    uint16_t *sensors2;
    uint16_t *sensors1;
    uint16_t *batt;
};

struct can_1516{
    uint16_t *launch_timing;
    uint16_t *tc_retard;
    uint16_t *VSS1;
};

class CanDecoder {
    public:
        can_1512 decode1512(uint8_t data[]);
        can_1513 decode1513(uint8_t data[]);
        can_1514 decode1514(uint8_t data[]);
        can_1515 decode1515(uint8_t data[]);
        can_1516 decode1516(uint8_t data[]);
};
