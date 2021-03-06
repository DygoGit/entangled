/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __CONSENSUS_SNAPSHOT_STATE_DELTA_H__
#define __CONSENSUS_SNAPSHOT_STATE_DELTA_H__

#include "common/errors.h"
#include "common/trinary/flex_trit.h"
#include "utils/hash_containers.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef hash_to_int_map_entry_t state_delta_entry_t;
typedef state_delta_entry_t *state_delta_t;

#define state_delta_add(delta, hash, value) hash_int_map_add(delta, hash, value)
#define state_delta_find(delta, hash, entry) \
  HASH_FIND(hh, delta, hash, FLEX_TRIT_SIZE_243, entry);
#define state_delta_destroy(delta) hash_int_map_free(delta)

int64_t state_delta_sum(state_delta_t const *const state);
retcode_t state_delta_add_or_sum(state_delta_t *const state,
                                 flex_trit_t const *const hash,
                                 int64_t const value);
retcode_t state_delta_add_or_replace(state_delta_t *const state,
                                     flex_trit_t const *const hash,
                                     int64_t const value);
retcode_t state_delta_create_patch(state_delta_t const *const state,
                                   state_delta_t const *const delta,
                                   state_delta_t *const patch);
retcode_t state_delta_apply_patch(state_delta_t *const state,
                                  state_delta_t const *const patch);
retcode_t state_delta_merge_patch(state_delta_t *const state,
                                  state_delta_t const *const patch);
bool state_delta_is_consistent(state_delta_t *const delta);

size_t state_delta_serialized_size(state_delta_t const *const delta);
retcode_t state_delta_serialize(state_delta_t const *const delta,
                                byte_t *const bytes);
retcode_t state_delta_deserialize(byte_t const *const bytes, size_t const size,
                                  state_delta_t *const delta);

#ifdef __cplusplus
}
#endif

#endif  // __CONSENSUS_SNAPSHOT_STATE_DELTA_H__
