#include <limits.h>

/*@ requires (1 <= (n) && (n) <= 100 &&
      0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    ensures 0 <= \result <= 100 * 100;
    ensures \result <= INT_MAX;
*/
int func(int n, int a) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 100 * 100;
    
    result = n * n - a;
    
    //@ assert result == ((n) * (n) - (a));
    //@ assert 0 <= result;
    //@ assert result <= 100 * 100;
    //@ assert result <= INT_MAX;
    
    return result;
}
