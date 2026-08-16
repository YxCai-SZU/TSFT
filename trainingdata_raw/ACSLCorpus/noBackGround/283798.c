/*@
    requires (1 <= (r) <= 100);
    ensures \result == (((r) * 2 * 3) / 1);
    assigns \nothing;
*/
long func(long r) {
    long pi;
    long result;
    long final_result;
    long temp_result;
    
    //@ assert (1 <= (r) <= 100);
    pi = 3;
    result = r * 2 * pi;
    
    final_result = 0;
    temp_result = result;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3;
        loop invariant result == r * 2 * pi;
        loop invariant final_result * 1 + temp_result == result;
        loop invariant 0 <= final_result;
        loop invariant 0 <= temp_result;
        loop assigns final_result, temp_result;
        loop variant temp_result;
    */
    while (temp_result >= 1) {
        //@ assert temp_result >= 1;
        final_result += 1;
        temp_result -= 1;
    }
    
    //@ assert final_result == (((r) * 2 * 3) / 1);
    return final_result;
}
