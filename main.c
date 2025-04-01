#include <stdio.h>
#include "states.h"

#define TEST_MACHINE true

int main(int argC, char * argV[]) {
    printf("Hello World\n");



    if (TEST_MACHINE) {
        printf("Enter initial s2s1: ");
        char vals[3];
        fgets(vals, 3, stdin);
        StateMachine * sm = createMachine(vals[0] == '1', vals[1] == '1');



        printf("Success! Loaded machine.\n");
        printf("Initial "); printMachine(sm);




        free(sm);
    }
}