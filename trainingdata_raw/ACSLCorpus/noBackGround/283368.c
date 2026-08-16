#include <stdbool.h>

/*@ requires A <= B && A <= 1000 && B >= 0 && C >= 0;
    ensures \result <==> (A <= C && C <= B);
    assigns \nothing;
*/
bool is_between(int A, int B, int C) {
    //@ assert A <= B;
    //@ assert A <= 1000;
    //@ assert B >= 0;
    //@ assert C >= 0;
    
    return (A <= C) && (C <= B);
}
