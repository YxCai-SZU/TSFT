#include <stdbool.h>

/*@ predicate is_sum_condition(integer x, integer y, integer z, integer sum) =
       (sum == 3) ==> (x == 5 && y == 5 && z == 5) &&
       (sum == 2) ==> ((x == 5 && y == 5 && z != 5) || 
                       (y == 5 && z == 5 && x != 5) || 
                       (x == 5 && z == 5 && y != 5)) &&
       (sum == 1) ==> (x == 5 || y == 5 || z == 5) &&
       (sum == 0) ==> (x != 5 && y != 5 && z != 5);
*/

/*@ lemma sum_range: \forall integer x, y, z, a, b, c, sum;
       1 <= x <= 10 && 1 <= y <= 10 && 1 <= z <= 10 &&
       (x == 5 ==> a == 1) && (x != 5 ==> a == 0) &&
       (y == 5 ==> b == 1) && (y != 5 ==> b == 0) &&
       (z == 5 ==> c == 1) && (z != 5 ==> c == 0) &&
       sum == a + b + c ==>
       sum == 3 || sum == 2 || sum == 1 || sum == 0;
*/

/*@ requires 1 <= x <= 10;
    requires 1 <= y <= 10;
    requires 1 <= z <= 10;
    ensures \result == ((x == 5 && y == 5 && z == 5) || 
                       (x == 5 && y == 5 && z != 5) || 
                       (y == 5 && z == 5 && x != 5) || 
                       (x == 5 && z == 5 && y != 5));
*/
bool func(int x, int y, int z) {
    int a = 0;
    int b = 0;
    int c = 0;
    int sum = 0;

    if (x == 5) {
        a = 1;
    }
    if (y == 5) {
        b = 1;
    }
    if (z == 5) {
        c = 1;
    }

    sum = a + b + c;
    //@ assert sum == 3 || sum == 2 || sum == 1 || sum == 0;
    //@ assert is_sum_condition(x, y, z, sum);
    
    return sum >= 2;
}
