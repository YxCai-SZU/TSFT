
int func(int A, int P)
{
    int sum;
    int ans;
    int count;
    
    sum = A * 3 + P;
    ans = 0;
    count = 0;
    
    
    while (sum >= 2)
    {
        //@ assert sum >= 2;
        sum -= 2;
        ans += 1;
        count += 1;
    }
    
    //@ assert ans <= A * 3 + P;
    return ans;
}
