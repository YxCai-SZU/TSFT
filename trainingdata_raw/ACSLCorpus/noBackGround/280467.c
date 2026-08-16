/*@
    requires (1 <= (r) && (r) <= 100);
    ensures ((\result) == (r) * (r) && (r) * (r) <= 10000);
*/
unsigned int func(unsigned int r)
{
    unsigned int res;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    
    res = r * r;
    return res;
}

int main()
{
    return 0;
}
