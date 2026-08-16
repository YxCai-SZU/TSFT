#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int max_val;
    int sum_val;
    int ans;

    max_val = (a > b) ? a : b;
    sum_val = a + b;
    ans = INT_MAX;

    //@ assert ans == INT_MAX;

    if (ans < sum_val) {
        //@ assert ans == INT_MAX;
    } else {
        ans = sum_val;
    }
    //@ assert ans == sum_val || ans == INT_MAX;

    if (ans < max_val * 2 - 1) {
        //@ assert ans == sum_val || ans == INT_MAX;
    } else {
        ans = max_val * 2 - 1;
    }
    //@ assert ans == sum_val || ans == max_val * 2 - 1;

    //@ assert ans == ((((a)) + ((b)))) || ans == (2 * ((((a)) > ((b))) ? ((a)) : ((b))) - 1);

    return ans;
}
