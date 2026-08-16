/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100);
    ensures ((\result) == ((x) % 2 == 0 && (y) % 2 == 0));
*/
int func(int x, int y) {
    int x_is_even;
    int temp_x;
    int y_is_even;
    int temp_y;
    int result;

    x_is_even = 0;
    temp_x = x;

    /*@
        loop invariant (0 <= (temp_x) <= (x));
        loop invariant (1 <= (x) <= 100);
        loop invariant (1 <= (y) <= 100);
        loop invariant ((temp_x) % 2 == (x) % 2);
        loop assigns temp_x;
    */
    while (temp_x >= 2) {
        temp_x = temp_x - 2;
    }

    if (temp_x == 0) {
        x_is_even = 1;
    }

    y_is_even = 0;
    temp_y = y;

    /*@
        loop invariant (0 <= (temp_y) <= (y));
        loop invariant (1 <= (x) <= 100);
        loop invariant (1 <= (y) <= 100);
        loop invariant ((temp_y) % 2 == (y) % 2);
        loop assigns temp_y;
    */
    while (temp_y >= 2) {
        temp_y = temp_y - 2;
    }

    if (temp_y == 0) {
        y_is_even = 1;
    }

    //@ assert (0 <= (temp_x) <= (x));
    //@ assert (0 <= (temp_y) <= (y));

    result = x_is_even && y_is_even;
    return result;
}
