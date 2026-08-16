#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a * 2 + 2) / 2 == b || (a * 3 + 1) / 2 == b || (a * 3 + 2) / 3 == b);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int a2 = a * 2 + 2;
    unsigned int a3 = a * 3 + 1;
    unsigned int a4 = a * 3 + 2;
    unsigned int b2 = 0;
    unsigned int b3 = 0;
    unsigned int b4 = 0;
    unsigned int temp_b2 = 0;
    unsigned int count_b2 = 0;
    unsigned int temp_b3 = 0;
    unsigned int count_b3 = 0;
    unsigned int temp_b4 = 0;
    unsigned int count_b4 = 0;
    
    // First division by 2
    temp_b2 = a2;
    count_b2 = 0;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_b2 >= 0;
        loop invariant temp_b2 == a2 - 2 * count_b2;
        loop invariant count_b2 >= 0;
        loop invariant count_b2 <= a2 / 2;
        loop assigns temp_b2, count_b2;
    */
    while (temp_b2 >= 2)
    {
        temp_b2 -= 2;
        count_b2 += 1;
    }
    b2 = count_b2;
    
    // Second division by 2
    temp_b3 = a3;
    count_b3 = 0;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_b3 >= 0;
        loop invariant temp_b3 == a3 - 2 * count_b3;
        loop invariant count_b3 >= 0;
        loop invariant count_b3 <= a3 / 2;
        loop assigns temp_b3, count_b3;
    */
    while (temp_b3 >= 2)
    {
        temp_b3 -= 2;
        count_b3 += 1;
    }
    b3 = count_b3;
    
    // Division by 3
    temp_b4 = a4;
    count_b4 = 0;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp_b4 >= 0;
        loop invariant temp_b4 == a4 - 3 * count_b4;
        loop invariant count_b4 >= 0;
        loop invariant count_b4 <= a4 / 3;
        loop assigns temp_b4, count_b4;
    */
    while (temp_b4 >= 3)
    {
        temp_b4 -= 3;
        count_b4 += 1;
    }
    b4 = count_b4;
    
    //@ assert b2 == (a * 2 + 2) / 2;
    //@ assert b3 == (a * 3 + 1) / 2;
    //@ assert b4 == (a * 3 + 2) / 3;
    
    return (b2 == b) || (b3 == b) || (b4 == b);
}

int main()
{
    return 0;
}
