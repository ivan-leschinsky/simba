/**
 * @file inet/network_interface.h
 * @version 2.0.0
 *
 * @section License
 * Copyright (C) 2016, Erik Moqvist
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERSOCKTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * This file is part of the Simba project.
 */

#ifndef __INET_NETWORK_INTERFACE_H__
#define __INET_NETWORK_INTERFACE_H__

#include "simba.h"

#include "lwip/sys.h"
#include "lwip/ip.h"

struct network_interface_t {
    struct netif netif;
    struct inet_ip_addr_t ipaddr;
    struct inet_ip_addr_t netmask;
    struct inet_ip_addr_t gw;
    netif_init_fn init;
};

/**
 * Initialize the network_interface module.
 *
 * @return zero(0) or negative error code.
 */
int network_interface_module_init(void);

/**
 * Add given network interface to the IP stack.
 *
 * @param[in] netif_p Network interface to add.
 *
 * @return zero(0) or negative error code.
 */
int network_interface_add(struct network_interface_t *netif_p);

/**
 * Enable given network interface.
 *
 * @param[in] netif_p Network interface to enable.
 *
 * @return zero(0) or negative error code.
 */
int network_interface_enable(struct network_interface_t *netif_p);

#endif