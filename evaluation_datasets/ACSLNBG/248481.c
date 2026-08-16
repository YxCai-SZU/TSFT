
int func(int x) {
    int ans = 0;
    int temp_x = x;

    
    while (temp_x >= 2) {
        ans += 1;
        temp_x -= 2;
    }

    int remainder = (temp_x == 1) ? 1 : 0;
    int res = ans + remainder;

    //@ assert res == (((x) + 1) / 2);

    return res;
}
