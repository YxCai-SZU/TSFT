/*@
    requires 0 <= a && a < b && b < c && c < d && d < e && e <= 123;
    requires k <= 123;
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
_Bool func(unsigned long long a, unsigned long long b, unsigned long long c,
           unsigned long long d, unsigned long long e, unsigned long long k)
{
    // Variable declarations
    _Bool result;
    
    //@ assert e - a <= 123;
    
    result = (e - a <= k);
    return result;
}

int main()
{
    // Variable declarations
    int __retres;
    
    __retres = 0;
    return __retres;
}
