#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int i;
    
    // First loop
    i = 0;
    /*@
        loop invariant 0 <= i <= a;
        loop invariant (1 <= (a) <= 100);
        loop invariant (1 <= (b) <= 100);
        loop assigns i;
        loop variant a - i;
    */
    while (i < a)
    {
        //@ assert i <= a;
        i++;
    }
    
    // Second loop
    i = 0;
    /*@
        loop invariant 0 <= i <= b;
        loop invariant (1 <= (a) <= 100);
        loop invariant (1 <= (b) <= 100);
        loop assigns i;
        loop variant b - i;
    */
    while (i < b)
    {
        //@ assert i <= b;
        i++;
    }
    
    // Precondition assertions
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    
    result = a * b;
    return result;
}

int main()
{
    return 0;
}
