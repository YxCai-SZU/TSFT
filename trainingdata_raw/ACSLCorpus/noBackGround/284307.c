/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int ans;

    // Precondition assertions
    //@ assert 2 <= a <= 100;
    //@ assert 2 <= b <= 100;

    // Product bounds verification
    //@ assert a * b <= 10000;
    //@ assert a * b >= 4;

    // Result positivity verification
    //@ assert a * b - a - b + 1 > 0;

    ans = a * b - a - b + 1;
    return ans;
}
