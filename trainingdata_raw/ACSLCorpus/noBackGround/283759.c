#include <stdint.h>
#include <stdbool.h>

/*@
    requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    assigns \nothing;
    ensures \result <= n + 1;
    ensures \result >= 1;
*/
int64_t func(int64_t n, int64_t x, int64_t *numbers)
{
    int64_t ans;
    int64_t sum;
    int64_t i;
    int64_t a;

    ans = 1;
    sum = 0;
    i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        1 <= (ans) <= (i) + 1 &&
        (sum) <= (i) * 100 &&
        (((n)) >= 1 && ((n)) <= 100 &&
        \forall integer i; 0 <= i < ((n)) ==> ((numbers))[i] >= 1 && ((numbers))[i] <= 100) &&
        (x) >= 1 && (x) <= 10000);
        loop assigns i, ans, sum, a;
        loop variant n - i;
    */
    while (i < n)
    {
        a = numbers[i];
        sum = sum + a;

        //@ assert sum <= (i + 1) * 100;
        if (sum <= x)
        {
            ans = ans + 1;
        }

        i = i + 1;
    }

    //@ assert ans <= n + 1 && ans >= 1;
    return ans;
}
