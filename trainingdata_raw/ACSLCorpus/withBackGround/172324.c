/*@
    predicate is_in_range(integer v) = 1 <= v <= 100;

    lemma transitivity_lemma:
        \forall integer a, b, c;
            is_in_range(a) && is_in_range(b) && is_in_range(c) &&
            a <= b && b <= c ==> a <= c;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    ensures \result == (x <= y && y <= z);
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= z <= 100;
    return (x <= y && y <= z);
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a <= b;
    requires b <= c;
    ensures a <= c;
    assigns \nothing;
*/
void check_less_than_or_equal(int a, int b, int c)
{
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
}

int main()
{
    return 0;
}
