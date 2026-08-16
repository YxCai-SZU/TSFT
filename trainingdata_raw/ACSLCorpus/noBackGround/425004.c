/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - (a) - (b));
    ensures 1 <= \result && \result <= 3;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int c;
    unsigned int result;

    c = 6;
    result = c - a - b;

    //@ assert result == 6 - a - b;

    return result;
}
