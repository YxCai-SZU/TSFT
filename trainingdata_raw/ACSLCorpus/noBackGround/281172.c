/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000 &&
        (a) + (b) + 1 <= (c));
    ensures \result == c - a - b - 1;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at the top
    unsigned int result;

    //@ assert a + b + 1 <= c;
    result = c - a - b - 1;
    return result;
}
