#include <lib/simple_state_machine/include/simple_fsm_v1.h>

bool fsm_v1_process_event(state_machine_t *fsm, fsm_event_t event, void *event_data)
{
    bool res = false;

    if (fsm)
    {
        size_t i = 0;
        for(; i < fsm->transitions_size; i++)
        {
            const fsm_transition_t *transition = fsm->transitions + i;

            if ((transition->from_state == fsm->current_state) && (transition->event == event))
            {
                if (transition->transition_action)
                    transition->transition_action(event_data);

                fsm->current_state = transition->to_state;

                res = true;

                break;
            }
        }
    }

    return res;
}