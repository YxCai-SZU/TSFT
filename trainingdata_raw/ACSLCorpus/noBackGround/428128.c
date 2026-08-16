#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
int func(int r) {
    int pi;
    int result;
    int adjusted_result;
    int temp_result;
    
    pi = 314;
    result = 2 * r * pi;
    adjusted_result = 0;
    temp_result = result;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant result == 2 * r * pi;
        loop invariant temp_result >= 0;
        loop invariant adjusted_result * 100 + temp_result == result;
        loop assigns adjusted_result, temp_result;
        loop variant temp_result;
    */
    while (temp_result >= 100) {
        //@ assert temp_result >= 100;
        adjusted_result += 1;
        temp_result -= 100;
    }
    
    //@ assert adjusted_result * 100 + temp_result == result;
    
    return adjusted_result;
}
