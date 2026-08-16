#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 3142 / 1000;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int precision_factor;
    int pi;
    int circumference;
    int result;
    
    precision_factor = 1000;
    pi = 3142;
    circumference = 2 * r * pi;
    result = 0;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant ((precision_factor) == 1000 && (pi) == 3142);
        loop invariant circumference >= 0;
        loop invariant result * precision_factor + circumference == 2 * r * pi;
        loop assigns circumference, result;
        loop variant circumference;
    */
    while (circumference >= precision_factor) {
        //@ assert circumference >= precision_factor;
        circumference -= precision_factor;
        result += 1;
    }
    
    //@ assert result * precision_factor + circumference == 2 * r * pi;
    //@ assert circumference < precision_factor;
    
    return result;
}
