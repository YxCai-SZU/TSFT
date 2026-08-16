#include <stdbool.h>

/*@
    predicate division_property(integer a, integer b) =
        b != 0 && a >= 0 && b > 0 ==> a / b <= a;
 */

/*@
    lemma division_lemma:
        \forall integer a, b;
            b != 0 && a >= 0 && b > 0 ==> a / b <= a;
 */

/*@
    requires b != 0;
    requires a >= 0;
    requires b > 0;
    ensures \result <= a;
    assigns \nothing;
 */
int lemma_division(int a, int b)
{
    //@ assert b != 0;
    //@ assert a >= 0 && b > 0;
    //@ assert a / b <= a;
    return a / b;
}

int main()
{
    int a;
    int b;
    int result;
    
    a = 10;
    b = 2;
    result = lemma_division(a, b);
    
    return 0;
}
