/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer circumference_formula(integer r) = 2 * 3142 * r / 1000;
    
    lemma formula_positive: \forall integer r; valid_range(r) ==> circumference_formula(r) >= 0;
*/

/*@
    requires valid_range(r);
    ensures \result == circumference_formula(r);
    assigns \nothing;
*/
long func(long r)
{
    long precision_factor = 1000;
    long pi = 3142;
    long circumference = 0;
    long temp = 2 * pi * r;
    long count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant precision_factor == 1000;
        loop invariant pi == 3142;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi * r - count * precision_factor;
        loop invariant count >= 0;
        loop invariant count <= 2 * pi * r / precision_factor;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= precision_factor)
    {
        //@ assert temp >= precision_factor;
        temp -= precision_factor;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert circumference == circumference_formula(r);
    
    return circumference;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
