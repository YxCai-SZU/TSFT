/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result >= 0;
    ensures \result == a || \result == b || \result == c || \result == d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;
    
    res = 2147483647;
    
    //@ assert res == 2147483647;
    
    if (a < res)
    {
        res = a;
    }
    //@ assert res == a || res == 2147483647;
    
    if (b < res)
    {
        res = b;
    }
    //@ assert res == a || res == b || res == 2147483647;
    
    if (c < res)
    {
        res = c;
    }
    //@ assert res == a || res == b || res == c || res == 2147483647;
    
    if (d < res)
    {
        res = d;
    }
    //@ assert res == a || res == b || res == c || res == d;
    
    //@ assert res >= 0;
    
    return res;
}
