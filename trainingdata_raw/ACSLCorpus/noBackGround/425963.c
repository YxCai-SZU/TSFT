#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (a >= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int diff;
    bool result;

    diff = a - b;
    //@ assert ((diff) >= 0 ==> (a) >= (b));
    //@ assert ((diff) < 0 ==> (a) < (b));
    
    result = (a >= b);
    return result;
}

int main()
{
    return 0;
}
