#include <stdbool.h>
/*@
    requires (1 <= (a) <= 123) && (1 <= (b) <= 123) && (1 <= (c) <= 123) &&
             (1 <= (d) <= 123) && (1 <= (e) <= 123);
    ensures \result >= 0 && \result <= 5;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int count = 0;

    //@ assert (1 <= (a) <= 123) && (1 <= (b) <= 123) && (1 <= (c) <= 123) && (1 <= (d) <= 123) && (1 <= (e) <= 123);
    if (a == 0) {
        count += 1;
    }
    //@ assert count >= 0 && count <= 1;
    if (b == 0) {
        count += 1;
    }
    //@ assert count >= 0 && count <= 2;
    if (c == 0) {
        count += 1;
    }
    //@ assert count >= 0 && count <= 3;
    if (d == 0) {
        count += 1;
    }
    //@ assert count >= 0 && count <= 4;
    if (e == 0) {
        count += 1;
    }
    //@ assert count >= 0 && count <= 5;

    int index = 0;
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant 0 <= count <= 5;
        loop invariant index >= 0 ==> count <= 5;
        loop assigns index, count;
        loop variant 5 - index;
    */
    while (index < 5)
    {
        //@ assert 0 <= index < 5;
        if ((index == 0 && a == 0) ||
            (index == 1 && b == 0) ||
            (index == 2 && c == 0) ||
            (index == 3 && d == 0) ||
            (index == 4 && e == 0)) {
            count -= 1;
        }
        //@ assert count >= -1 && count <= 5;
        index += 1;
        //@ assert count >= 0 && count <= 5;
    }
    //@ assert count >= 0 && count <= 5;
    return count;
}
