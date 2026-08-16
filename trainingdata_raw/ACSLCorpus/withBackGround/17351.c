/*@
    predicate is_valid_input(integer input) =
        1 <= input && input <= 1000000;

    predicate outer_loop_invariant(integer input, integer i, integer count) =
        is_valid_input(input) &&
        1 <= i &&
        i <= input + 1 &&
        count >= 0 &&
        count <= i - 1;

    predicate inner_loop_invariant(integer input, integer i, integer j, integer count) =
        outer_loop_invariant(input, i, count) &&
        1 <= j &&
        j <= 1000 + 1;

    lemma product_bounds:
        \forall integer input, integer i, integer j;
            is_valid_input(input) && 1 <= i && i <= input && 1 <= j && j <= 1000 ==>
            1 <= i * j && i * j <= 1000 * input;
*/

/*@
    requires is_valid_input(input);
    ensures \result >= 0;
*/
long func(long input)
{
    long i;
    long count;
    long j;
    int divisible;

    //@ assert is_valid_input(input);
    i = 1;
    count = 0;

    /*@
        loop invariant outer_loop_invariant(input, i, count);
        loop assigns i, count, divisible, j;
        loop variant input + 1 - i;
    */
    while (i <= input) {
        divisible = 0;
        j = 1;

        /*@
            loop invariant inner_loop_invariant(input, i, j, count);
            loop assigns j, divisible;
            loop variant 1000 + 1 - j;
        */
        while (j <= 1000) {
            //@ assert 1 <= i * j && i * j <= 1000 * input;
            if (i * j > input) {
                break;
            }
            if (i * j == input) {
                divisible = 1;
                break;
            }
            j += 1;
        }
        if (divisible) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count >= 0;
    return count;
}
