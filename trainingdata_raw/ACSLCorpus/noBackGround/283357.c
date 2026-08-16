/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int count;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    //@ assert 1 <= a * b <= 10000;
    
    result = a * b;
    count = 0;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant 0 <= result <= a * b;
        loop invariant 0 <= count <= (a * b) / 2;
        loop invariant result == a * b - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        result -= 2;
        count += 1;
    }
    
    return count;
}

int main()
{
    return 0;
}
