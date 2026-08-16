/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
int func(int N)
{
    int ans = 0;
    int temp = N;
    int count = 0;
    
    /*@
        loop invariant 0 <= temp <= N;
        loop invariant temp == N - 3 * count;
        loop invariant 0 <= count <= ((N) / 3);
        loop invariant ans == count;
        loop assigns temp, ans, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        //@ assert temp >= 3;
        temp -= 3;
        ans += 1;
        count += 1;
    }
    
    //@ assert ans == ((N) / 3);
    return ans;
}

int main()
{
    return 0;
}
