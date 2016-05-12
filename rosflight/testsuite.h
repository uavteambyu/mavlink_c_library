/** @file
 *	@brief MAVLink comm protocol testsuite generated from rosflight.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef ROSFLIGHT_TESTSUITE_H
#define ROSFLIGHT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_rosflight(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_rosflight(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_offboard_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_offboard_control_t packet_in = {
		17235,17339,17443,17547,29
    };
	mavlink_offboard_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.value1 = packet_in.value1;
        	packet1.value2 = packet_in.value2;
        	packet1.value3 = packet_in.value3;
        	packet1.value4 = packet_in.value4;
        	packet1.mode = packet_in.mode;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_offboard_control_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_offboard_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_offboard_control_pack(system_id, component_id, &msg , packet1.mode , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 );
	mavlink_msg_offboard_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_offboard_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 );
	mavlink_msg_offboard_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_offboard_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_offboard_control_send(MAVLINK_COMM_1 , packet1.mode , packet1.value1 , packet1.value2 , packet1.value3 , packet1.value4 );
	mavlink_msg_offboard_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_rosflight(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_offboard_control(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ROSFLIGHT_TESTSUITE_H
