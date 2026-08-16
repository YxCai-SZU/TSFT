int abs(int val) {
    if(val < 0) return -val;
    return val;
}

void test() {
    int b = abs(-42);
    //@ assert b == 42;

    int c = abs(42);
    //@ assert c == 42;

    int z = abs(0);
    //@ assert z == 0;

    int unknown = 100;
    int d = abs(unknown);
    //@ assert d >= 0;
}
