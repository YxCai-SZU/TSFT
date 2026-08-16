/*@
    requires ((x) <= 8 && (y) <= 8 && (z) <= 1000);
    ensures \result == ((x) * (y) + (z));
    ensures \result <= 1064;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    unsigned int product;
    unsigned int result;
    
    //@ assert 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 1000;
    
    product = x * y;
    //@ assert product <= 64;
    
    result = product + z;
    //@ assert result <= 1064;
    
    //@ assert result <= 4294967295;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
