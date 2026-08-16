/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
    
    logic integer compute_result(integer a, integer b) = a - b * 2;
    
    lemma result_property:
        \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==>
        compute_result(a, b) >= 0 || 0 >= 0;
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    int ans;
    
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    
    res = a - b * 2;
    
    if (res > 0)
    {
        ans = res;
        //@ assert ans == a - b * 2;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans >= 0;
    
    return ans;
}
