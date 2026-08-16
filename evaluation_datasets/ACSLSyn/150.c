/* Real-world scenario: A simple arithmetic expression validator for a calculator app
   that checks if the result of a distributive multiplication is a "target" number (3,5,7).
   Data flow: Given three operands (x,y,z) each in [0,10], compute x*(y+z) and check if result is target.
*/

/*@
    predicate is_target(integer x) = x == 7 || x == 5 || x == 3;
 */

int func(int input)
{
    int ans;
    //@ assert 1 <= input <= 9;
    ans = (input == 7) || (input == 5) || (input == 3);
    //@ assert ans == 1 <==> is_target(input);
    return ans;
}

/*@
    lemma mul_is_distributive_add:
        \forall integer x, y, z;
            0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10 ==>
            x * (y + z) == x * y + x * z;

    lemma mul_is_associative:
        \forall integer x, y, z;
            0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10 ==>
            x * (y * z) == (x * y) * z;

    lemma mul_is_commutative:
        \forall integer x, y;
            0 <= x <= 10 && 0 <= y <= 10 ==>
            x * y == y * x;

    lemma upper_bound_check:
        \forall integer x, y;
            0 <= x <= 10 && 0 <= y <= 10 ==>
            x * y <= 100;
*/

#include <stdint.h>

int32_t test_distributive(int32_t x, int32_t y, int32_t z) {
    //@ assert 0 <= x && x <= 10;
    //@ assert 0 <= y && y <= 10;
    //@ assert 0 <= z && z <= 10;
    return x * (y + z);
}

int32_t test_associative(int32_t x, int32_t y, int32_t z) {
    //@ assert 0 <= x && x <= 10;
    //@ assert 0 <= y && y <= 10;
    //@ assert 0 <= z && z <= 10;
    return x * (y * z);
}

int32_t test_commutative(int32_t x, int32_t y) {
    //@ assert 0 <= x && x <= 10;
    //@ assert 0 <= y && y <= 10;
    return x * y;
}

uint32_t test_upper_bound(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x <= 10;
    //@ assert y <= 10;
    return x * y;
}

/* Synthesized function: validate_distributive_target
   Checks if the result of x*(y+z) is a target number (3,5,7).
   Requires: x,y,z in [0,10] and x*(y+z) in [1,9]
   Ensures: result indicates whether x*(y+z) is a target number
*/
int validate_distributive_target(int32_t x, int32_t y, int32_t z)
{
    int32_t product = test_distributive(x, y, z);
    
    int result = func(product);
    
    //@ assert (result == 1) <==> is_target(x * (y + z));
    
    return result;
}
