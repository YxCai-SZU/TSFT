/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (((a) * 3 + (b)) % 2 == 0);
    assigns \nothing;
*/
int func(int a, int b) {
    int x;
    int is_even;
    int temp_x;

    x = a * 3 + b;
    is_even = 1;
    temp_x = x;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 2 == x % 2;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 2) {
        temp_x -= 2;
    }

    //@ assert temp_x == 0 || temp_x == 1;
    if (temp_x == 1) {
        is_even = 0;
    }

    //@ assert is_even == (x % 2 == 0);
    return is_even;
}
