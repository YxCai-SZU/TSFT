#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a + b + c || \result == a + b + d || 
            \result == a + c + d || \result == b + c + d;
*/
int func(int a, int b, int c, int d) {
    int max_value;
    int sum;
    int result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a > b) {
        if (a > c) {
            if (a > d) {
                max_value = a;
            } else {
                max_value = d;
            }
        } else {
            if (c > d) {
                max_value = c;
            } else {
                max_value = d;
            }
        }
    } else {
        if (b > c) {
            if (b > d) {
                max_value = b;
            } else {
                max_value = d;
            }
        } else {
            if (c > d) {
                max_value = c;
            } else {
                max_value = d;
            }
        }
    }

    sum = a + b + c + d;
    result = sum - max_value;

    //@ assert max_value == a || max_value == b || max_value == c || max_value == d;
    //@ assert sum == a + b + c + d;
    //@ assert result == sum - max_value;
    //@ assert result == a + b + c || result == a + b + d || result == a + c + d || result == b + c + d;

    return result;
}
