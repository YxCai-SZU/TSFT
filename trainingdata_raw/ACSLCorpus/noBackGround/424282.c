#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == (800 * (n) - 200 * ((n) / 15));
*/
long long func(long long n)
{
    // Variable declarations at scope top
    long long res;
    long long count;
    long long temp_n;

    res = 800 * n;
    //@ assert res == 800 * n;
    
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 15;
        loop invariant res == 800 * n;
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
    */
    while (temp_n >= 15) {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
    }
    
    res = res - 200 * count;
    //@ assert res == 800 * n - 200 * count;
    
    return res;
}
