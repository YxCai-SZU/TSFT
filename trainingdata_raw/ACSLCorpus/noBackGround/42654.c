#include <stdbool.h>
#include <stddef.h>

/*@ requires (3 <= (n) && (n) <= 100 &&
      1 <= (a) && (a) < (b) && (b) < 20);
    requires (\valid((p) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 20);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int a, int b, int *p) {
    int t_list[3];
    int i;
    int min_value;
    
    t_list[0] = 0;
    t_list[1] = 0;
    t_list[2] = 0;
    
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \valid(&t_list[0]) && \valid(&t_list[1]) && \valid(&t_list[2]);
        loop invariant 0 <= t_list[0] && t_list[0] <= n;
        loop invariant 0 <= t_list[1] && t_list[1] <= n;
        loop invariant 0 <= t_list[2] && t_list[2] <= n;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= p[j] && p[j] <= 20;
        loop invariant t_list[0] + t_list[1] + t_list[2] == i;
        loop assigns i, t_list[0], t_list[1], t_list[2];
        loop variant n - i;
    */
    while (i < n) {
        int task = p[i];
        if (task <= a) {
            //@ assert 1 <= task && task <= a;
            t_list[0] = t_list[0] + 1;
        } else if (task <= b) {
            //@ assert a < task && task <= b;
            t_list[1] = t_list[1] + 1;
        } else {
            //@ assert b < task && task <= 20;
            t_list[2] = t_list[2] + 1;
        }
        i = i + 1;
    }
    
    min_value = t_list[0];
    i = 1;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant \valid(&t_list[0]) && \valid(&t_list[1]) && \valid(&t_list[2]);
        loop invariant min_value >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= t_list[k];
        loop invariant \exists integer k; 0 <= k < i && min_value == t_list[k];
        loop assigns i, min_value;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (t_list[i] < min_value) {
            min_value = t_list[i];
        }
        i = i + 1;
    }
    
    //@ assert min_value == (((t_list[0]) <= (t_list[1]) && (t_list[0]) <= (t_list[2])) ? (t_list[0]) : (((t_list[1]) <= (t_list[2])) ? (t_list[1]) : (t_list[2])));
    return min_value;
}
