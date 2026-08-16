/*@
    requires 1 <= N && N <= 10000;
    ensures \result == 1000 * ((N + 999) / 1000) - N;
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int temp;
    int count;
    
    result = 0;
    temp = N + 999;
    count = 0;
    
    /*@
        loop invariant 1 <= N && N <= 10000;
        loop invariant temp >= 0;
        loop invariant temp == N + 999 - 1000 * count;
        loop invariant count >= 0;
        loop invariant count <= (N + 999) / 1000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
    }
    
    //@ assert temp == N + 999 - 1000 * count;
    result = count * 1000;
    //@ assert result == 1000 * count;
    result -= N;
    //@ assert result == 1000 * count - N;
    
    return result;
}
