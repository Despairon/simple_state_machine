#ifndef FSM_COMMON_H
#define FSM_COMMON_H

#include <stdint.h>
#include <stdbool.h>

#define FSM_NO_EVENT_ACTION NULL
#define FSM_NULL_STATE ((fsm_state_t)-1)
#define FSM_NULL_EVENT ((fsm_event_t)-1)

typedef struct state_machine_s state_machine_t;
typedef uint16_t fsm_state_t;
typedef uint16_t fsm_event_t;
typedef void (*transition_action_t)(void*);

#endif