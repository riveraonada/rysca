#ifndef _UDP_H
#define _UDP_H

#include "ipv4.h"
#include "ipv4_config.h"
#include "ipv4_route_table.h"

#include <timerms.h>
#include <stdio.h>
#include <stdlib.h>

#define UDP_HDR_LEN 8
#define UDP_OVER_IP_PROT 17


typedef struct {
	uint16_t port_src;
	uint16_t port_dst;
	uint16_t udp_len;
	uint16_t checksum;
}udp_header_t, * udp_header;

typedef struct 
{
	udp_header_t header;
	unsigned char payload [ETH_MTU - UDP_HDR_LEN];
}udp_datagram_t, * udp_datagram;


int udp_open( uint16_t port_src );

int udp_send( ipv4_addr_t dst, uint16_t target_port, unsigned char * payload, int len );

int udp_recv( ipv4_addr_t src, unsigned char * buffer, long int timeout, int * src_port);

uint16_t udp_checksum ( unsigned char * data, int len );

void udp_close();

#endif