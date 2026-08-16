#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (n / 1000 + 1) * 1000 - n;
    assigns \nothing;
*/
int func(int n)
{
    int res;
    int count;
    int temp;
    
    res = n;
    count = 0;
    temp = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= temp <= n;
        loop invariant temp == ((n) - 1000 * (count));
        loop invariant 0 <= count <= n / 1000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
    }
    
    //@ assert temp == ((n) - 1000 * (count));
    //@ assert count == n / 1000;
    
    res = (count + 1) * 1000 - n;
    
    //@ assert res == (((count) + 1) * 1000 - (n));
    //@ assert res == (n / 1000 + 1) * 1000 - n;
    
    return res;
}
