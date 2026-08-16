/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer division_result(integer x, integer divisor) = 
        (x / divisor) * divisor + x % divisor;
    
    lemma division_property: 
        \forall integer x, divisor; divisor > 0 ==> 
        division_result(x, divisor) == x;
*/

/*@
    requires valid_range(x);
    ensures \result == division_result(x, 3);
    ensures \result == x;
*/
int func(int x) {
    int quotient = 0;
    int remainder = x;
    int divisor = 3;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / divisor;
        loop invariant remainder == x - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
    }
    
    int result = quotient * divisor + remainder;
    
    //@ assert result == division_result(x, 3);
    //@ assert result == x;
    
    return result;
}
