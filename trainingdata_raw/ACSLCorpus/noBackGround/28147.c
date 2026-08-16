/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == x + ((y) / 2);
    assigns \nothing;
*/
int func(int x, int y) {
    int half_y;
    int i;

    half_y = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= y;
        loop invariant half_y >= 0;
        loop invariant half_y * 2 == i;
        loop invariant (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
        loop assigns half_y, i;
        loop variant y - i;
    */
    while (i < y) {
        //@ assert half_y * 2 == i;
        half_y += 1;
        i += 2;
    }

    //@ assert half_y * 2 == y;
    return x + half_y;
}
