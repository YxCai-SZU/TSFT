#include <stdbool.h>

/*@
    requires (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
        (1 <= ((a)[0]) <= 100) && (1 <= ((a)[1]) <= 100) && (1 <= ((a)[2]) <= 100)) && (\valid((b)) && \valid((b)+1) && \valid((b)+2) &&
        (1 <= ((b)[0]) <= 100) && (1 <= ((b)[1]) <= 100) && (1 <= ((b)[2]) <= 100));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int *a, int *b) {
    int result = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant result >= 0;
        loop invariant (\valid((a)) && \valid((a)+1) && \valid((a)+2) &&
        (1 <= ((a)[0]) <= 100) && (1 <= ((a)[1]) <= 100) && (1 <= ((a)[2]) <= 100)) && (\valid((b)) && \valid((b)+1) && \valid((b)+2) &&
        (1 <= ((b)[0]) <= 100) && (1 <= ((b)[1]) <= 100) && (1 <= ((b)[2]) <= 100));
        loop invariant result <= index * 100;
        loop assigns result, index;
        loop variant 3 - index;
    */
    while (index < 3) {
        //@ assert (1 <= (a[index]) <= 100) && (1 <= (b[index]) <= 100);
        
        if (a[index] > b[index]) {
            result += a[index] - b[index];
        } else {
            result += b[index] - a[index];
        }
        index += 1;
    }
    
    //@ assert result >= 0;
    return result;
}
