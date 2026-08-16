int func(int c) {
    int x = c;
    int y = 0;

    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}

void test() {

    int r1 = func(100);
    //@ assert r1 == 100;

    int r2 = func(1);
    //@ assert r2 == 1;

    int r3 = func(42);
    //@ assert r3 == 42;
}
