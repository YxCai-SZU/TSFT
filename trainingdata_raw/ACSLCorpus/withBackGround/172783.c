/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate i_in_range(integer i, integer b) = 0 <= i <= b;
    predicate result_correct(integer result, integer a, integer i) = result == a * i;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result = 0;
    int i = 0;
    
    /*@
        loop invariant a_in_range(a);
        loop invariant b_in_range(b);
        loop invariant i_in_range(i, b);
        loop invariant result_correct(result, a, i);
        loop assigns result, i;
        loop variant b - i;
    */
    while (i < b)
    {
        //@ assert 0 <= a * i <= 100 * 100;
        //@ assert result + a == a * (i + 1);
        
        result += a;
        i += 1;
    }
    
    return result;
}

int main()
{
    return 0;
}
