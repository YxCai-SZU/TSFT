/*@
    predicate is_max(integer ret, integer a, integer b) =
        (ret == a || ret == b) && ret >= a && ret >= b;

    logic integer max_val(integer a, integer b) =
        a > b ? a : b;

    lemma max_property:
        \forall integer a, b;
            max_val(a, b) == a || max_val(a, b) == b;

    lemma max_ge_a:
        \forall integer a, b;
            max_val(a, b) >= a;

    lemma max_ge_b:
        \forall integer a, b;
            max_val(a, b) >= b;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 50;
    requires 1 <= b <= 50;
    ensures \result >= 0;
    ensures \result <= n * a;
    ensures \result <= b;
*/
int func(int n, int a, int b)
{
    //@ assert n * a <= 20 * 50;
    int result;
    if (n * a < b)
    {
        result = n * a;
    }
    else
    {
        result = b;
    }
    return result;
}

/*@
    ensures is_max(\result, a, b);
*/
int maximum(int a, int b)
{
    int ret;
    if (a > b)
    {
        ret = a;
    }
    else
    {
        ret = b;
    }
    //@ assert is_max(ret, a, b);
    return ret;
}
