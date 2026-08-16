/*@
requires n > 0;
*/
void foo(int n) {
    int y = 0;
    int x = 1;

    while (x <= n) {
        y = n - x;
        x = x +1;
    }

    if (n > 0) {

        /*@ assert y <= n; */
    }
}
