#include <stdint.h>

/*@ requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
 */
int32_t func(int32_t r) {
    int32_t pi;
    int32_t area;
    
    pi = 3;
    
    //@ assert (1 <= (r) && (r) <= 100);
    
    //@ assert pi * r <= 300;
    
    //@ assert pi * r * r <= 30000;
    
    area = pi * r * r;
    
    //@ assert area == 3 * r * r;
    
    return area;
}

int main() {
    return 0;
}
