#ifndef SIMPLE_FSM_V1_H
#define SIMPLE_FSM_V1_H

// Simple fsm variant 1: A bit slow (state processing takes min. O(n) where n - current fsm state), consumes moderate memory and reliable.

#include "fsm_common.h"
#include <stddef.h>

typedef struct fsm_transition_s
{
    fsm_state_t from_state;
    fsm_event_t event;
    fsm_state_t to_state;
    transition_action_t transition_action;
} fsm_transition_t;

struct state_machine_s
{
    fsm_state_t current_state;
    const fsm_transition_t *transitions;
    size_t transitions_size;
};

bool fsm_v1_process_event(state_machine_t *fsm, fsm_event_t event, void *event_data);

#endif