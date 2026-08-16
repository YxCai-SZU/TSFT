/*@
    requires (0 <= (a) && (a) <= 1000000000);
    ensures \result == ((a) / 3);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int count = 0;
    unsigned int temp = a;
    
    /*@
        loop invariant ((temp) <= (a) && (temp) >= 0 && (count) <= (a) / 3 && 
        (a) <= 1000000000 && (temp) + 3 * (count) == (a));
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3)
    {
        //@ assert temp >= 3;
        temp -= 3;
        count += 1;
        //@ assert temp + 3 * count == a;
    }
    
    //@ assert temp < 3 && temp >= 0;
    //@ assert count <= a / 3;
    //@ assert a <= 1000000000;
    //@ assert temp + 3 * count == a;
    //@ assert count == a / 3;
    
    return count;
}

int main()
{
    return 0;
}
