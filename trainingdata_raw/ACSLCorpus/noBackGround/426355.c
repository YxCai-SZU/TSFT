#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int precision_factor;
    int pi;
    int result;
    int final_result;
    int temp_result;
    
    precision_factor = 1000;
    pi = 3142;
    result = 2 * r * pi;
    final_result = 0;
    temp_result = result;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant precision_factor == 1000;
        loop invariant pi == 3142;
        loop invariant result == 2 * r * pi;
        loop invariant final_result * precision_factor + temp_result == result;
        loop invariant 0 <= final_result;
        loop invariant 0 <= temp_result;
        loop assigns temp_result, final_result;
        loop variant temp_result;
    */
    while (temp_result >= precision_factor)
    {
        temp_result -= precision_factor;
        final_result += 1;
    }
    
    //@ assert final_result * precision_factor + temp_result == result;
    //@ assert final_result == 2 * r * 3142 / 1000;
    
    return final_result;
}
