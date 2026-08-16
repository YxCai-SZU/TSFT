#include <limits.h>

/*@ predicate is_valid_input(integer a, integer b, integer c) =
      1 <= a <= 100 &&
      1 <= b <= 100 &&
      1 <= c <= 100;
*/

/*@ logic integer func_result(integer a, integer b, integer c) =
      (a == b && b == c) ? 1 :
      (a == b || a == c || b == c) ? 2 : 3;
*/

/*@ lemma result_range: 
      \forall integer a, b, c; 
      is_valid_input(a, b, c) ==> 
      1 <= func_result(a, b, c) <= 3;
*/

/*@ requires is_valid_input(a, b, c);
    ensures \result >= 1 && \result <= 3;
    ensures \result == func_result(a, b, c);
*/
int func(int a, int b, int c) {
    //@ assert is_valid_input(a, b, c);
    
    int result;
    
    if (a == b && b == c) {
        result = 1;
    } else if (a == b || a == c || b == c) {
        result = 2;
    } else {
        result = 3;
    }
    
    //@ assert result == func_result(a, b, c);
    //@ assert result >= 1 && result <= 3;
    return result;
}

/*@ predicate valid_n(integer n) = 1 <= n <= 100;
*/

/*@ logic integer func2_result(integer n) = n + 2;
*/

/*@ lemma func2_range: 
      \forall integer n; 
      valid_n(n) ==> 
      func2_result(n) >= 3 && func2_result(n) <= 102;
*/

/*@ requires valid_n(n);
    ensures \result == n + 2;
    ensures \result >= 3 && \result <= 102;
*/
int func2(int n) {
    //@ assert valid_n(n);
    
    //@ assert n + 2 >= 3;
    //@ assert n + 2 <= 102;
    
    int result = n + 2;
    
    //@ assert result == func2_result(n);
    //@ assert result >= 3 && result <= 102;
    return result;
}

int main() {
    return 0;
}
