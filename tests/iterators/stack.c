// Checks if the stack iterator can go back and forward in the stack without
// hitting invalid states or a null pointer. Check is done visually.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../src/stack.h"

STACK_GENERATE(s, stack, static, int)

int main(int argc, char const *argv[])
{
    size_t i;
    int r;

    // Initialize stack and add some elements
    stack *s = s_new(10);
    for (int i = 0; i < 10; i++)
        s_push(s, i);

    // Initialize iterator
    stack_iter iter;
    s_iter_new(&iter, s);

    // Make the iterator go back and forward
    for (int j = 0; j < 4; j++)
    {
        while (s_iter_next(&iter, &r, &i))
            printf("C[%2d] = %2d\n", i, r);
        printf("\n");
        while (s_iter_prev(&iter, &r, &i))
            printf("C[%2d] = %2d\n", i, r);
        printf("\n\n");
    }

    for (s_iter_tostart(&iter); !s_iter_end(&iter); /**/)
    {
        s_iter_next(&iter, &r, &i);
        printf("S[%2d] = %2d\n", i, r);
    }

    printf("\n");

    for (s_iter_toend(&iter); !s_iter_start(&iter); /**/)
    {
        s_iter_prev(&iter, &r, &i);
        printf("S[%2d] = %2d\n", i, r);
    }

    s_free(s);

    return 0;
}
