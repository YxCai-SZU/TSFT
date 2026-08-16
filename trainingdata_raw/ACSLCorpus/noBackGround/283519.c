/*@
    requires (1 <= (x) <= 1000000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
unsigned long long func(unsigned long long x)
{
    unsigned long long div500;
    unsigned long long under500;
    unsigned long long div5;
    unsigned long long res;
    
    div500 = x / 500;
    //@ assert div500 == x / 500;
    
    under500 = x % 500;
    //@ assert under500 == x % 500;
    
    div5 = under500 / 5;
    //@ assert div5 == under500 / 5;
    
    res = div500 * 1000 + div5 * 5;
    //@ assert res == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    
    return res;
}
