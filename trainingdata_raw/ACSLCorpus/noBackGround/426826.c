#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
      1 <= (a) && (a) <= 50 &&
      1 <= (b) && (b) <= 50);
    ensures (\result == a * n || \result == b) && 
            \result >= 1 && 
            \result <= 1000;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t result;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    // Product bounds verification
    //@ assert a * n >= 1;
    //@ assert a * n <= 1000;
    
    if (a * n < b) {
        result = a * n;
        //@ assert result == a * n;
    } else {
        result = b;
        //@ assert result == b;
    }
    
    // Postcondition verification
    //@ assert result >= 1;
    //@ assert result <= 1000;
    
    return result;
}
