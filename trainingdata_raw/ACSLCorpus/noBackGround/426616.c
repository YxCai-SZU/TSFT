#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> (500 * (k) >= (x));
*/
bool func(int k, int x)
{
    int sum;
    int max_value;
    int min_value;
    int diff;
    bool within_range;
    bool result;

    sum = 500 * k;

    //@ assert sum == 500 * k;

    if (sum > x) {
        max_value = sum;
    } else {
        max_value = x;
    }

    if (sum < x) {
        min_value = sum;
    } else {
        min_value = x;
    }

    if (sum > x) {
        diff = sum - x;
    } else {
        diff = x - sum;
    }

    within_range = diff <= 500;

    result = sum >= x;

    //@ assert result == true <==> (500 * (k) >= (x));

    return result;
}
