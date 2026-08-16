/*@
requires n > 0;
*/
void foo(int n) {
    int x = 1;
    int y = 0;

    while (x <= n) {
        y = n - x;
        x = x +1;
    }

    if (n > 0) {

      /*@ assert y < n; */
    }
}
