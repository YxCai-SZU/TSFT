/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result >= ((a) + (b) + 1 <= (c) ? (a) + (b) + 1 + (b) : (b) + (c));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int ans;

    //@ assert a + b <= 200;
    //@ assert a + b + 1 <= 201;
    //@ assert b + c <= 200;

    if (a + b + 1 <= c) {
        ans = a + b + 1 + b;
    } else {
        ans = b + c;
    }

    return ans;
}
