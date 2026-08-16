/*@
    predicate pos(integer v) = v > 0;

    lemma calc_example_23:
        \forall integer x, y;
            pos(x) && pos(y) ==>
                (x + 3) * (y + 3) == x * y + 3 * x + 3 * y + 9;
*/

int main()
{
    return 0;
}
