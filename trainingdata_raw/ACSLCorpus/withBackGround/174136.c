/*@
    predicate valid_range(integer x) = 2 <= x <= 100;

    logic integer func_spec(integer a, integer b) = a * b - a - b + 1;

    lemma func_positive: \forall integer a, b; valid_range(a) && valid_range(b) ==> func_spec(a, b) > 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == func_spec(a, b);
    ensures \result > 0;
*/
int func(int a, int b)
{
    int result;

    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    //@ assert a * b <= 10000;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -99;
    //@ assert a * b - a - b + 1 > 0;

    result = a * b - a - b + 1;
    return result;
}
