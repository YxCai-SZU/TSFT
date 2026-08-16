#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == c + a;
*/
int func(int a, int b, int c) {
    int result;
    int i;

    result = a + b;
    i = 0;

    /*@
        loop invariant 0 <= i <= 1;
        loop invariant result >= 0;
        loop invariant result <= a + b + c;
        loop invariant result == a + b || result == b + c || result == c + a;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns result, i;
        loop variant 1 - i;
    */
    while (i < 1) {
        //@ assert result == a + b || result == b + c || result == c + a;
        if (result > b + c) {
            result = b + c;
        }
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= 1;
        loop invariant result >= 0;
        loop invariant result <= a + b + c;
        loop invariant result == a + b || result == b + c || result == c + a;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns result, i;
        loop variant 1 - i;
    */
    while (i < 1) {
        //@ assert result == a + b || result == b + c || result == c + a;
        if (result > c + a) {
            result = c + a;
        }
        i += 1;
    }

    //@ assert result == a + b || result == b + c || result == c + a;
    return result;
}
