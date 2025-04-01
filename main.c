#include <stdio.h>
#include "states.h"

#define TEST_MACHINE true

int main(int argC, char * argV[]) {
    printf("Hello World\n");



    if (TEST_MACHINE) {
        printf("Enter initial s2s1: ");
        char vals[10];
        fgets(vals, 10, stdin);
        StateMachine * sm = createMachine(vals[0] == '1', vals[1] == '1');



        printf("Success! Loaded machine.\n");
        printf("Initial "); printMachine(sm);
        printf("q to exit\n");

        while (true) {
            printf("a2a1b: ");
            fgets(vals, 10, stdin);
            if (vals[0] == 'q') break;

            bool a2 = (vals[0] == '1') ? true : false;
            bool a1 = (vals[1] == '1') ? true : false;
            bool b = (vals[2] == '1') ? true : false;

            printf("\tPrev "); printMachine(sm);
            StateOut out = eval_up(sm, inp(a2, a1, b));
            printf("\t"); printMachine(sm);
            printf("\tOutpt: %c%c\n", (out.o2) ? '1' : '0', (out.o1) ? '1' : '0');
        }


        free(sm);
    }
}