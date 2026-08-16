/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer double_triple(integer r) = r * 2 * 3;
    lemma double_bound: \forall integer r; r_in_range(r) ==> 2 * r <= 200;
    lemma result_bound: \forall integer r; r_in_range(r) ==> 6 <= double_triple(r) <= 600;
*/


int func(int r)
{
    // Declare all variables at the top
    int result;

    //@ assert r_in_range(r);
    //@ assert 2 * r <= 200;
    //@ assert 6 <= r * 2 * 3 <= 600;
    
    result = r * 2 * 3;
    
    //@ assert result == double_triple(r);
    return result;
}
