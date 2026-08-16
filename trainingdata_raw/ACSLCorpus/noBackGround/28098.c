#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && b != c) || (a == c && c != b) || (b == c && a != b));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    int ab;
    int ac;
    int bc;
    int sum;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    if (a == b) {
        ab = 1;
    } else {
        ab = 0;
    }
    //@ assert ab == (((a) == (b)) ? 1 : 0);

    if (a == c) {
        ac = 1;
    } else {
        ac = 0;
    }
    //@ assert ac == (((a) == (c)) ? 1 : 0);

    if (b == c) {
        bc = 1;
    } else {
        bc = 0;
    }
    //@ assert bc == (((b) == (c)) ? 1 : 0);

    sum = ab + ac + bc;

    if (sum == 1) {
        //@ assert (ab + ac + bc == 1);
        //@ assert ((a == b && b != c) || (a == c && c != b) || (b == c && a != b));
        return true;
    } else {
        //@ assert !((ab + ac + bc == 1));
        //@ assert !((a == b && b != c) || (a == c && c != b) || (b == c && a != b));
        return false;
    }
}
