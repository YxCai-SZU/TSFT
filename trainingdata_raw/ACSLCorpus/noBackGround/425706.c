#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 10000);
    ensures \result == 1 <==> ((((a)) + ((b))) >= (c));
*/
int func(int a, int b, int c)
{
    int sum;
    int ans;

    sum = a + b;
    ans = 0;

    if (sum >= c)
    {
        ans = 1;
    }

    //@ assert ans == 1 <==> (a + b >= c);

    return ans;
}
