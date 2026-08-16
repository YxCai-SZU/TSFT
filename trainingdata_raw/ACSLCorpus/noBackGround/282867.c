/*@
    requires (0 <= (x) && (x) <= 100 && 0 <= (y) && (y) <= 100);
    ensures \result >= 0;
    ensures \result == x * y;
    assigns \nothing;
*/
int func(unsigned int x, unsigned int y)
{
    int result;

    //@ assert (0 <= (x) && (x) <= 100 && 0 <= (y) && (y) <= 100);
    //@ assert 0 <= x * y <= 10000;

    result = x * y;
    
    //@ assert result >= 0;
    //@ assert result == x * y;
    
    return result;
}

int main()
{
    return 0;
}
