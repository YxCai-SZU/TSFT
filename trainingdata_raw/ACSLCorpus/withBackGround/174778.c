/*@
    predicate is_small(integer x) = 1 <= x && x <= 20;
    predicate both_small(integer a, integer b) = a < 10 && b < 10;
    predicate one_large(integer a, integer b) = a >= 10 || b >= 10;
*/

/*@
    requires is_small(a) && is_small(b);
    ensures both_small(a, b) ==> \result == a * b;
    ensures one_large(a, b) ==> \result == -1;
*/
int func(int a, int b)
{
    int max_value;
    int result;

    //@ assert is_small(a) && is_small(b);
    max_value = (a > b) ? a : b;

    if (max_value < 10)
    {
        //@ assert both_small(a, b);
        //@ assert a * b <= 100;
        result = a * b;
        return result;
    }
    else
    {
        //@ assert one_large(a, b);
        return -1;
    }
}
