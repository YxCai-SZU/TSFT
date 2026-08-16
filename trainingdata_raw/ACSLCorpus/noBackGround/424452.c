#include <limits.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result >= 0;
    ensures \result == A - 2 * B || \result == 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    //@ assert (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ans = A - 2 * B;
    
    if (ans < 0)
    {
        //@ assert ans < 0;
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        //@ assert ans >= 0;
        //@ assert ans == A - 2 * B;
    }
    
    //@ assert ans >= 0;
    //@ assert ans == A - 2 * B || ans == 0;
    return ans;
}

#ifdef TESTING
#include <assert.h>
int main()
{
    assert(func(10, 3) == 4);
    assert(func(6, 2) == 2);
    assert(func(100, 50) == 0);
    return 0;
}
#endif
