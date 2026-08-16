#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((numbers) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= *((numbers) + i) && *((numbers) + i) <= 100);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *numbers)
{
    int ans = 0;
    int sum = 0;
    int index = 0;

    /*@
        loop invariant (0 <= (index) && (index) <= (n) &&
        (sum) >= 0 &&
        (sum) <= (index) * 100 &&
        (ans) >= 0 &&
        (ans) <= (index) + 1);
        loop assigns index, sum, ans;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (x) && (x) <= 10000 &&         \valid((numbers) + (0 .. (n)-1)) &&         \forall integer i; 0 <= i < (n) ==> 1 <= *((numbers) + i) && *((numbers) + i) <= 100);
        sum += numbers[index];
        ans += 1;
        index += 1;

        //@ assert sum >= 0 && sum <= index * 100;
        if (sum > x)
        {
            break;
        }
    }
    //@ assert ans >= 0 && ans <= n + 1;
    return ans;
}
