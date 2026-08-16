#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a + b + c >= 20 || a + b + c >= 15);
*/
bool func(int a, int b, int c)
{
    int cnt;
    int sum;

    cnt = 0;
    sum = a + b + c;

    if (sum >= 20)
    {
        cnt = 1;
    }
    else if (sum >= 15)
    {
        cnt = 0;
    }
    else
    {
        cnt = -1;
    }

    //@ assert cnt == 1 || cnt == 0 || cnt == -1;

    return cnt == 1 || cnt == 0;
}
