#ifndef STATES_H
#define STATES_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct StateM_Struct {
    bool s2;
    bool s1;
} StateMachine;

typedef struct StateM_In_Struct {
    bool a2;
    bool a1;
    bool b;
} StateIn;

typedef struct StateM_Out_Struct {
    bool q2;
    bool q1;
    bool o2;
    bool o1;
} StateOut;

/**
 * @brief evaluates a state machine given input in
 * @return output
 */
StateOut eval(StateMachine * sm, StateIn in) {
    StateOut out;
    bool a2 = in.a2;
    bool a1 = in.a1;
    bool b = in.b;
    bool s2 = sm->s2;
    bool s1 = sm->s1;

    bool q2, q1, o2, o1;

// SMLOGIC
	q2 = ((!a2) && (!a1) && (!b) && s2 && (!s1)) || ((!a2) && (!a1) && b && s2 && (!s1)) || ((!a2) && a1 && (!b) && (!s2) && (!s1)) || ((!a2) && a1 && b && (!s2) && s1) || (a2 && (!a1) && (!b) && (!s2) && s1) || (a2 && (!a1) && b && (!s2) && (!s1));
	q1 = ((!a2) && (!a1) && (!b) && (!s2) && s1) || ((!a2) && (!a1) && b && (!s2) && s1) || ((!a2) && a1 && (!b) && s2 && (!s1)) || ((!a2) && a1 && b && (!s2) && (!s1)) || (a2 && (!a1) && (!b) && (!s2) && (!s1)) || (a2 && (!a1) && b && s2 && (!s1));
	o2 = ((!a2) && (!a1) && (!b) && s2 && (!s1)) || ((!a2) && (!a1) && b && s2 && (!s1)) || ((!a2) && a1 && (!b) && s2 && (!s1)) || ((!a2) && a1 && b && s2 && (!s1)) || (a2 && (!a1) && (!b) && s2 && (!s1)) || (a2 && (!a1) && b && s2 && (!s1));
	o1 = ((!a2) && (!a1) && (!b) && (!s2) && s1) || ((!a2) && (!a1) && b && (!s2) && s1) || ((!a2) && a1 && (!b) && (!s2) && s1) || ((!a2) && a1 && b && (!s2) && s1) || (a2 && (!a1) && (!b) && (!s2) && s1) || (a2 && (!a1) && b && (!s2) && s1);
// SMLOGIC

    out.q2 = q2;
    out.q1 = q1;
    out.o2 = o2;
    out.o1 = o1;

    return out;
}

/**
 * @brief evaluate the state machine with given input, also update state
 * @return output
 */

 StateOut eval_up(StateMachine * sm, StateIn in) {
    StateOut out = eval(sm, in);
    sm->s1 = out.q1;
    sm->s2 = out.q2;
    return out;
 }

 /**
  * @brief StateInput constructor
  * @return state input
  */
 StateIn inp(bool a2, bool a1, bool b) {
    StateIn out;
    out.a1 = a1;
    out.a2 = a2;
    out.b = b;
    return out;
 }

 /**
  * @brief StateMachine constructor
  * @return pointer to the new state machine
  */

  StateMachine * createMachine(bool s2, bool s1) {
    StateMachine * out = (StateMachine *) malloc(sizeof(StateMachine));
    out->s2 = s2;
    out->s1 = s1;
  }

#endif