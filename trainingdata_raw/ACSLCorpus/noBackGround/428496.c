#include <stdbool.h>

/*@
    requires 1 <= x <= 10000;
    ensures \result == (x % 3 == 0 || x % 5 == 0);
    assigns \nothing;
*/
bool func(int x) {
    bool is_divisible_by_3;
    bool is_divisible_by_5;
    int temp_x;
    int count_3;
    int count_5;
    
    is_divisible_by_3 = false;
    temp_x = x;
    count_3 = 0;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x <= x;
        loop invariant count_3 >= 0;
        loop invariant temp_x == x - 3 * count_3;
        loop assigns temp_x, count_3;
        loop variant temp_x;
    */
    while (temp_x >= 3) {
        //@ assert temp_x == x - 3 * count_3;
        temp_x -= 3;
        count_3 += 1;
        //@ assert temp_x == x - 3 * count_3;
    }
    
    if (temp_x == 0) {
        is_divisible_by_3 = true;
    }
    
    is_divisible_by_5 = false;
    temp_x = x;
    count_5 = 0;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= temp_x <= x;
        loop invariant count_5 >= 0;
        loop invariant temp_x == x - 5 * count_5;
        loop assigns temp_x, count_5;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        //@ assert temp_x == x - 5 * count_5;
        temp_x -= 5;
        count_5 += 1;
        //@ assert temp_x == x - 5 * count_5;
    }
    
    if (temp_x == 0) {
        is_divisible_by_5 = true;
    }
    
    //@ assert is_divisible_by_3 == (x % 3 == 0);
    //@ assert is_divisible_by_5 == (x % 5 == 0);
    return is_divisible_by_3 || is_divisible_by_5;
}
