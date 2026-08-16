#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == (x >= 30);
    assigns \nothing;
 */
bool func(int x)
{
    // Variable declarations at top of scope
    int i = 0;
    
    //@ assert (1 <= (x) <= 100);
    
    /*@
        loop invariant 0 <= i <= 1000000;
        loop invariant (1 <= (x) <= 100);
        loop assigns i;
        loop variant 1000000 - i;
     */
    while (i < 1000000)
    {
        i = i + 1;
    }
    
    //@ assert (1 <= (x) <= 100);
    return x >= 30;
}

int main(void)
{
    return 0;
}
