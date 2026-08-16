/*@
    requires ((x) % 2 == 0);
    ensures \result == x - 2;
*/
int calc_example_4(int x) {
    //@ assert ((x) % 2 == 0);
    return x - 2;
}

/*@
    requires ((x) % 2 == 0);
    ensures \result == x / 2;
*/
int is_even_func(int x) {
    //@ assert ((x) % 2 == 0);
    int half_x = x / 2;
    //@ assert half_x == x / 2;
    return half_x;
}

/*@
    requires ((x) % 3 == 0);
    ensures \result == x / 3;
*/
int is_divisible_by_3_func(int x) {
    //@ assert ((x) % 3 == 0);
    int third_x = x / 3;
    //@ assert third_x == x / 3;
    return third_x;
}

/*@
    requires ((x) % 6 == 0);
    ensures \result == x / 6;
*/
int is_divisible_by_6_func(int x) {
    //@ assert ((x) % 6 == 0);
    int sixth_x = x / 6;
    //@ assert sixth_x == x / 6;
    return sixth_x;
}

int main() {
    return 0;
}
