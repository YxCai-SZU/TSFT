int func(int a) {
    int x, y;
    int sum, res;
    if (a == 0){
        x = 0; y = 0;
    }
    else {
        x = 5; y = 5;
    }
    sum = x + y;
    res = 10/sum;
    return res;
}

void test() {
    int res = func(10);
    //@ assert res == 1;

    int res2 = func(-5);
    //@ assert res2 == 1;
}
