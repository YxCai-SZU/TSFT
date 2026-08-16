/*@
    predicate valid_range(integer x) = 1 <= x && x <= 1000000000000000;
    predicate loop_inv(integer x_unsigned, integer temp, integer div) =
        0 <= temp <= x_unsigned &&
        0 <= div <= (x_unsigned - temp) / 11 &&
        x_unsigned == temp + 11 * div;
    logic integer final_result(integer div, integer temp) = 
        div * 2 + (temp == 0 ? 0 : 1);
*/

/*@
    requires valid_range(x);
    ensures \result >= 0;
    ensures \result <= x;
    assigns \nothing;
*/
long func(long x) {
    unsigned long x_unsigned;
    unsigned long div;
    unsigned long temp;
    
    x_unsigned = (x < 0) ? 0 : (unsigned long)x;
    div = 0;
    temp = x_unsigned;
    
    /*@
        loop invariant loop_inv(x_unsigned, temp, div);
        loop invariant valid_range(x);
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 11) {
        //@ assert temp >= 11;
        temp -= 11;
        div += 1;
    }
    
    long ret = (long)(div * 2 + (temp == 0 ? 0 : 1));
    //@ assert ret >= 0;
    //@ assert ret <= x;
    return ret;
}
