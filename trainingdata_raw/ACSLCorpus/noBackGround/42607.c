/*@
    requires (1 <= (a) <= 10);
    ensures \result >= 0;
    ensures \result <= 30;
    assigns \nothing;
*/
int func(unsigned int a)
{
    int result = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= a;
        loop invariant result >= 0;
        loop invariant result <= ((i) * 3);
        loop assigns i, result;
        loop variant a - i;
    */
    while (i < a)
    {
        //@ assert result + 3 <= ((i + 1) * 3);
        result += 3;
        i += 1;
    }
    
    //@ assert result <= 30;
    return result;
}

int main()
{
    return 0;
}
