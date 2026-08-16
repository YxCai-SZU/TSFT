/*@
    requires (2 <= (n) <= 100 &&
        1 <= (a) < (b) <= (n));
    ensures \result == (((b) - (a) - 1) % 2 != 0);
*/
int func(unsigned long n, unsigned long a, unsigned long b) {
    unsigned long interval;
    int is_odd;
    unsigned long temp;

    interval = b - a - 1;
    is_odd = 0;
    temp = interval;

    /*@
        loop invariant 0 <= temp <= interval;
        loop invariant ((b) - (a) - 1) % 2 == temp % 2;
        loop assigns temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }

    if (temp == 1) {
        is_odd = 1;
    }

    return is_odd;
}
