/*@
    requires 1 <= x && x <= 5;
    requires 1 <= y && y <= 5;
    ensures \result <= 10;
*/
int calc_example_int(int x, int y)
{
    //@ assert 1 <= x && x <= 5;
    //@ assert 1 <= y && y <= 5;
    //@ assert x + y <= 10;
    
    int result;
    result = x + y;
    
    return result;
}

int main()
{
    return 0;
}
