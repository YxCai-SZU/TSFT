/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer max_product(integer t, integer s) = t * s;
    
    lemma product_bound:
        \forall integer t, s;
        valid_range(t) && valid_range(s) ==> max_product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (d <= t * s);
*/
int func(int d, int t, int s)
{
    //@ assert valid_range(d);
    //@ assert valid_range(t);
    //@ assert valid_range(s);
    //@ assert max_product(t, s) <= 10000 * 10000;
    
    int result;
    result = (d <= t * s);
    return result;
}

/*@
    lemma func_proof:
        \forall integer d, t, s;
        valid_range(d) && valid_range(t) && valid_range(s) ==>
        max_product(t, s) <= 10000 * 10000;
*/

int main()
{
    return 0;
}
