/*@
    requires (0 <= (a) <= 123 &&
        0 <= (b) <= 123 &&
        0 <= (c) <= 123 &&
        0 <= (d) <= 123 &&
        0 <= (e) <= 123 &&
        0 <= (k) <= 123 &&
        (a) < (b) &&
        (b) < (c) &&
        (c) < (d) &&
        (d) < (e));
    ensures \result == 1;
    assigns \nothing;
*/
int func(long long a, long long b, long long c, long long d, long long e, long long k) {
    long long v[5];
    int n;
    int i;
    int j;
    long long diff;

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;
    n = 5;
    i = 0;

    //@ assert ((n) == 5 &&         \forall integer x; 0 <= x < (n) ==>              ((&v[0])[x] == (a) || (&v[0])[x] == (b) || (&v[0])[x] == (c) || (&v[0])[x] == (d) || (&v[0])[x] == (e)));

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((n) == 5 &&
        \forall integer x; 0 <= x < (n) ==> 
            ((&v[0])[x] == (a) || (&v[0])[x] == (b) || (&v[0])[x] == (c) || (&v[0])[x] == (d) || (&v[0])[x] == (e)));
        loop assigns i, j, diff;
        loop variant n - i;
    */
    while (i < n) {
        j = 0;

        /*@
            loop invariant 0 <= j <= n;
            loop invariant ((n) == 5 &&
        \forall integer x; 0 <= x < (n) ==> 
            ((&v[0])[x] == (a) || (&v[0])[x] == (b) || (&v[0])[x] == (c) || (&v[0])[x] == (d) || (&v[0])[x] == (e)));
            loop assigns j, diff;
            loop variant n - j;
        */
        while (j < n) {
            if (v[i] > v[j]) {
                diff = v[i] - v[j];
            } else {
                diff = v[j] - v[i];
            }

            //@ assert diff >= 0;

            j += 1;
        }

        i += 1;
    }

    //@ assert \true;
    return 1;
}

int main() {
    return 0;
}
