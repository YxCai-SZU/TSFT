/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a && a <= 10000 && 1 <= b && b <= 10000;

    lemma multiplication_bounds:
        \forall integer a, b;
            is_valid_range(a, b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == ((a * b) % 2 == 0);
*/
int func(unsigned int a, unsigned int b)
{
    int result = 0;

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    if ((a * b) % 2 == 0)
    {
        result = 1;
    }

    //@ assert result == ((a * b) % 2 == 0);
    return result;
}
