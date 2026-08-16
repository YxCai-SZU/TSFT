/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int result;
    
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    
    //@ assert a * b <= 100 * 100;
    
    result = a * b;
    
    //@ assert result == a * b;
    
    return result;
}

int main(void)
{
    return 0;
}
