/*@
    requires (1 <= (a) && (a) <= 123) && (1 <= (b) && (b) <= 123) && (1 <= (c) && (c) <= 123) && (1 <= (d) && (d) <= 123) && (1 <= (e) && (e) <= 123);
    ensures \result <= a + b + c + d + e;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, 
                  unsigned int d, unsigned int e)
{
    unsigned int s;
    unsigned int ans;
    unsigned int tmp;
    unsigned int i;
    
    s = a + b + c + d + e;
    ans = 0;
    tmp = s;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant tmp <= s;
        loop invariant ans <= i;
        //@ assert s <= a + b + c + d + e;
        loop invariant (1 <= (a) && (a) <= 123) && (1 <= (b) && (b) <= 123) && (1 <= (c) && (c) <= 123) && (1 <= (d) && (d) <= 123) && (1 <= (e) && (e) <= 123);
        loop assigns i, tmp, ans;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        tmp = (tmp < 10) ? tmp : tmp - 10;
        ans += 1;
        if (tmp == 0) break;
        i += 1;
    }
    
    return ans;
}

int main(void)
{
    return 0;
}
