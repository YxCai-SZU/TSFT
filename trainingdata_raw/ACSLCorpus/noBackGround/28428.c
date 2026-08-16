#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * (3141592)/ (1000000));
*/
int64_t func(uint64_t r)
{
    // Variable declarations at scope top
    int64_t result = 0;
    int64_t temp;
    const int64_t pi = 3141592;
    const int64_t divisor = 1000000;
    
    //@ assert pi == (3141592);
    //@ assert divisor == (1000000);
    
    temp = 2 * (int64_t)r * pi;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant pi == (3141592);
        loop invariant divisor == (1000000);
        loop invariant temp >= 0;
        loop invariant temp == 2 * (int64_t)r * pi - result * divisor;
        loop invariant result >= 0;
        loop invariant result <= (2 * (r) * (3141592)/ (1000000));
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        result += 1;
        //@ assert temp == 2 * (int64_t)r * pi - result * divisor;
    }
    
    //@ assert temp < divisor;
    //@ assert temp >= 0;
    
    // Apply the division property lemma
    //@ assert result * divisor + temp == 2 * (int64_t)r * pi;
    
    // Final verification
    //@ assert result == (2 * (r) * (3141592)/ (1000000));
    
    return result;
}
