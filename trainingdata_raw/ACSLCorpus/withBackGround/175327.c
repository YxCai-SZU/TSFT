/*@
    predicate is_in_range(integer x) = 1 <= x <= 10;

    logic integer double_sum(integer a, integer b) = (a + b) * 2;

    lemma double_sum_definition: \forall integer a, b; double_sum(a, b) == (a + b) * 2;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == (double_sum(a, b) <= 21);
*/
int func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    unsigned int product;
    int result;

    sum = a + b;
    product = sum * 2;

    //@ assert product == (a + b) * 2;

    result = (product <= 21);
    return result;
}
