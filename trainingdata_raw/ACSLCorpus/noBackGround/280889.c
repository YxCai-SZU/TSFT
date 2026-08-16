/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == a * c + b * d;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int ans;
    
    //@ assert a * c <= 100 * 100;
    //@ assert b * d <= 100 * 100;
    
    ans = a * c + b * d;
    return ans;
}

int main()
{
    return 0;
}
