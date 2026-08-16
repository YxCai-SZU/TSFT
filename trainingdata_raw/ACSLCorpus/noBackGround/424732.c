#include <stdbool.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0 && \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int max_val;
    int d;
    int result;

    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);

    // Manual min calculation
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    // Manual max calculation
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    //@ assert min_val == ((a) < (b) ? (a) : (b));
    //@ assert max_val == ((a) > (b) ? (a) : (b));
    //@ assert min_val <= max_val;

    d = max_val - min_val + 1;

    if (d > c) {
        //@ assert d > c;
        result = 0;
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    } else {
        int min_val2;
        int max_val2;

        //@ assert d <= c;

        // Manual min calculation again
        if (d < c) {
            min_val2 = d;
        } else {
            min_val2 = c;
        }

        // Manual max calculation again
        if (d > c) {
            max_val2 = d;
        } else {
            max_val2 = c;
        }

        //@ assert min_val2 == ((d) < (c) ? (d) : (c));
        //@ assert max_val2 == ((d) > (c) ? (d) : (c));
        //@ assert min_val2 <= max_val2;

        result = c - d;
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    }
}
