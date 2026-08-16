#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(long n)
{
    // Variable declarations at top of scope
    long counter = 0;
    long i = 1;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 100000 &&         1 <= (i) && (i) <= (n) + 1 &&         (counter) >= 0 &&         (counter) <= (i) - 1);
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100000 &&
        1 <= (i) && (i) <= (n) + 1 &&
        (counter) >= 0 &&
        (counter) <= (i) - 1);
        loop assigns counter, i;
        loop variant ((n) + 1 - (i));
    */
    while (i < n + 1)
    {
        //@ assert i == 7 || i == 5 || i == 3 ==> counter + 1 >= 0;
        if (i == 7 || i == 5 || i == 3)
        {
            counter += 1;
        }
        i += 1;
        //@ assert counter <= i - 1;
    }
    
    //@ assert n - counter == 0 || n - counter != 0;
    result = (n - counter == 0) ? 1 : 0;
    return result;
}
