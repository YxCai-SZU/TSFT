/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires y % 2 == 0;
    ensures \result == x + (y / 2);
*/
unsigned int func(unsigned int x, unsigned int y)
{
    unsigned int half_y;
    unsigned int temp_y;
    
    half_y = 0;
    temp_y = y;
    
    /*@
        loop invariant 0 <= half_y;
        loop invariant temp_y >= 0;
        loop invariant temp_y + 2 * half_y == y;
        loop invariant half_y <= y / 2;
        loop assigns half_y, temp_y;
    */
    while (temp_y >= 2)
    {
        half_y = half_y + 1;
        temp_y = temp_y - 2;
    }
    
    //@ assert half_y == y / 2;
    
    return x + half_y;
}

int main(void)
{
    return 0;
}
