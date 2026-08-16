/*@
    predicate is_max(integer val, integer a, integer b, integer c) =
        (val == a || val == b || val == c) &&
        val >= a && val >= b && val >= c;
*/

/*@
    requires \true;
    ensures is_max(\result, a, b, c);
*/
int find_greater_of_three(int a, int b, int c)
{
    int ret;
    //@ assert \true;
    if (a >= b && a >= c)
    {
        //@ assert a >= b;
        //@ assert a >= c;
        ret = a;
    }
    else if (b >= a && b >= c)
    {
        //@ assert b >= a;
        //@ assert b >= c;
        ret = b;
    }
    else
    {
        //@ assert c >= a;
        //@ assert c >= b;
        ret = c;
    }
    //@ assert is_max(ret, a, b, c);
    return ret;
}
