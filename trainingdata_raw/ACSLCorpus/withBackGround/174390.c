#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer func_result(integer n) =
        n == 1 ? 1 :
        n == 2 ? 1 :
        n == 3 ? 2 :
        n == 4 ? 5 :
        n == 5 ? 14 :
        n == 6 ? 15 :
        n == 7 ? 51 :
        4;

    lemma result_range: \forall integer n; valid_n(n) ==>
        (func_result(n) == 1 || func_result(n) == 2 || 
         func_result(n) == 5 || func_result(n) == 14 || 
         func_result(n) == 15 || func_result(n) == 51 || 
         func_result(n) == 4);
*/

/*@
    requires valid_n(n);
    ensures \result == func_result(n);
    ensures \result == 1 || \result == 2 || \result == 5 || 
            \result == 14 || \result == 15 || \result == 51 || 
            \result == 4;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    if (n == 1) {
        result = 1;
        //@ assert result == 1;
    } else if (n == 2) {
        result = 1;
        //@ assert result == 1;
    } else if (n == 3) {
        result = 2;
        //@ assert result == 2;
    } else if (n == 4) {
        result = 5;
        //@ assert result == 5;
    } else if (n == 5) {
        result = 14;
        //@ assert result == 14;
    } else if (n == 6) {
        result = 15;
        //@ assert result == 15;
    } else if (n == 7) {
        result = 51;
        //@ assert result == 51;
    } else {
        //@ assert n > 7;
        result = 4;
        //@ assert result == 4;
    }
    
    return result;
}

int main() {
    return 0;
}
