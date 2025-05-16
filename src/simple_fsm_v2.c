#include <lib/simple_state_machine/include/simple_fsm_v2.h>

const fsm_transition_t fsm_no_transition = FSM_NO_TRANSITION;

bool fsm_v2_process_event(state_machine_t *fsm, fsm_event_t event, void *event_data)
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