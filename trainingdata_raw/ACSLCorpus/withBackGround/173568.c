/*@
    predicate bounds(integer x) = -40 <= x <= 40;
    predicate is_integer(integer x) = x == (integer)x;
    predicate result_condition(integer x, integer r) = r == (x >= 30);
*/

/*@
    requires bounds(x);
    requires is_integer(x);
    ensures result_condition(x, \result);
*/
int func(int x) {
    int start = 0;
    int end = 10;
    int current_time = 0;

    /*@
        loop invariant start <= current_time;
        loop invariant current_time <= end;
        loop invariant bounds(x);
        loop invariant is_integer(x);
        loop assigns current_time;
        loop variant end - current_time;
    */
    while (current_time < end) {
        current_time += 1;
    }

    //@ assert x >= 30 ==> x >= 30;
    return x >= 30;
}
