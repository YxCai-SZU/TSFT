/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;

    lemma mul_bound_64:
        \forall integer x, y;
            in_range(x, 1, 8) && in_range(y, 1, 8) ==> x * y <= 64;

    lemma mul_bound_10000:
        \forall integer x, y;
            in_range(x, 1, 100) && in_range(y, 1, 100) ==> x * y <= 10000;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    return n * n;
}

/*@
    requires 1 <= x <= 8;
    requires 1 <= y <= 8;
    ensures x * y <= 64;
    assigns \nothing;
*/
void nonlinear_arith_example(unsigned int x, unsigned int y)
{
    //@ assert x * y <= 64;
}

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures x * y <= 10000;
    assigns \nothing;
*/
void nonlinear_arith_example2(unsigned int x, unsigned int y)
{
    //@ assert x * y <= 10000;
}

int main()
{
    return 0;
}
