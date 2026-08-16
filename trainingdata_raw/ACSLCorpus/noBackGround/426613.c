/*@
    requires (400 <= (x) && (x) <= 1999);
    ensures \result == (10 - (((x) - 400) / 200));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int temp_x;
    int count;
    
    result = 0;
    temp_x = x - 400;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_x && temp_x <= x - 400;
        loop invariant 0 <= count && count <= (x - 400) / 200;
        loop invariant temp_x == x - 400 - 200 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 200)
    {
        //@ assert temp_x >= 200;
        temp_x -= 200;
        count += 1;
    }
    
    result = 10 - count;
    return result;
}

int main()
{
    return 0;
}
