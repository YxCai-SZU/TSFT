#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= x <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100 &&
      \forall integer i; 1 <= i < (n) ==> (a)[i] - (a)[i-1] >= 0);
    ensures \result >= 0;
    ensures \result <= n;
*/
long long func(long long n, long long m, long long x, long long* a) {
    long long res = 0;
    long long i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res >= 0;
        loop invariant res <= i;
        loop invariant res <= n;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        long long a_i = a[i];
        long long sub = (a_i < x) ? a_i : x;
        long long add = (a_i < x) ? (x - a_i) : 0;
        
        //@ assert 1 <= m * sub <= 100 * 100;
        long long prob = m * sub + (m - 1) * add;
        
        if (prob < m) {
            res += 1;
        }
        
        i += 1;
    }
    
    return res;
}
