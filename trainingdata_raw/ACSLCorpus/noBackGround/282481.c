/*@
    requires (0 <= (a) <= 100 &&
        0 <= (b) <= 100 &&
        0 <= (c) <= 100);
    ensures \result == 1;
    assigns \nothing;
*/
int lemma_bounds_check(int a, int b, int c)
{
    //@ assert (0 <= (a) <= 100 &&         0 <= (b) <= 100 &&         0 <= (c) <= 100);
    //@ assert 0 <= a + b <= 200;
    //@ assert 0 <= (a + b) * c <= 20000;
    return 1;
}
