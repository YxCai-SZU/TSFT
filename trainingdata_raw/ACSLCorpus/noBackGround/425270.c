#include <stdbool.h>

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result == ((a + b + c) % 3 == 0);
    assigns \nothing;
*/
bool can_distribute_evenly_c(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    bool result;
    
    sum = a + b + c;
    result = (sum % 3 == 0);
    
    //@ assert result == ((a + b + c) % 3 == 0);
    return result;
}

/*@ requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result <= 3 && \result >= 1;
    ensures \result == 3 ==> ((a + b + c) % 3 == 0);
    ensures \result == 2 ==> ((a + b + c) % 3 != 0 && (a + b + c) % 3 != 2);
    ensures \result == 1 ==> ((a + b + c) % 3 != 0 && (a + b + c) % 3 == 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    unsigned int result;
    
    sum = a + b + c;
    
    if (sum % 3 == 0) {
        //@ assert sum % 3 == 0;
        result = 3;
    } else if (sum % 3 == 2) {
        //@ assert sum % 3 != 0 && sum % 3 == 2;
        result = 1;
    } else {
        //@ assert sum % 3 != 0 && sum % 3 != 2;
        result = 2;
    }
    
    //@ assert result <= 3 && result >= 1;
    return result;
}
