#include <limits.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == n * 800 - (n / 15) * 200;
    ensures 600 <= \result && \result <= 80000;
*/
int func(int n)
{
    int result;
    int count;
    int temp;
    int divisor;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    result = n * 800;
    count = 0;
    temp = n;
    divisor = 15;
    
    //@ assert ((n) * 800) == n * 800;
    //@ assert (((n) / 15) * 200) == (n / 15) * 200;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant temp == n - count * divisor;
        loop invariant result == n * 800;
        loop invariant divisor == 15;
        loop invariant count * 200 <= n * 800;
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        count += 1;
        
        //@ assert count * 200 <= n * 800;
    }
    
    //@ assert 0 <= count * 200 && count * 200 <= n * 800;
    result = result - count * 200;
    
    //@ assert count == n / 15;
    //@ assert result == n * 800 - (n / 15) * 200;
    
    //@ assert n * 800 <= 100 * 800;
    //@ assert (n / 15) * 200 <= 100 * 200;
    //@ assert n * 800 >= 1 * 800;
    //@ assert (n / 15) * 200 >= 0 * 200;
    
    //@ assert ((((n)) * 800) - ((((n)) / 15) * 200)) == result;
    return result;
}
