/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    predicate pi_constant(integer pi) = pi == 31415;
    predicate divisor_constant(integer divisor) = divisor == 10000;
    predicate temp_nonnegative(integer temp) = temp >= 0;
    predicate division_invariant(integer circumference, integer temp, integer pi, integer r) = 
        circumference * 10000 + temp == 2 * pi * r;
    
    lemma division_correctness: 
        \forall integer r, pi, divisor, circumference, temp; 
        is_valid_range(r) && pi_constant(pi) && divisor_constant(divisor) && 
        temp_nonnegative(temp) && division_invariant(circumference, temp, pi, r) && 
        temp < divisor ==> circumference == 2 * 31415 * r / 10000;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 31415 * r / 10000;
*/
long func(long r) {
    long pi;
    long circumference;
    long temp;
    long divisor;
    
    pi = 31415;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = 10000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415;
        loop invariant divisor == 10000;
        loop invariant temp >= 0;
        loop invariant circumference * 10000 + temp == 2 * pi * r;
        loop assigns temp, circumference;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference == 2 * 31415 * r / 10000;
    return circumference;
}
