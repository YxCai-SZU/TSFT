#include <stdint.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 20 &&
        (input)[1] >= 1 && (input)[1] <= 20 &&
        (input)[2] >= 1 && (input)[2] <= 20);
    ensures \result <= input[0] + input[1] + input[2];
    assigns \nothing;
*/
uint32_t count_nounphrases(uint32_t input[3]) {
    uint32_t total_ways;
    uint32_t a;
    uint32_t b;
    uint32_t c;
    
    total_ways = 0;
    a = input[0];
    b = input[1];
    c = input[2];
    
    //@ assert a >= 1 && a <= 20;
    //@ assert b >= 1 && b <= 20;
    //@ assert c >= 1 && c <= 20;
    
    total_ways += (a > 0 && b > 0 && c > 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a > 0 && b > 0 && c == 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a > 0 && b == 0 && c > 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a == 0 && b > 0 && c > 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a > 0 && b == 0 && c == 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a == 0 && b > 0 && c == 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    total_ways += (a == 0 && b == 0 && c > 0) ? 1 : 0;
    //@ assert total_ways <= a + b + c;
    
    return total_ways;
}
