#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100 &&
        (x) >= 0 && (x) <= (n) * 50 &&
        \valid((numbers) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 50);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *numbers)
{
    int ans = 1;
    int sum = 0;
    int i = 0;
    /*@
        loop invariant (0 <= (i) <= (n) &&
        1 <= (ans) <= (i) + 1 &&
        (sum) >= 0 &&
        (sum) <= (i) * 50 &&
        \forall integer j; 0 <= j < (i) ==> (numbers)[j] >= 1 && (numbers)[j] <= 50 &&
        (((n)) >= 1 && ((n)) <= 100 &&
        ((x)) >= 0 && ((x)) <= ((n)) * 50 &&
        \valid(((numbers)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> ((numbers))[i] >= 1 && ((numbers))[i] <= 50) &&
        (i) <= (n) &&
        ((sum) <= (x) ==> (ans) == (i) + 1));
        loop assigns i, ans, sum;
        loop variant n - i;
    */
    while (i < n)
    {
        int num = numbers[i];
        sum += num;
        if (sum <= x)
        {
            ans += 1;
        }
        else
        {
            break;
        }
        i += 1;
    }
    return ans;
}
