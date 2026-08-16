/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi;
    int result;
    int temp;
    int count;
    
    pi = 314;
    result = 0;
    temp = 2 * r * pi;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant temp >= 0;
        loop invariant temp == (2 * (r) * 314 - 100 * (count));
        loop invariant count <= (2 * r * pi) / 100;
        loop invariant result == count;
        loop assigns result, temp, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        result += 1;
        temp -= 100;
        count += 1;
    }
    
    //@ assert result == ((2 * (r) * 314) / 100);
    return result;
}

int main()
{
    return 0;
}
