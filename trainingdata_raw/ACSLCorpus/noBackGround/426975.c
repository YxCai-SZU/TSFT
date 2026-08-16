/*@
    requires (0 <= (a) && (a) <= 10) && (0 <= (b) && (b) <= 10);
    ensures \result == a + 2 * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    //@ assert (0 <= (b) && (b) <= 10);
    //@ assert 0 <= 2 * b && 2 * b <= 20;
    
    result = a + 2 * b;
    
    //@ assert result == a + 2 * b;
    return result;
}

int main(void)
{
    return 0;
}
