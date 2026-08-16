/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_at_most_five(integer x) = x <= 5;
    predicate double_at_most_ten(integer x) = x * 2 <= 10;

    lemma double_inequality:
        \forall integer x;
            is_nonnegative(x) && is_at_most_five(x) ==> double_at_most_ten(x);
*/

int main()
{
    return 0;
}
