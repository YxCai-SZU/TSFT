/*@
requires 1 <= a && a < b && b <= 10;
ensures 1 <= a && a < b && b <= 10;
assigns \nothing;
*/
void example11(int a, int b)
{
    //@ assert 1 <= a;
    //@ assert a < b;
    //@ assert b <= 10;
}

int main()
{
    int a;
    int b;
    
    return 0;
}
