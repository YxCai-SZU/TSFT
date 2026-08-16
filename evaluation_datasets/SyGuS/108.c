/*@
requires a <= m;
*/
void foo(int a, int m, int c) {
    int j = 0;
    int k = 0;

    while (k < c) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

    /*@ assert a <= m; */
}
