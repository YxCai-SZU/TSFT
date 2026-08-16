int fun(int n) {
    int y = 0;
    int i = 0;

    while(i <= n) {

        y = y + (1 << i);
        i = i + 1;
    }
    return y;
}

int main() {
    int res = fun(4);

    //@ assert res == 31;

    int res2 = fun(2);
    //@ assert res2 == 7;
}
