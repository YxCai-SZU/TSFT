#include <limits.h>

/*@ requires (1 <= (n) <= 20 && 1 <= (m) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result >= 0;
    ensures \result == n * m - (a + b) || \result == 0;
    assigns \nothing;
*/
int func(int n, int m, int a, int b)
{
    int product;
    int sum;
    int result;

    //@ assert n * m <= 20 * 20;
    product = n * m;

    //@ assert a + b <= 50 + 50;
    sum = a + b;

    if (product > sum) {
        //@ assert product - sum >= 0;
        result = product - sum;
    } else {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == n * m - (a + b) || result == 0;
    return result;
}
