#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct i2c_msg_t {
        uint8_t rid;
    uint8_t cmd;
    uint8_t tid;
    uint16_t size;
    uint8_t cfg_id;
    uint8_t pckt_size;
    uint8_t pckt_num;
    uint8_t buf[5];
};


struct v_mode {

    struct mode_vtable const * ops;

    int32_t debug;

    void *priv;

};

struct mode_app {

    struct v_mode mode;

    // Volatile data of application
    struct volat_data {

        bool is_open;

        bool is_measuring;

        bool clk_corr_enabled;

        uint32_t irq;

//        struct clk_corr clk_cr;

//        struct msg msg;

        struct i2c_msg_t i2c_msg;

        uint32_t capture_num;

//        struct app_config cfg;

        uint8_t uid[sizeof(uint32_t)];

//        struct timespec timestamp;

    } volat_data;

};

#define member_of(ptr, type, member) \
    ((type *) ((uint8_t *)(ptr) - offsetof(type, member)))

static inline struct i2c_msg_t * to_i2cmsg(struct mode_app *app)
{
    return &app->volat_data.i2c_msg;
}
int main()
{
    struct i2c_msg_t *i2c_msg;
    struct mode_app *app;


    i2c_msg->size = 0;

    return 0;
}

