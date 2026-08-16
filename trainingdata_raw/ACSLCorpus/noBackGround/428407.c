#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long tmp_a = a;
    unsigned long tmp_b = b;
    unsigned long tmp_c = c;
    
    //@ assert 1 <= tmp_a <= 100 && 1 <= tmp_b <= 100 && 1 <= tmp_c <= 100;
    
    if (tmp_a <= tmp_b && tmp_a <= tmp_c)
    {
        //@ assert tmp_a <= tmp_b && tmp_a <= tmp_c;
    }
    else if (tmp_b <= tmp_a && tmp_b <= tmp_c)
    {
        unsigned long temp = tmp_a;
        tmp_a = tmp_b;
        tmp_b = temp;
        //@ assert tmp_a <= tmp_b && tmp_a <= tmp_c;
    }
    else
    {
        unsigned long temp = tmp_a;
        tmp_a = tmp_c;
        tmp_c = temp;
        //@ assert tmp_a <= tmp_b && tmp_a <= tmp_c;
    }
    
    //@ assert tmp_a + tmp_b <= 200;
    //@ assert tmp_a + tmp_c <= 200;
    //@ assert tmp_b + tmp_c <= 200;
    
    return tmp_a == tmp_b + tmp_c || tmp_b == tmp_a + tmp_c || tmp_c == tmp_a + tmp_b;
}
