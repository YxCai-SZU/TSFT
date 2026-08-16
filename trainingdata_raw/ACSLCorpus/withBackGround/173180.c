/*@
    predicate is_i32(integer x) = -2147483648 <= x <= 2147483647;

    lemma min_is_one_of:
        \forall integer a, b, c, ret;
        is_i32(a) && is_i32(b) && is_i32(c) &&
        (ret == a || ret == b || ret == c) &&
        ret <= a && ret <= b && ret <= c
        ==>
        ret == a || ret == b || ret == c;

    lemma min_is_le_all:
        \forall integer a, b, c, ret;
        is_i32(a) && is_i32(b) && is_i32(c) &&
        (ret == a || ret == b || ret == c) &&
        ret <= a && ret <= b && ret <= c
        ==>
        ret <= a && ret <= b && ret <= c;
*/

/*@
    requires is_i32(a) && is_i32(b) && is_i32(c);
    ensures \result == a || \result == b || \result == c;
    ensures \result <= a && \result <= b && \result <= c;
    assigns \nothing;
*/
int min_numbers(int a, int b, int c)
{
    int min_val = a;
    //@ assert min_val == a;
    
    if (b < min_val)
    {
        min_val = b;
        //@ assert min_val == b;
    }
    //@ assert min_val <= a && min_val <= b;
    
    if (c < min_val)
    {
        min_val = c;
        //@ assert min_val == c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    
    //@ assert min_val == a || min_val == b || min_val == c;
    return min_val;
}
