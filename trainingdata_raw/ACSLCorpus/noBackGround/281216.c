#include <limits.h>

/*@
    requires (2 <= (a) <= 100 && 2 <= (b) <= 100);
    ensures \result == (((a) * (b)) - ((a) + (b) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (2 <= (a) <= 100 && 2 <= (b) <= 100);
    
    //@ assert a + b - 1 <= 100 + 100 - 1;
    
    //@ assert 2 * 2 <= a * b <= 100 * 100;
    
    //@ assert (((a) * (b)) - ((a) + (b) - 1)) <= 100 * 100 - (100 + 100 - 1);
    
    return (a * b) - (a + b - 1);
}

int main()
{
    return 0;
}
