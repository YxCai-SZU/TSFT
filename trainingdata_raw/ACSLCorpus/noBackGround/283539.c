#include <limits.h>

/*@
    requires ((a) * (a) <= INT_MAX &&
        (b) * (b) <= INT_MAX &&
        (a) * (a) + (b) * (b) <= INT_MAX);
    ensures \result == ((a) * (a) + (b) * (b));
    assigns \nothing;
*/
int sum_of_squares(int a, int b) {
    int a_square;
    int b_square;
    int result;

    //@ assert a * a <= INT_MAX;
    //@ assert a * a >= 0;
    a_square = a * a;

    //@ assert b * b <= INT_MAX;
    //@ assert b * b >= 0;
    b_square = b * b;

    //@ assert (long long)a_square + (long long)b_square <= INT_MAX;
    //@ assert (long long)a_square + (long long)b_square >= 0;
    result = a_square + b_square;

    return result;
}
