#include <limits.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a * b;
    ensures \result == a * b || \result == 10000;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int x;
    int result;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100);
    
    //@ assert 0 <= a * b <= 10000;
    x = a * b;

    if (x > 10000)
    {
        //@ assert x > 10000;
        result = 10000;
    }
    else
    {
        //@ assert x <= 10000;
        result = x;
    }

    //@ assert result >= 0;
    //@ assert result <= a * b;
    //@ assert result == a * b || result == 10000;
    return result;
}

int main()
{
    return 0;
}
