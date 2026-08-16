#include <stdbool.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int ans;

    //@ assert (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    
    result = c - a + b;
    
    if (result < 0)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = result;
        //@ assert ans == result;
    }
    
    //@ assert ans == ((((c)) - ((a)) + ((b))) < 0 ? 0 : (((c)) - ((a)) + ((b))));
    //@ assert ans >= 0;
    //@ assert ans <= a - b + c;
    
    return ans;
}
