#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (k) <= 100000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
 */
int func(size_t k)
{
    int a[7];
    size_t i;
    int m;
    int result;
    
    a[0] = 7;
    a[1] = 5;
    a[2] = 2;
    a[3] = 3;
    a[4] = 7;
    a[5] = 8;
    a[6] = 6;
    
    m = 0;
    i = 0;
    
    /*@ loop invariant (0 <= (i) <= (k) &&
     (m) <= 9 * (i) &&
     (7) == 7 &&
     1 <= (k) <= 100000);
        loop invariant 0 <= i <= k;
        loop invariant m <= 9 * i;
        loop assigns i, m;
        loop variant k - i;
     */
    while (i < 7 && i < k)
    {
        //@ assert i < 7;
        //@ assert i < k;
        m += a[i];
        i += 1;
    }
    
    if (m >= 20)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
