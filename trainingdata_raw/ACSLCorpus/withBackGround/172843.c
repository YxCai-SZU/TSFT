/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    logic integer compute_circumference(integer r, integer pi) = 2 * r * pi;
    logic integer compute_expected(integer r) = 2 * r * 3;
    
    lemma precision_factor_positive: \forall integer r; is_valid_range(r) ==> 10000 > 0;
    lemma temp_decreases: \forall integer temp; temp >= 10000 ==> temp - 10000 < temp;
*/

/*@
    requires is_valid_range(r);
    ensures \result == compute_expected(r);
    assigns \nothing;
*/
int func(int r) {
    int precision_factor;
    int pi;
    int circumference;
    int result;
    int temp;
    
    precision_factor = 10000;
    pi = 3 * precision_factor;
    circumference = 2 * r * pi;
    
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant precision_factor == 10000;
        loop invariant pi == 3 * precision_factor;
        loop invariant circumference == 2 * r * pi;
        loop invariant result * precision_factor + temp == circumference;
        loop invariant temp >= 0;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= precision_factor) {
        //@ assert temp >= 10000;
        result += 1;
        temp -= precision_factor;
        //@ assert result * precision_factor + temp == circumference;
    }
    
    //@ assert result * precision_factor + temp == circumference;
    //@ assert temp < precision_factor;
    //@ assert result == compute_expected(r);
    return result;
}
