#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 0;
    ensures \result <= 1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    if ((a == b && a != c) || (a != b && a == c)) {
        ans = 1;
        //@ assert ans == (((a) == (b) && (a) != (c)) || ((a) != (b) && (a) == (c)) ? 1 :         ((a) == (b) && (b) == (c)) ? 0 : 1);
    } else if (a == b && b == c) {
        ans = 0;
        //@ assert ans == (((a) == (b) && (a) != (c)) || ((a) != (b) && (a) == (c)) ? 1 :         ((a) == (b) && (b) == (c)) ? 0 : 1);
    } else {
        ans = 1;
        //@ assert ans == (((a) == (b) && (a) != (c)) || ((a) != (b) && (a) == (c)) ? 1 :         ((a) == (b) && (b) == (c)) ? 0 : 1);
    }

    //@ assert ans >= 0 && ans <= 1;
    return ans;
}
