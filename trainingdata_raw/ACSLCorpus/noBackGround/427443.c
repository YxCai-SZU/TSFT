/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int ans;
    
    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    
    //@ assert 4 <= a * b && a * b <= 10000;
    //@ assert a * b - a - b + 1 > 0;
    
    ans = a * b - a - b + 1;
    
    return ans;
}
