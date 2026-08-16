/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == (k * k) / 4;
    assigns \nothing;
*/
int func(int k)
{
    int result;
    int square;
    int count;
    
    //@ assert (2 <= (k) && (k) <= 100);
    //@ assert 4 <= k * k <= 10000;
    
    square = k * k;
    count = 0;
    
    /*@
        loop invariant 0 <= square;
        loop invariant square == k * k - 4 * count;
        loop invariant 0 <= count <= (k * k) / 4;
        loop assigns square, count;
        loop variant square;
    */
    while (square >= 4)
    {
        square -= 4;
        count += 1;
    }
    
    result = count;
    
    //@ assert result * 4 + square == k * k;
    //@ assert square >= 0 && square < 4;
    //@ assert result == (k * k) / 4;
    
    return result;
}
