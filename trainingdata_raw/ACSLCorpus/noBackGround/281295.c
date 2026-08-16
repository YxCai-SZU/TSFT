#include <limits.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result >= 1 && \result <= 7;
    ensures ((x) % 7) == 0 ==> \result == 7;
    ensures ((x) % 7) != 0 ==> \result == 7 - ((x) % 7);
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    int temp_x;
    ans = 7;
    temp_x = x;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x <= 100000;
        loop invariant ((temp_x) % 7) == ((x) % 7);
        loop assigns temp_x;
    */
    while (temp_x >= 7)
    {
        temp_x = temp_x - 7;
    }

    if (temp_x != 0)
    {
        ans = ans - temp_x;
    }

    //@ assert ans == ((((x)) % 7) == 0 ? 7 : 7 - (((x)) % 7));
    return ans;
}
