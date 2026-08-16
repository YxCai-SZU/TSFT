/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    
    logic integer circumference_formula(integer r) = 
        (2 * 314159 * r) / 100000;
    
    lemma temp_bounds: 
        \forall integer r; valid_radius(r) ==> 0 < 2 * 314159 * r <= 200 * 314159;
*/

/*@
    requires valid_radius(r);
    ensures \result == circumference_formula(r);
    assigns \nothing;
*/
long func(long r) {
    long pi_approx = 314159;
    long circumference = 0;
    long temp = 2 * pi_approx * r;
    long divisor = 100000;
    
    //@ assert valid_radius(r);
    //@ assert temp == 2 * 314159 * r;
    //@ assert 0 < 2 * 314159 * r <= 200 * 314159;
    
    /*@
        loop invariant valid_radius(r);
        loop invariant temp == 2 * 314159 * r - circumference * 100000;
        loop invariant circumference * 100000 + temp == 2 * pi_approx * r;
        loop invariant 0 <= temp;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * 100000 + temp == 2 * 314159 * r;
    //@ assert temp < divisor;
    //@ assert circumference == circumference_formula(r);
    
    return circumference;
}

int main() {
    return 0;
}
