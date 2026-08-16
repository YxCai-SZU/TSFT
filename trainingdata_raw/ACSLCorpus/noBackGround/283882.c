/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
unsigned int func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned int res;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;

    if (a == b && b == c) {
        res = 1;
    } else if (a == b || b == c || c == a) {
        res = 2;
    } else {
        //@ assert 1 <= 3 && 3 <= 3;
        res = 3;
    }

    //@ assert res >= 1 && res <= 3;
    return res;
}
