/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    predicate square_in_range(integer r, integer res) = res == r * r && r * r <= 10000;

    lemma square_bound: \forall integer r; is_valid_range(r) ==> r * r <= 10000;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    return r * r;
}

/*@
    requires 1 <= x <= 100;
    ensures \result == x * x;
    assigns \nothing;
*/
unsigned int square_number(unsigned int x)
{
    unsigned int result;
    
    //@ assert 1 <= x && x <= 100;
    result = func(x);
    //@ assert result == x * x;
    return result;
}
