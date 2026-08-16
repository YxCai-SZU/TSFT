/*@
    requires (1 <= (X) && (X) <= 1000000000);
    ensures \result == (X / 3) + (X % 3);
    assigns \nothing;
*/
long func(long X)
{
    long result = 0;
    long temp_X = X;
    long count = 0;
    
    /*@
        loop invariant 0 <= temp_X && temp_X <= X;
        loop invariant 0 <= count && count <= X / 3;
        loop invariant temp_X == X - 3 * count;
        loop assigns temp_X, count;
        loop variant temp_X;
    */
    while (temp_X >= 3)
    {
        temp_X -= 3;
        count += 1;
    }
    
    result = count + temp_X;
    
    //@ assert result == (X / 3) + (X % 3);
    return result;
}

int main()
{
    return 0;
}
