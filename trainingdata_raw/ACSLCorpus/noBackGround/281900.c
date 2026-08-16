/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0 && \result <= 1;
    assigns \nothing;
*/
int func(int n)
{
    int i;
    int a;
    int b;
    int c;
    int d;
    int e;
    int sum;
    int result;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    i = 1;
    /*@
        loop invariant 1 <= i && i <= 10;
        loop invariant (1 <= (n) && (n) <= 10000);
        loop assigns i, a, b, c, d, e, sum, result;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        a = 1;
        /*@
            loop invariant 1 <= a && a <= 10;
            loop invariant (1 <= (n) && (n) <= 10000);
            loop assigns a, b, c, d, e, sum, result;
            loop variant 10 - a;
        */
        while (a < 10)
        {
            b = 1;
            /*@
                loop invariant 1 <= b && b <= 10;
                loop invariant (1 <= (n) && (n) <= 10000);
                loop assigns b, c, d, e, sum, result;
                loop variant 10 - b;
            */
            while (b < 10)
            {
                c = 1;
                /*@
                    loop invariant 1 <= c && c <= 10;
                    loop invariant (1 <= (n) && (n) <= 10000);
                    loop assigns c, d, e, sum, result;
                    loop variant 10 - c;
                */
                while (c < 10)
                {
                    d = 1;
                    /*@
                        loop invariant 1 <= d && d <= 10;
                        loop invariant (1 <= (n) && (n) <= 10000);
                        loop assigns d, e, sum, result;
                        loop variant 10 - d;
                    */
                    while (d < 10)
                    {
                        e = 1;
                        /*@
                            loop invariant 1 <= e && e <= 10;
                            loop invariant (1 <= (n) && (n) <= 10000);
                            loop assigns e, sum, result;
                            loop variant 10 - e;
                        */
                        while (e < 10)
                        {
                            sum = i + a + b + c + d + e + 1;
                            //@ assert sum >= 7 && sum <= 55;
                            
                            if (sum == n) {
                                return 1;
                            }
                            e += 1;
                        }
                        d += 1;
                    }
                    c += 1;
                }
                b += 1;
            }
            a += 1;
        }
        i += 1;
    }
    
    result = 0;
    //@ assert result == 0;
    return result;
}
