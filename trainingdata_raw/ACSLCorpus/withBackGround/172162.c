/*@
    predicate is_positive(integer x) = x > 0;
    predicate sum_bounded(integer a, integer b, integer c) = a + b + c <= 100;
    
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
    
    lemma sum_properties:
        \forall integer a, b, c;
        is_positive(a) && is_positive(b) && is_positive(c) && sum_bounded(a, b, c) ==>
        total_sum(a, b, c) > 0;
*/

/*@
    requires is_positive(a) && is_positive(b) && is_positive(c);
    requires sum_bounded(a, b, c);
    ensures \result == total_sum(a, b, c);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert is_positive(a);
    //@ assert is_positive(b);
    //@ assert is_positive(c);
    //@ assert sum_bounded(a, b, c);
    
    unsigned int res;
    res = a + b + c;
    
    //@ assert res == total_sum(a, b, c);
    return res;
}

int main()
{
    return 0;
}
