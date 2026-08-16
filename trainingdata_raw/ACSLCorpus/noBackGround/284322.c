/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int result;
    int final_result;
    int temp_result;
    int divisor;
    
    pi = 3142;
    result = 2 * r * pi;
    final_result = 0;
    temp_result = result;
    divisor = 1000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant result == 2 * r * pi;
        loop invariant final_result * divisor + temp_result == result;
        loop invariant 0 <= final_result;
        loop invariant 0 <= temp_result;
        loop assigns temp_result, final_result;
    */
    while (temp_result >= divisor)
    {
        temp_result -= divisor;
        final_result += 1;
    }
    
    //@ assert final_result * divisor + temp_result == result;
    //@ assert temp_result < divisor;
    
    return final_result;
}
