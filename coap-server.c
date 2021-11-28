#include "contiki.h"
#include "coap-engine.h"

#include "sys/log.h"
#define LOG_MODULE "CoAP Server"
#define LOG_LEVEL LOG_LEVEL_INFO

extern coap_resource_t res_battery;

PROCESS(coap_server, "CoAP Server");
AUTOSTART_PROCESSES(&coap_server);

PROCESS_THREAD(coap_server, ev, data)
{
    PROCESS_BEGIN();

    PROCESS_PAUSE();

    LOG_INFO("Starting the CoAP Server\n");
    coap_activate_resource(&res_battery, "system/battery");

    while (1) {
        PROCESS_WAIT_EVENT();
    }

    PROCESS_END();
}