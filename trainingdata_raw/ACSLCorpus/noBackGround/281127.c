#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int counter = 0;

    //@ ghost int old_counter = counter;

    if (a == b) {
        //@ assert a == b;
        counter += 1;
        //@ assert counter == old_counter + 1;
    }
    //@ assert counter == (a == b ? 1 : 0);

    //@ ghost old_counter = counter;
    if (a == c) {
        //@ assert a == c;
        counter += 1;
        //@ assert counter == old_counter + 1;
    }
    //@ assert counter == (a == b ? 1 : 0) + (a == c ? 1 : 0);

    //@ ghost old_counter = counter;
    if (b == c) {
        //@ assert b == c;
        counter += 1;
        //@ assert counter == old_counter + 1;
    }
    //@ assert counter == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);

    //@ assert counter == 1 <==> (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return counter == 1;
}
