/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer scaled_pi = 314159;
    logic integer scale_factor = 100000;
    
    logic integer expected_circumference(integer r) = 
        (2 * r * scaled_pi) / scale_factor;
    
    lemma division_property: 
        \forall integer r, temp, count; 
        valid_range(r) && temp == 2 * r * scaled_pi - count * scale_factor && temp >= 0 && temp < scale_factor ==> 
        count == expected_circumference(r);
*/

/*@
    requires valid_range(r);
    ensures \result == expected_circumference(r);
    assigns \nothing;
*/
long func(long r) {
    long pi;
    long scale;
    long circumference;
    long temp;
    long count;
    
    pi = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * r * pi;
    count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 314159;
        loop invariant scale == 100000;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi - count * scale;
        loop invariant count >= 0;
        loop invariant count == expected_circumference(r) - (temp / scale);
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale) {
        //@ assert temp == 2 * r * pi - count * scale;
        temp -= scale;
        count += 1;
        //@ assert temp == 2 * r * pi - count * scale;
    }
    
    circumference = count;
    
    //@ assert temp < scale;
    //@ assert circumference == expected_circumference(r);
    return circumference;
}

int main(void) {
    return 0;
}
