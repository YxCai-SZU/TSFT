int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;

    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}

void test() {
    int r1;
    int q1 = fun(10, 3, &r1);

    //@ assert 10 == q1 * 3 + r1;
    //@ assert r1 < 3;

    int r2;
    int q2 = fun(12, 4, &r2);

    //@ assert 12 == q2 * 4 + r2;
    //@ assert r2 < 4;

}
