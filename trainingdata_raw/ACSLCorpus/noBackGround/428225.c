/*@
    requires (1 <= (n) && (n) <= 1000);
    ensures \result >= 0;
    ensures \result * 3 <= n;
    ensures (\result - 1) * 3 < n;
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    int temp_n;
    int three;
    
    ans = 0;
    temp_n = n;
    three = 3;
    
    /*@
        loop invariant 1 <= n && n <= 1000;
        loop invariant n == temp_n + ans * three;
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant 0 <= ans && ans <= n / 3;
        loop assigns temp_n, ans;
        loop variant temp_n;
    */
    while (temp_n >= three)
    {
        temp_n -= three;
        ans += 1;
    }
    
    return ans;
}

int main(void)
{
    return 0;
}
