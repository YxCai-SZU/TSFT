int unknown();

/*@
requires n > 1;
*/
void foo(int n)
{
    int x = 1;
    int m = 1;

    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    if(n > 1) {

       /*@ assert m >= 1; */
    }
}
