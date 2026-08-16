#include <limits.h>

/*@
    requires INT_MIN <= a <= INT_MAX;
    requires INT_MIN <= b <= INT_MAX;
    requires INT_MIN <= c <= INT_MAX;
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c)) &&
        (\result) <= (a) && (\result) <= (b) && (\result) <= (c));
*/
int min_numbers(int a, int b, int c)
{
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;

    if (a <= b && a <= c) {
        //@ assert ((((a)) == (a) || ((a)) == (b) || ((a)) == (c)) &&         ((a)) <= (a) && ((a)) <= (b) && ((a)) <= (c));
        return a;
    } else if (b <= a && b <= c) {
        //@ assert ((((b)) == (a) || ((b)) == (b) || ((b)) == (c)) &&         ((b)) <= (a) && ((b)) <= (b) && ((b)) <= (c));
        return b;
    } else {
        //@ assert ((((c)) == (a) || ((c)) == (b) || ((c)) == (c)) &&         ((c)) <= (a) && ((c)) <= (b) && ((c)) <= (c));
        return c;
    }
}
