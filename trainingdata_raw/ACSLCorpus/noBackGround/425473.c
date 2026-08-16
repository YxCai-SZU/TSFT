/*@
    requires 1 <= X <= 1000000000;
    ensures \result == 1000 * (X / 500) + 5 * (X % 500 / 5);
*/
long func(long X)
{
    long div500;
    long tempX;
    long div5;
    long ans;
    
    div500 = 0;
    tempX = X;
    
    /*@
        loop invariant 1 <= X <= 1000000000;
        loop invariant 0 <= tempX <= X;
        loop invariant div500 >= 0;
        loop invariant tempX == X - 500 * div500;
        loop assigns tempX, div500;
    */
    while (tempX >= 500)
    {
        //@ assert tempX >= 500;
        tempX -= 500;
        div500 += 1;
    }
    
    div5 = 0;
    
    /*@
        loop invariant 1 <= X <= 1000000000;
        loop invariant 0 <= tempX <= X;
        loop invariant div500 >= 0;
        loop invariant div5 >= 0;
        loop invariant tempX == X - 500 * div500 - 5 * div5;
        loop assigns tempX, div5;
    */
    while (tempX >= 5)
    {
        //@ assert tempX >= 5;
        tempX -= 5;
        div5 += 1;
    }
    
    ans = 1000 * div500 + 5 * div5;
    
    //@ assert ans == 1000 * (X / 500) + 5 * (X % 500 / 5);
    return ans;
}

int main()
{
    return 0;
}
