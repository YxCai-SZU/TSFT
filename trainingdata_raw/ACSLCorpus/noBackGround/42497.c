#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int i;
    bool break_occurred;
    
    i = 0;
    break_occurred = false;
    
    /*@
        loop invariant 0 <= i <= 100;
        loop invariant break_occurred == false || break_occurred == true;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100);
        loop assigns i, break_occurred;
        loop variant 100 - i;
    */
    while (i < 100)
    {
        if (i >= a)
        {
            break_occurred = true;
            break;
        }
        i = i + 1;
    }
    
    //@ assert 1 <= a * b <= 10000;
    
    return a * b;
}
