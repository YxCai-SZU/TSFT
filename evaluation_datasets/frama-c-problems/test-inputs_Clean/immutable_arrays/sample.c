int fun(int x, int y) {
    int r = x;
    int d = 0;

    while (r >= y) {
        printf("r = %d   d = %d   y = %d   x = %d\n", r, d, y, x);

        r = r - y;
        d = d + 1;

    }
    //@ assert r < y;
    //@ assert x == d*y + r;
    return d;
}
