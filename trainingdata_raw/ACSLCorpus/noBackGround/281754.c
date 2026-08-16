/*@
    requires (1 <= (A) && (A) <= 3 &&
        1 <= (B) && (B) <= 3 &&
        (A) != (B));
    ensures 1 <= \result && \result <= 6;
    ensures \result != A && \result != B;
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B)
{
    unsigned int ans;
    unsigned int i;

    //@ assert (1 <= (A) && (A) <= 3 &&         1 <= (B) && (B) <= 3 &&         (A) != (B));
    ans = 6;
    i = 1;

    /*@
        loop invariant 1 <= i && i <= 4;
        loop invariant (1 <= (A) && (A) <= 3 &&
        1 <= (B) && (B) <= 3 &&
        (A) != (B) &&
        1 <= (i) && (i) <= 4 &&
        1 <= (ans) && (ans) <= 6 &&
        ((i) > 1 ==> (ans) != (A) && (ans) != (B)) &&
        ((ans) == 6 || ((ans) != (A) && (ans) != (B))));
        loop assigns i, ans;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (i != A && i != B)
        {
            ans = i;
            break;
        }
        i += 1;
    }

    //@ assert 1 <= ans && ans <= 6;
    //@ assert ans != A && ans != B;
    return ans;
}
