/*@
    requires \true;
    ensures \result == (x % 3 == 0);
*/
_Bool is_multiple_of_three(unsigned int x)
{
    //@ assert 9 % 3 == 0;
    //@ assert 10 % 3 != 0;
    
    return x % 3 == 0;
}

int main()
{
    unsigned int x;
    _Bool result;
    
    result = is_multiple_of_three(9);
    //@ assert result == 1;
    
    result = is_multiple_of_three(10);
    //@ assert result == 0;
    
    return 0;
}
