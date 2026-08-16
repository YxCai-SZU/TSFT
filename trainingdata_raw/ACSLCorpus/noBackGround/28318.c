/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == 1 <==> ((c) <= (b) + (d) && (b) <= (a) + (d) && (a) <= (c) + (d) && (d) <= (a) + (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    
    ans = 0;
    
    if (c <= b + d && b <= a + d && a <= c + d && d <= a + b + c)
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }
    
    //@ assert ans == 1 <==> ((c) <= (b) + (d) && (b) <= (a) + (d) && (a) <= (c) + (d) && (d) <= (a) + (b) + (c));
    
    return ans;
}
