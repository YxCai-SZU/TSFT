/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * 800 - ((a) / 15) * 200);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int result;
    unsigned int count;
    unsigned int temp;
    
    result = a * 800;
    count = 0;
    temp = a;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 0 <= count && count <= a / 15;
        loop invariant temp == a - count * 15;
        loop invariant result == a * 800;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 15)
    {
        temp -= 15;
        count += 1;
    }
    
    result = result - count * 200;
    
    //@ assert result == ((a) * 800 - ((a) / 15) * 200);
    return result;
}

int main(void)
{
    return 0;
}
