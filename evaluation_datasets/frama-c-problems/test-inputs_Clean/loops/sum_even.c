int func(int n) {
    int sum = 0;
    int i = 0;

    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}

void test() {

    int s1 = func(0);
    //@ assert s1 == 0;

    int s2 = func(2);
    //@ assert s2 == 2;

    int s3 = func(10);
    //@ assert s3 == 30;

    int s4 = func(100);
    //@ assert s4 >= 0;
}
