/*@
    predicate less_than(integer a, integer b) = a < b;

    lemma calc_example_j:
        \forall integer a, b;
            less_than(a, b) ==> less_than(a - 1, b - 1);

    logic integer max_product(integer a, integer b, integer c) = a * b * c;

    lemma example_multiple_integer_arithmetics:
        \forall integer a, b, c;
            (0 <= a && a <= 100 && 0 <= b && b <= 100 && 0 <= c && c <= 100) ==>
            max_product(a, b, c) <= 100 * 100 * 100;
*/

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    ensures \result <= 100 * 100 * 100;
*/
int example_multiple_integer_arithmetics(int a, int b, int c)
{
    int result;

    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
    result = a * b * c;

    return result;
}

int main()
{
    return 0;
}
