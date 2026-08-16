#include <stdbool.h>

/*@
    predicate is_mod_zero(integer x) = x % 3 == 0;
    logic integer mod_3(integer x) = x % 3;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(long a, long b)
{
    long mod_3_a;
    long mod_3_b;
    long mod_3_sum;
    long sum;
    long abs_a;
    long abs_b;
    long abs_sum;
    
    // Compute mod_3_a
    if (a < 0) {
        abs_a = -a;
    } else {
        abs_a = a;
    }
    
    /*@
        loop invariant 0 <= abs_a <= 100;
        loop invariant a < 0 ==> (-a) % 3 == (-abs_a) % 3;
        loop invariant a >= 0 ==> a % 3 == abs_a % 3;
        loop assigns abs_a;
    */
    while (abs_a >= 3) {
        abs_a -= 3;
    }
    
    if (a < 0) {
        mod_3_a = -abs_a;
    } else {
        mod_3_a = abs_a;
    }
    
    // Compute mod_3_b
    if (b < 0) {
        abs_b = -b;
    } else {
        abs_b = b;
    }
    
    /*@
        loop invariant 0 <= abs_b <= 100;
        loop invariant b < 0 ==> (-b) % 3 == (-abs_b) % 3;
        loop invariant b >= 0 ==> b % 3 == abs_b % 3;
        loop assigns abs_b;
    */
    while (abs_b >= 3) {
        abs_b -= 3;
    }
    
    if (b < 0) {
        mod_3_b = -abs_b;
    } else {
        mod_3_b = abs_b;
    }
    
    // Compute mod_3_sum
    sum = a + b;
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    /*@
        loop invariant 0 <= abs_sum <= 200;
        loop invariant sum < 0 ==> (-sum) % 3 == (-abs_sum) % 3;
        loop invariant sum >= 0 ==> sum % 3 == abs_sum % 3;
        loop assigns abs_sum;
    */
    while (abs_sum >= 3) {
        abs_sum -= 3;
    }
    
    if (sum < 0) {
        mod_3_sum = -abs_sum;
    } else {
        mod_3_sum = abs_sum;
    }
    
    //@ assert mod_3_a == a % 3;
    //@ assert mod_3_b == b % 3;
    //@ assert mod_3_sum == (a + b) % 3;
    
    return mod_3_a == 0 || mod_3_b == 0 || mod_3_sum == 0;
}

int main()
{
    return 0;
}
