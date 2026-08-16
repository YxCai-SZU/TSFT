#include <stdbool.h>

/*@
    requires (1 <= (h) <= 10000 && 1 <= (a) <= 10000);
    ensures \result >= h / a;
    ensures h % a == 0 ==> \result == h / a;
    ensures h % a != 0 ==> \result == h / a + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int h, unsigned int a)
{
    unsigned int ans;
    //@ assert (1 <= (h) <= 10000 && 1 <= (a) <= 10000);
    ans = h / a;
    //@ assert ans == h / a;
    if (h % a != 0)
    {
        //@ assert h % a != 0;
        ans = ans + 1;
        //@ assert ans == h / a + 1;
    }
    //@ assert ans == ((h) % (a) == 0 ? (h) / (a) : (h) / (a) + 1);
    return ans;
}
