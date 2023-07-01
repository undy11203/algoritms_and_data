#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Output.h"

void PrintSortGraph(TStack* stack) {
    while (stack) {
        printf("%d ", stack->value);
        TStack* ptr = stack;
        stack = stack->next;
        free(ptr);
    }
}
