int max(int x, int y) {
    if (x >= y) {
        return x;
    }
    return y;
}

void test() {
    int x = 1;
    int y = 2;
    int max_value = max(x, y);
    //@ assert max_value == 2;
}
