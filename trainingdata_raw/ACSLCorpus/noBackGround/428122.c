#include <stdbool.h>

/*@
    requires 1 <= a <= 100 && 1 <= b <= 100;
    ensures \result >= 0 && \result <= a && \result <= b;
*/
int func(int a, int b)
{
    int min;
    int result;
    int i;
    bool divisible;
    int temp_a;
    int temp_b;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    
    //@ assert min == ((a) < (b) ? (a) : (b));
    
    result = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= min + 1;
        loop invariant result >= 0;
        loop invariant result <= a;
        loop invariant result <= b;
        loop invariant result <= i - 1;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop assigns i, result, divisible, temp_a, temp_b;
        loop variant min + 1 - i;
    */
    while (i < min + 1) {
        divisible = true;
        temp_a = a;
        temp_b = b;
        
        /*@
            loop invariant 0 <= temp_a <= a;
            loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
            loop invariant 1 <= i <= min + 1;
            loop invariant result >= 0 && result <= a && result <= b && result <= i - 1;
            loop assigns temp_a;
            loop variant temp_a;
        */
        while (temp_a >= i) {
            temp_a -= i;
        }
        
        //@ assert temp_a >= 0 && temp_a < i;
        
        if (temp_a != 0) {
            divisible = false;
        }
        
        /*@
            loop invariant 0 <= temp_b <= b;
            loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
            loop invariant 1 <= i <= min + 1;
            loop invariant result >= 0 && result <= a && result <= b && result <= i - 1;
            loop assigns temp_b;
            loop variant temp_b;
        */
        while (temp_b >= i) {
            temp_b -= i;
        }
        
        //@ assert temp_b >= 0 && temp_b < i;
        
        if (temp_b != 0) {
            divisible = false;
        }
        
        if (divisible) {
            result = i;
        }
        
        //@ assert ((1 <= ((a)) <= 100 && 1 <= ((b)) <= 100) &&         1 <= (i + 1) <= (min) + 1 &&         (result) >= 0 &&         (result) <= (a) &&         (result) <= (b) &&         (result) <= (i + 1) - 1);
        i += 1;
    }
    
    //@ assert result >= 0 && result <= a && result <= b;
    return result;
}
