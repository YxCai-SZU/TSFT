/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 31415 * ((r))) / 10000);
    assigns \nothing;
*/
int func(int r) {
    int res;
    int quotient = 0;
    int divisor = 10000;

    //@ assert 2 * 31415 <= 100000;
    res = 2 * 31415 * r;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= res <= 20000000;
        loop invariant (2 * 31415 * (r)) - quotient * divisor == res;
        loop invariant res >= 0;
        loop assigns res, quotient;
        loop variant res;
    */
    while (res >= divisor) {
        res -= divisor;
        quotient += 1;
    }

    return quotient;
}

int main() {
    return 0;
}
