/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    predicate loop_invariant(integer result, integer a, integer b, integer c,
                             integer ra, integer rb, integer rc) =
        0 <= result <= a + b + c &&
        ra >= 0 && rb >= 0 && rc >= 0 &&
        result <= (a - ra) / 2 + (b - rb) + (c - rc);

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    lemma result_bounds: \forall integer a,b,c,result;
        valid_input(a,b,c) && 0 <= result <= total_sum(a,b,c) ==> result >= 0;
*/

/*@
    requires valid_input(a,b,c);
    ensures \result >= 0 && \result <= a + b + c;
*/
int func(int a, int b, int c)
{
    int result = 0;
    int remaining_a = a;
    int remaining_b = b;
    int remaining_c = c;

    /*@
        loop invariant loop_invariant(result,a,b,c,remaining_a,remaining_b,remaining_c);
        loop assigns result, remaining_a, remaining_b, remaining_c;
        loop variant remaining_a + remaining_b + remaining_c;
    */
    while (remaining_a >= 2 && remaining_b >= 1 && remaining_c >= 1)
    {
        //@ assert result <= a + b + c;
        remaining_a -= 2;
        remaining_b -= 1;
        remaining_c -= 1;
        result += 1;
    }

    //@ assert result <= a + b + c;
    return result;
}
