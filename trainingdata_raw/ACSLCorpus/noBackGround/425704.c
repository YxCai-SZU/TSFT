#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top of scope
    int sum;
    int result = 0;
    int count = 0;
    bool is_divisible = false;
    int i = 1;
    int remainder;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    sum = a + b;
    
    //@ assert 1 <= sum <= 200;
    
    /*@
        loop invariant 1 <= i <= sum + 1;
        loop invariant result >= 0;
        loop invariant result <= a;
        loop invariant sum == a + b;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop assigns i, remainder, is_divisible, result;
        loop variant sum - i + 1;
    */
    while (i <= sum) {
        remainder = sum;
        
        /*@
            loop invariant 0 <= remainder < i + sum;
            loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
            loop invariant 1 <= i <= sum + 1;
            loop invariant result >= 0;
            loop invariant result <= a;
            loop invariant sum == a + b;
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= i) {
            remainder -= i;
        }
        
        if (remainder == 0) {
            is_divisible = true;
            break;
        }
        i += 1;
    }
    
    if (is_divisible) {
        result = a;
    } else {
        result = a - 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a;
    return result;
}
