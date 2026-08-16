/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    predicate pi_constant(integer pi) = pi == 31415;
    
    logic integer scaled_circumference(integer pi, integer r) = 2 * pi * r;
    logic integer expected_result(integer pi, integer r) = 2 * pi * r / 10000;
    
    lemma loop_maintains_relation:
        \forall integer pi, r, ans, temp, count;
        pi_constant(pi) && is_valid_range(r) &&
        0 <= ans <= expected_result(pi, r) &&
        temp == scaled_circumference(pi, r) - ans * 10000 &&
        count == ans ==>
        count * 10000 + temp == scaled_circumference(pi, r);
*/

/*@
    requires is_valid_range(r);
    ensures \result == expected_result(31415, r);
*/
long func(long r)
{
    long pi;
    long ans;
    long temp;
    long count;
    
    pi = 31415;
    ans = 0;
    temp = 2 * pi * r;
    count = 0;
    
    /*@
        loop invariant is_valid_range(r);
        loop invariant pi_constant(pi);
        loop invariant 0 <= ans <= expected_result(pi, r);
        loop invariant temp == scaled_circumference(pi, r) - ans * 10000;
        loop invariant count == ans;
        loop invariant count * 10000 + temp == scaled_circumference(pi, r);
        loop assigns ans, temp, count;
        loop variant temp;
    */
    while (temp >= 10000)
    {
        //@ assert count * 10000 + temp == scaled_circumference(pi, r);
        
        ans += 1;
        temp -= 10000;
        count += 1;
    }
    
    //@ assert count * 10000 + temp == scaled_circumference(pi, r);
    
    return ans;
}
