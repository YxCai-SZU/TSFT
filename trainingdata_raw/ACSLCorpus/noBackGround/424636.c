#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (a + b + 1) / 2;
*/
int func(int a, int b) {
    int sum;
    int result;
    int abs_sum;
    int divisor;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    sum = a + b + 1;
    result = 0;
    abs_sum = sum < 0 ? -sum : sum;
    divisor = 2;
    
    //@ assert 0 <= abs_sum <= 201;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= abs_sum <= 201;
        loop invariant abs_sum % 2 == sum % 2;
        loop invariant result * 2 == sum - abs_sum;
        loop assigns abs_sum, result;
        loop variant abs_sum;
    */
    while (abs_sum >= divisor) {
        abs_sum -= divisor;
        result += 1;
    }
    
    //@ assert sum == a + b + 1;
    //@ assert abs_sum == 0 || abs_sum == 1;
    
    if (sum < 0) {
        result = -result;
    }
    
    //@ assert result == (a + b + 1) / 2;
    
    return result;
}

int main() {
    return 0;
}
