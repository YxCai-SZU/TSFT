#include <stdbool.h>

/*@
    requires \valid(out);
    requires m % 2 == 0;
    requires m >= 0;
    assigns *out;
    ensures *out >= 0;
    ensures *out == m * m;
*/
void compute_even_square(int m, int *out) {
    int result;
    int temp_m;
    
    temp_m = m;
    result = temp_m * temp_m;
    
    //@ assert result >= 0;
    //@ assert result == m * m;
    
    *out = result;
}

int main() {
    int output;
    compute_even_square(4, &output);
    return 0;
}
