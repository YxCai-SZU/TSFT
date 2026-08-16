/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    
    logic integer pi_val = 3;
    
    logic integer circumference_formula(integer r) = 2 * pi_val * r;
    
    lemma loop_invariant_maintained:
        \forall integer r, i, circ;
        valid_radius(r) && 0 <= i && i <= 2 && circ == i * pi_val * r ==>
        circ <= 2 * pi_val * r;
*/

/*@
    requires valid_radius(r);
    ensures \result == circumference_formula(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int pi;
    int circumference;
    int i;
    
    pi = 3;
    circumference = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant circumference == i * pi * r;
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3;
        loop invariant circumference <= 2 * pi * r;
        loop assigns circumference, i;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        circumference += pi * r;
        i += 1;
    }
    
    //@ assert circumference == 2 * pi * r;
    
    return circumference;
}

int main()
{
    return 0;
}
