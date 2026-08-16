#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a_1;
    int64_t a_2;
    int64_t a_3;
    int64_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    
    a_1 = a;
    a_2 = a * a;
    a_3 = a * a * a;
    result = a_1 + a_2 + a_3;
    
    //@ assert result == a + a * a + a * a * a;
    
    return result;
}

int main(void)
{
    return 0;
}
