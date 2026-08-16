/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_spec(integer r) = 3 * r * r;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top
    int res;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    res = 3 * r * r;
    return res;
}

int main()
{
    return 0;
}
