/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= h <= 100 && h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bounds: \forall integer a, b, h;
        valid_params(a, b, h) ==> 2 <= a + b <= 200;

    lemma product_bounds: \forall integer a, b, h;
        valid_params(a, b, h) ==> 2 <= (a + b) * h <= 20000;

    lemma division_bounds: \forall integer a, b, h;
        valid_params(a, b, h) ==> 1 <= (a + b) * h / 2 <= 10000;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
long func(long a, long b, long h) {
    // Variable declarations at top
    long sum;
    long result;
    long i;
    long temp_sum;
    long half;

    // Precondition checks
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= h <= 100;
    //@ assert h % 2 == 0;

    // Calculate sum
    sum = (a + b) * h;
    
    // Initialize loop variables
    result = 0;
    i = 0;
    temp_sum = sum;
    half = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant h % 2 == 0;
        loop invariant sum == (a + b) * h;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum + 2 * half == sum;
        loop invariant half >= 0;
        loop assigns temp_sum, half;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        half += 1;
    }
    
    result = half;

    // Postcondition verification
    //@ assert result == (a + b) * h / 2;
    
    return result;
}
