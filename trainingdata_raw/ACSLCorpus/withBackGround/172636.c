/*@
    predicate is_valid_input(integer x) = x <= 0x49;

    logic integer target_result(integer x) = (x + 3) / 4;

    lemma remainder_bound: \forall integer x; is_valid_input(x) ==> x + 3 <= 0x4C;
*/

/*@
    requires is_valid_input(x);
    ensures \result == target_result(x);
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int result = 0;
    unsigned int remainder = x + 3;

    //@ assert x + 3 <= 0x4C;

    /*@
        loop invariant 0 <= result;
        loop invariant result <= target_result(x);
        loop invariant remainder == x + 3 - 4 * result;
        loop invariant remainder <= x + 3;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= 4)
    {
        result += 1;
        remainder -= 4;
    }

    return result;
}

int main(void)
{
    return 0;
}
