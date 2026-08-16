/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;
    predicate result_range(integer r) = 0 <= r && r <= 100000;
    logic integer cast_to_i32(integer x) = x;
*/

/*@
    requires is_valid_range(x);
    ensures result_range(\result);
    assigns \nothing;
*/
int func(unsigned int x)
{
    int v;
    int m;
    int result;
    
    v = (int)x;
    m = 1;
    result = 0;
    
    /*@
        loop invariant 1 <= x && x <= 100;
        loop invariant m >= 1;
        loop invariant result >= 0 && result <= 100000;
        loop invariant v == (int)x;
        loop invariant m <= (int)x;
        loop assigns m, result;
    */
    while (m * 2 <= v)
    {
        //@ assert m >= 1 && m <= (int)x;
        result = m;
        m = m + 1;
        //@ assert result >= 0 && result <= 100000;
    }
    
    //@ assert result_range(result);
    return result;
}

int main(void)
{
    return 0;
}
