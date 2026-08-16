/*@
    requires n >= 0;
    ensures \result == (n % 2 == 0);
*/
int is_even(int n) {
    int temp_n;
    temp_n = n;

    /*@
        loop invariant ((temp_n) >= 0 && (temp_n) <= (n) && (temp_n) % 2 == (n) % 2);
        loop assigns temp_n;
    */
    while (temp_n >= 2) {
        temp_n -= 2;
    }

    //@ assert temp_n == 0 || temp_n == 1;
    return temp_n == 0;
}

/*@
    requires 1 <= r <= 100;
    ensures \result == (3 * (r) * (r));
*/
int func(int r) {
    int pi;
    int area;
    
    pi = 3;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    area = pi * r * r;
    
    return area;
}
