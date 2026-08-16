/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b < c < d < e;
    ensures \result == 1 <==> ((b) - (a) <= (k) && (c) - (a) <= (k) && (d) - (a) <= (k) && (e) - (a) <= (k));
*/
int func(int a, int b, int c, int d, int e, int k)
{
    int check = 0;

    //@ assert a < b && b < c && c < d && d < e;
    
    if (b - a <= k)
    {
        //@ assert b - a <= k;
        if (c - a <= k)
        {
            //@ assert c - a <= k;
            if (d - a <= k)
            {
                //@ assert d - a <= k;
                if (e - a <= k)
                {
                    //@ assert e - a <= k;
                    check = 1;
                }
            }
        }
    }

    //@ assert check == 1 <==> ((b) - (a) <= (k) && (c) - (a) <= (k) && (d) - (a) <= (k) && (e) - (a) <= (k));
    return check;
}
