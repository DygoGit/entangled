/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __CIRI_CORE_H__
#define __CIRI_CORE_H__

#include "ciri/api/api.h"
#include "ciri/conf/conf.h"
#include "ciri/node.h"
#include "consensus/consensus.h"
#include "gossip/components/requester.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct core_s {
  bool running;
  ciri_conf_t config;
  iota_consensus_t consensus;
  requester_state_t transaction_requester;
  node_t node;
  iota_api_t api;
} core_t;

/**
 * Initializes a core
 *
 * @param core The core
 *
 * @return a status code
 */
retcode_t core_init(core_t *const core);

/**
 * Starts a core
 *
 * @param core The core
 *
 * @return a status code
 */
retcode_t core_start(core_t *const core);

/**
 * Stops a core
 *
 * @param core The core
 *
 * @return a status code
 */
retcode_t core_stop(core_t *const core);

/**
 * Destroys a core
 *
 * @param core The core
 *
 * @return a status code
 */
retcode_t core_destroy(core_t *const core);

#ifdef __cplusplus
}
#endif

#endif  // __CIRI_CORE_H__
