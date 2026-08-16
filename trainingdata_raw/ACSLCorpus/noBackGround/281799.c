#include <limits.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - (((a) > (b) ? (a) : (b)) - ((a) < (b) ? (a) : (b)))) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int max_val;
    int ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    ans = c - (max_val - min_val);

    //@ assert ans == ((c) - (((a) > (b) ? (a) : (b)) - ((a) < (b) ? (a) : (b))));

    if (ans < 0) {
        //@ assert ans < 0;
        return 0;
    } else {
        //@ assert ans >= 0;
        return ans;
    }
}
