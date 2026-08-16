#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) <= 23 &&
        0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 &&
        0 <= (m2) && (m2) <= 59);
    ensures \result <= 24 * 60;
    assigns \nothing;
*/
uint32_t sleep_time(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2)
{
    uint32_t s1;
    uint32_t s2;
    uint32_t result;

    //@ assert (0 <= (h1) && (h1) <= 23 &&         0 <= (m1) && (m1) <= 59);
    //@ assert (0 <= (h2) && (h2) <= 23 &&         0 <= (m2) && (m2) <= 59);
    
    s1 = h1 * 60 + m1;
    s2 = h2 * 60 + m2;
    
    if (s2 > s1) {
        //@ assert ((h2) * 60 + (m2)) > ((h1) * 60 + (m1));
        //@ assert s2 - s1 <= 24 * 60;
        result = s2 - s1;
    } else {
        //@ assert ((h2) * 60 + (m2)) <= ((h1) * 60 + (m1));
        //@ assert 24 * 60 - s1 + s2 <= 24 * 60;
        result = 24 * 60 - s1 + s2;
    }
    
    //@ assert result <= 24 * 60;
    return result;
}

/*@
    requires (0 <= (h1) && (h1) <= 23 &&
        0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 &&
        0 <= (m2) && (m2) <= 59);
    requires result <= 24 * 60;
    ensures \true;
    assigns \nothing;
*/
void print_result(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t result)
{
    uint32_t s1;
    uint32_t s2;
    
    s1 = h1 * 60 + m1;
    s2 = h2 * 60 + m2;
    
    //@ assert s1 == ((h1) * 60 + (m1));
    //@ assert s2 == ((h2) * 60 + (m2));
}

/*@
    assigns \nothing;
*/
int main()
{
    uint32_t h1;
    uint32_t m1;
    uint32_t h2;
    uint32_t m2;
    uint32_t result;
    
    h1 = 10;
    m1 = 10;
    h2 = 20;
    m2 = 20;
    
    //@ assert (0 <= (h1) && (h1) <= 23 &&         0 <= (m1) && (m1) <= 59);
    //@ assert (0 <= (h2) && (h2) <= 23 &&         0 <= (m2) && (m2) <= 59);
    
    result = sleep_time(h1, m1, h2, m2);
    
    //@ assert result <= 24 * 60;
    print_result(h1, m1, h2, m2, result);
    
    return 0;
}
