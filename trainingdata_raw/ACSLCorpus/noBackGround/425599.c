#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == b*d || \result == b*c || \result == a*d || \result == a*c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    int i;
    int j;
    long long x;
    long long y;
    long long prod;
    
    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    max1 = a * c;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 2;
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant ((a) <= (b)) && ((c) <= (d));
        loop invariant max1 == a*c || max1 == b*c || max1 == a*d || max1 == b*d;
        loop assigns i, j, max1, x, y, prod;
        loop variant 2 - i;
    */
    while (i < 2)
    {
        j = 0;
        /*@
            loop invariant 0 <= j <= 2;
            loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
            loop invariant ((a) <= (b)) && ((c) <= (d));
            loop invariant max1 == a*c || max1 == b*c || max1 == a*d || max1 == b*d;
            loop assigns j, max1, x, y, prod;
            loop variant 2 - j;
        */
        while (j < 2)
        {
            x = (i == 0) ? a : b;
            y = (j == 0) ? c : d;
            
            //@ assert (-1000000000 <= (x) <= 1000000000);
            //@ assert (-1000000000 <= (y) <= 1000000000);
            //@ assert (-1000000000000000000 <= (x * y) <= 1000000000000000000);
            
            prod = x * y;
            if (prod > max1) {
                max1 = prod;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    return max1;
}
