/*@
    predicate is_valid_range(integer l) = 1 <= l && l <= 1000;
    
    logic integer square(integer l) = l * l;
    
    lemma square_bounded: 
        \forall integer l; is_valid_range(l) ==> square(l) <= 1000000;
*/

/*@
    requires is_valid_range(l);
    ensures \result == (l * l) / 3;
    assigns \nothing;
*/
int func(int l)
{
    // Variable declarations at top of scope
    int l_squared;
    int result;
    int count;
    int temp;
    
    //@ assert is_valid_range(l);
    
    //@ assert l * l <= 1000000;
    l_squared = l * l;
    
    result = 0;
    count = 0;
    temp = l_squared;
    
    /*@
        loop invariant 1 <= l && l <= 1000;
        loop invariant l_squared == l * l;
        loop invariant temp >= 0;
        loop invariant temp == l_squared - 3 * count;
        loop invariant count >= 0;
        loop invariant count <= l_squared / 3;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        int old_temp = temp;
        int old_count = count;
        
        //@ assert temp >= 3;
        temp = temp - 3;
        //@ assert temp == old_temp - 3;
        count = count + 1;
        //@ assert count == old_count + 1;
    }
    
    result = count;
    
    //@ assert result == (l * l) / 3;
    return result;
}
