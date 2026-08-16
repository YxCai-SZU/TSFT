#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures ((((a)) % 3 == 0) ||
        (((b)) % 3 == 0) ||
        (((a) + (b)) % 3 == 0)) ==> \result == 1;
    ensures !((((a)) % 3 == 0) ||
        (((b)) % 3 == 0) ||
        (((a) + (b)) % 3 == 0)) ==> \result == 0;
*/
int func(unsigned int a, unsigned int b)
{
    bool ans;
    int result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    ans = (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
    
    if (ans)
    {
        //@ assert ((((a)) % 3 == 0) ||         (((b)) % 3 == 0) ||         (((a) + (b)) % 3 == 0));
        result = 1;
    }
    else
    {
        //@ assert !((((a)) % 3 == 0) ||         (((b)) % 3 == 0) ||         (((a) + (b)) % 3 == 0));
        //@ assert 0 == 0;
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
