#include <stdint.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A + C || \result == B + D || 
            \result == A + D || \result == B + C;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
    uint32_t min1;
    uint32_t min2;
    uint32_t max_val;
    uint32_t result;
    
    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    
    // Calculate min1 = min(A, B)
    if (A < B) {
        min1 = A;
    } else {
        min1 = B;
    }
    //@ assert min1 == ((A) < (B) ? (A) : (B));
    
    // Calculate min2 = min(C, D)
    if (C < D) {
        min2 = C;
    } else {
        min2 = D;
    }
    //@ assert min2 == ((C) < (D) ? (C) : (D));
    
    // Calculate max_val = max(max(max(A, B), C), D)
    if (A > B) {
        max_val = A;
    } else {
        max_val = B;
    }
    //@ assert max_val == ((A) > (B) ? (A) : (B));
    
    if (C > max_val) {
        max_val = C;
    }
    //@ assert max_val == ((((A) > (B) ? (A) : (B))) > (C) ? (((A) > (B) ? (A) : (B))) : (C));
    
    if (D > max_val) {
        max_val = D;
    }
    //@ assert max_val == ((((((((A)) > ((B)) ? ((A)) : ((B)))) > ((C)) ? ((((A)) > ((B)) ? ((A)) : ((B)))) : ((C)))) > ((D)) ? ((((((A)) > ((B)) ? ((A)) : ((B)))) > ((C)) ? ((((A)) > ((B)) ? ((A)) : ((B)))) : ((C)))) : ((D))));
    
    if (min1 + max_val < min2) {
        //@ assert min1 + max_val < min2;
        result = A + C;
        //@ assert result == A + C;
    } else {
        //@ assert min1 + max_val >= min2;
        result = B + D;
        //@ assert result == B + D;
    }
    
    return result;
}
