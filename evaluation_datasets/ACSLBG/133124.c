/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer spec_max_value(integer x, integer y) = 
        x > y ? x : y;
    
    lemma max_value_test1:
        spec_max_value(100, 200) == 200;
    
    lemma max_value_test2:
        spec_max_value(300, 50) == 300;
    
    lemma arithmetic_bounds:
        \forall integer r; is_valid_range(r) ==> 3 * r <= 300;
    
    lemma result_bound:
        \forall integer r; is_valid_range(r) ==> 3 * r * r <= 30000;
*/


int func(int r)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert is_valid_range(r);
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    result = 3 * r * r;
    
    //@ assert result == 3 * r * r;
    return result;
}

int main()
{
    return 0;
}
