#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 10000; */

/*@ predicate loop_inv(integer n, integer temp_n, integer count) =
    is_valid_n(n) &&
    temp_n >= 0 &&
    n == temp_n + 3 * count &&
    count >= 0 &&
    count <= n / 3; */

/*@ lemma division_property: 
    \forall integer n, integer count; 
    is_valid_n(n) && n == 3 * count ==> count == n / 3; */

/*@ requires is_valid_n(n);
    ensures \result == n / 3;
    assigns \nothing;
 */
int func(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    /*@ loop invariant loop_inv(n, temp_n, count);
        loop assigns temp_n, count;
        loop variant temp_n;
     */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n = temp_n - 3;
        count = count + 1;
        //@ assert n == temp_n + 3 * count;
    }
    
    //@ assert n == temp_n + 3 * count;
    //@ assert temp_n < 3;
    //@ assert count == n / 3;
    result = count;
    return result;
}

/*@ predicate map_contains_key(int *m, integer key, integer value) = 
    \valid(m + key) && m[key] == value; */

/*@ requires \valid(m + (0..2));
    ensures map_contains_key(m, 1, 10);
    ensures map_contains_key(m, 2, 20);
    assigns m[1], m[2];
 */
void initialize_map(int* m)
{
    //@ assert \valid(m + (0..2));
    m[1] = 10;
    //@ assert m[1] == 10;
    m[2] = 20;
    //@ assert m[2] == 20;
}
