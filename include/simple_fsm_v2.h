#ifndef SIMPLE_FSM_V2_H
#define SIMPLE_FSM_V2_H

// Simple fsm variant 2: fast, but consumes more memory than and less reliable than v1. The user must define all event reactions (even no reaction) otherwise crashes possible.

#include <fsm_common.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#define FSM_NO_TRANSITION {FSM_NULL_STATE, FSM_NO_EVENT_ACTION}

typedef struct fsm_transition_s
{
    fsm_state_t next_state;
    transition_action_t action;
} fsm_transition_t;

typedef struct state_machine_s
{
    fsm_state_t current_state;
    int events_count;
    const fsm_transition_t *transitions;
} state_machine_t;

const fsm_transition_t fsm_no_transition = FSM_NO_TRANSITION;

bool fsm_process_event(state_machine_t *fsm, fsm_event_t event, void *event_data)
{
    bool res = false;

    if (fsm && (event >= 0))
    {
        const fsm_transition_t *transition = fsm->transitions + (fsm->current_state * fsm->events_count) + event;
        if (memcmp(transition, &fsm_no_transition, sizeof(fsm_transition_t)))
        {
            if (transition->action)
                transition->action(event_data);

            fsm->current_state = transition->next_state;
            
            res = true;
        }
    }

    return res;
}

#endif