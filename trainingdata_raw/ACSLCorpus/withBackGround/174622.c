#include <stdbool.h>

/*@
    predicate Y_condition(integer Y, integer count, integer temp_Y) =
        0 <= temp_Y <= Y &&
        0 <= count <= Y / 5 &&
        temp_Y == Y - 5 * count;
*/

/*@
    logic integer compute_count(integer Y) =
        Y / 5;
*/

/*@
    lemma loop_decreases:
        \forall integer Y, count, temp_Y;
        Y_condition(Y, count, temp_Y) && temp_Y >= 5 ==>
            temp_Y - 5 < temp_Y;
*/

/*@
    requires 1 <= a <= 1000000000000;
    ensures \result == (a / 100 >= (a % 100) / 5 + (a % 100) % 5);
*/
bool func(unsigned long long a) {
    unsigned long long t;
    unsigned long long Y;
    unsigned long long count;
    unsigned long long temp_Y;
    
    t = a / 100;
    Y = a % 100;
    count = 0;
    temp_Y = Y;
    
    /*@
        loop invariant 0 <= temp_Y <= Y;
        loop invariant 0 <= count <= Y / 5;
        loop invariant temp_Y == Y - 5 * count;
        loop assigns count, temp_Y;
        loop variant temp_Y;
    */
    while (temp_Y >= 5) {
        //@ assert Y_condition(Y, count, temp_Y);
        count += 1;
        temp_Y -= 5;
        //@ assert Y_condition(Y, count, temp_Y);
    }
    
    //@ assert temp_Y == Y % 5;
    //@ assert count == Y / 5;
    return t >= (count + temp_Y);
}

int main() {
    return 0;
}
