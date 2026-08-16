#include <stddef.h>

/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == ((((k)) / 2) * ((((k)) + 1) / 2));
    assigns \nothing;
*/
size_t func(size_t k) {
    size_t k_2;
    size_t k_1_2;
    size_t res;
    
    //@ assert (2 <= (k) && (k) <= 100);
    
    k_2 = k / 2;
    k_1_2 = (k + 1) / 2;
    
    //@ assert k_2 == ((k) / 2);
    //@ assert k_1_2 == (((k) + 1) / 2);
    
    //@ assert k_2 * k_1_2 == ((((k)) / 2) * ((((k)) + 1) / 2));
    
    //@ assert k_2 * k_1_2 <= 50 * 50;
    
    res = k_2 * k_1_2;
    
    //@ assert res == ((((k)) / 2) * ((((k)) + 1) / 2));
    
    return res;
}

int main() {
    return 0;
}
