#include <stdio.h>

enum state {
    STATE1,
    STATE2,
    STATE3,
};

struct transition {
    const enum state from_state;
    const enum state (*fnc_out)(const enum state, const enum state);
    const enum state (*fnc_in)(const enum state, const enum state);
    const enum state to_state;
};

const enum state transition_default(const enum state from, const enum state to)
{
    printf("Transition: %i -> %i\n", from, to);
    return to;
}

#define NSTATES 4
const enum state transition_table[][NSTATES] = 
{
    { STATE1, STATE1 },
    { STATE1, STATE2 },
    { STATE1, STATE3 },
    { STATE3, STATE1 },
};

const enum state transition_check(const enum state from, const enum state to)
{
    for (int i = 0; i < NSTATES; i++)
    {
        const enum state *transition = transition_table[i];
        if (transition[0] == transition[1])
            return to;
    }

    return from;
}

const enum state transition(const struct transition *t)
{
    const enum state from = t->from_state;
    const enum state to   = t->to_state;

    const enum state allowed_state = transition_check(from, to);
    if (allowed_state == to)
    {
        const enum state out_fnc_state = t->fnc_out(from, to);
        const enum state to_fnc_state = t->fnc_in(from, to);
        if (allowed_state != out_fnc_state || allowed_state != to_fnc_state)
            // Undo?
            return from;
        else
            return to;
    }
    else
        return from;    
}

int main(void)
{
    enum state state = STATE1;
    const struct transition t1 = 
    {
        .from_state = state,
        .to_state = STATE1,
        .fnc_out = transition_default,
        .fnc_in = transition_default,
    };
    state = transition(&t1);

    const struct transition t2 =
    {
        .from_state = state,
        .to_state = STATE3,
        .fnc_out = transition_default,
        .fnc_in = transition_default,
    };
    state = transition(&t2);

    const struct transition t3 =
    {
        .from_state = state,
        .to_state = STATE1,
        .fnc_out = transition_default,
        .fnc_in = transition_default,
    };

    state = transition(&t3);
    state = transition(&t1);

    printf("Done.\n");
    return 0;
}