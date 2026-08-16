/*@
    predicate bounds_a(integer a) = 1 <= a && a <= 10;
    predicate bounds_b(integer b) = 1 <= b && b <= 10;
    predicate sum_bound(integer a, integer b) = a + b <= 11;
    predicate product_bound(integer a, integer b) = a * b <= 100;
*/

/*@
    lemma calc_example_i_lemma:
        \forall integer a, b;
            a <= b + 1 ==> a + 2 <= b + 3;
*/

/*@
    lemma nonlinear_arith_example_i_lemma:
        \forall integer a, b;
            bounds_a(a) && bounds_b(b) && sum_bound(a, b) ==> product_bound(a, b);
*/

/*@
    lemma example_x_lemma:
        \forall integer a, b;
            bounds_a(a) && bounds_b(b) && sum_bound(a, b) ==> product_bound(a, b);
*/

/*@
    lemma example_y_lemma:
        \forall integer a, b;
            bounds_a(a) && bounds_b(b) && sum_bound(a, b) ==> product_bound(a, b);
*/

/*@
    requires a <= b + 1;
    ensures a + 2 <= b + 3;
*/
void calc_example_i(int a, int b)
{
    //@ assert a + 2 <= b + 3;
}

/*@
    requires 1 <= a && a <= 10 && 1 <= b && b <= 10 && a + b <= 11;
    ensures a * b <= 100;
*/
void nonlinear_arith_example_i(int a, int b)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert a + b <= 11;
    //@ assert a * b <= 100;
}

/*@
    requires 1 <= a && a <= 10 && 1 <= b && b <= 10 && a + b <= 11;
    ensures a * b <= 100;
*/
void example_x(int a, int b)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert a + b <= 11;
    //@ assert a * b <= 100;
}

/*@
    requires 1 <= a && a <= 10 && 1 <= b && b <= 10 && a + b <= 11;
    ensures a * b <= 100;
*/
void example_y(int a, int b)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert a + b <= 11;
    //@ assert a * b <= 100;
}

int main()
{
    return 0;
}
