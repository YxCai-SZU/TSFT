#include <limits.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val;
    int min_val;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);

    // Implementing max function manually
    if (c - a + b > 0) {
        max_val = c - a + b;
    } else {
        max_val = 0;
    }

    //@ assert max_val == (((c) - (a) + (b) > 0) ? ((c) - (a) + (b)) : 0);
    //@ assert max_val >= 0;

    // Implementing min function manually
    if (max_val < c) {
        min_val = max_val;
    } else {
        min_val = c;
    }

    //@ assert min_val == ((((((c)) - ((a)) + ((b)) > 0) ? (((c)) - ((a)) + ((b))) : 0) < (c)) ? ((((c)) - ((a)) + ((b)) > 0) ? (((c)) - ((a)) + ((b))) : 0) : (c));
    //@ assert min_val >= 0;
    //@ assert min_val <= c;

    return min_val;
}
