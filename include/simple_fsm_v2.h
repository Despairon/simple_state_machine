#ifndef SIMPLE_FSM_V2_H
#define SIMPLE_FSM_V2_H

// Simple fsm variant 2: fast, but consumes more memory than and less reliable than v1. The user must define all event reactions (even no reaction) otherwise crashes possible.

#include "fsm_common.h"
#include <stddef.h>
#include <string.h>

#define FSM_NO_TRANSITION {FSM_NULL_EVENT, NULL}

typedef struct fsm_transition_s
{
    fsm_state_t next_state;
    transition_action_t action;
} fsm_transition_t;

struct state_machine_s
{
    fsm_state_t current_state;
    int events_count;
    const fsm_transition_t *transitions;
};

extern const fsm_transition_t fsm_no_transition;

bool fsm_v2_process_event(state_machine_t *fsm, fsm_event_t event, void *event_data);

#endif