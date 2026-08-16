#include <limits.h>

/*@
    requires (1 <= (A) && (A) <= 1000 &&
        1 <= (B) && (B) <= 1000 &&
        (A) + (B) <= (X) && (X) <= 10000);
    ensures \result >= 0;
    ensures \result <= B;
    assigns \nothing;
*/
int func(int X, int A, int B)
{
    int ans;
    
    //@ assert (1 <= (A) && (A) <= 1000 &&         1 <= (B) && (B) <= 1000 &&         (A) + (B) <= (X) && (X) <= 10000);
    
    if (X - A < 0)
    {
        ans = 0;
    }
    else
    {
        ans = X - A;
    }
    
    //@ assert ans == (((X) - (A) < 0) ? 0 : ((X) - (A)));
    
    if (ans > B)
    {
        ans = B;
    }
    
    //@ assert ans == ((((((X)) - ((A)) < 0) ? 0 : (((X)) - ((A)))) > (B)) ? (B) : ((((X)) - ((A)) < 0) ? 0 : (((X)) - ((A)))));
    //@ assert ans >= 0;
    //@ assert ans <= B;
    
    return ans;
}
