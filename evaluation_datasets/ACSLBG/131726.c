/*@
    predicate lt(integer x, integer y) = x < y;
    predicate gt(integer x, integer y) = x > y;
    predicate gt_chain(integer a, integer b, integer c) = a > b && b > c;

    logic integer diff_lt_zero(integer x, integer y) = x - y;

    lemma calc_example_6: \forall integer x, y; lt(x, y) ==> diff_lt_zero(x, y) < 0;
    lemma calc_example_7: \forall integer a, b, c; gt_chain(a, b, c) ==> (a - b) > (c - a);
    lemma calc_example_8: \forall integer x, y; lt(x, y) ==> (x + y) < (2 * y);
*/


int calc_example_6_impl(int x, int y)
{
    //@ assert x - y < 0;
    return 0;
}


int calc_example_7_impl(int a, int b, int c)
{
    //@ assert a - b > c - a;
    return 0;
}


int calc_example_8_impl(int x, int y)
{
    //@ assert x + y < 2 * y;
    return 0;
}

int main()
{
    int x;
    int y;
    int a;
    int b;
    int c;
    return 0;
}
