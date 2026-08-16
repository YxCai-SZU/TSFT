/*@
predicate valid_range(integer n, integer m) =
    1 <= n <= 10000 && 1 <= m <= 10000;

logic integer func(integer n, integer m) = n + m;

lemma func_bounds:
    \forall integer n, m;
    valid_range(n, m) ==> 2 <= func(n, m) <= 20000;

lemma add_no_underflow:
    \forall integer x, y;
    x >= 0 && y >= 0 && x + y <= 10000 ==>
    x + y >= 0 && x + y <= 10000;
*/

#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result == n + m;
    ensures 2 <= \result <= 20000;
*/
int compute_func(int n, int m) {
    int result;
    //@ assert valid_range(n, m);
    //@ assert 2 <= func(n, m) <= 20000;
    result = n + m;
    //@ assert result == n + m;
    //@ assert result >= 2;
    //@ assert result <= 20000;
    return result;
}

/*@
    requires x >= 0;
    requires y >= 0;
    requires x + y <= 10000;
    ensures \result == x + y;
    ensures \result >= 0;
    ensures \result <= 10000;
*/
int safe_add(int x, int y) {
    int sum;
    //@ assert x >= 0;
    //@ assert y >= 0;
    //@ assert x + y <= 10000;
    sum = x + y;
    //@ assert sum == x + y;
    //@ assert sum >= 0;
    //@ assert sum <= 10000;
    return sum;
}

int main() {
    int a;
    int b;
    int c;
    
    a = 5;
    b = 5;
    c = compute_func(a, b);
    //@ assert c == 10;
    
    return 0;
}
