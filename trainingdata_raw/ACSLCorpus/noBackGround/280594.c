/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) ||
            \result == ((b) * (c)) || \result == ((b) * (d));
*/
long long func(long long a, long long b, long long c, long long d)
{
    // Variable declarations at top of scope
    long long max_val;
    int i;
    int j;
    long long x;
    long long y;
    long long prod;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert ((a) * (c)) >= -1000000000000000000;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert ((a) * (d)) >= -1000000000000000000;

    max_val = a * c;

    i = 0;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant a <= b && c <= d;
        loop invariant ((max_val) == (((a)) * ((c))) || (max_val) == (((a)) * ((d))) ||
        (max_val) == (((b)) * ((c))) || (max_val) == (((b)) * ((d))));
        loop assigns i, j, max_val, x, y, prod;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        j = 0;
        /*@
            loop invariant 0 <= j <= 2;
            loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
            loop invariant a <= b && c <= d;
            loop invariant ((max_val) == (((a)) * ((c))) || (max_val) == (((a)) * ((d))) ||
        (max_val) == (((b)) * ((c))) || (max_val) == (((b)) * ((d))));
            loop assigns j, max_val, x, y, prod;
            loop variant 2 - j;
        */
        while (j < 2)
        {
            x = (i == 0) ? a : b;
            y = (j == 0) ? c : d;

            //@ assert (-1000000000 <= (x) <= 1000000000);
            //@ assert (-1000000000 <= (y) <= 1000000000);
            //@ assert ((x) * (y)) >= -1000000000000000000;

            prod = x * y;
            if (prod > max_val) {
                max_val = prod;
            }
            j++;
        }
        i++;
    }

    return max_val;
}
