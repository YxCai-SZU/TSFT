#include <stdbool.h>

/*@
    requires x >= 1 && x <= 1000;
    ensures \result >= 0 && \result * 3 <= x;
    assigns \nothing;
*/
int func(int x)
{
    int q;
    int temp_x;
    int count;
    
    q = 0;
    temp_x = x;
    count = 0;
    
    /*@
        loop invariant ((temp_x) >= 0 && (count) >= 0 && (x) == (temp_x) + 3 * (count));
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x = temp_x - 3;
        count = count + 1;
        //@ assert ((temp_x) >= 0 && (count) >= 0 && (x) == (temp_x) + 3 * (count));
    }
    
    q = count;
    //@ assert ((q) >= 0);
    //@ assert q * 3 <= x;
    
    return q;
}
