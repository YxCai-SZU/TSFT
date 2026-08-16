/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == 1 <==> (a > b + c || b > c + d || c > d + a || d > a + b);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    //@ assert ((b) + (c)) <= 200;
    //@ assert ((c) + (d)) <= 200;
    //@ assert ((d) + (a)) <= 200;
    //@ assert ((a) + (b)) <= 200;

    if (a > b + c || b > c + d || c > d + a || d > a + b)
    {
        return 1;
    }
    else
    {
        //@ assert a <= b + c && b <= c + d && c <= d + a && d <= a + b;
        return 0;
    }
}
