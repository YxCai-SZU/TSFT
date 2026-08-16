#include <stdbool.h>

/*@ predicate is_heat_wave(integer n) = n >= 30; */

/*@
    requires -40 <= n <= 40;
    ensures \result == true <==> n >= 30;
    ensures \result == false <==> n < 30;
*/
bool func(int n)
{
    bool result;
    
    //@ assert -40 <= n <= 40;
    
    if (n >= 30) {
        //@ assert n >= 30;
        result = true;
    } else {
        //@ assert n < 30;
        result = false;
    }
    
    //@ assert result == true <==> n >= 30;
    return result;
}

/*@ lemma heat_wave_boundary: 
        \forall integer n; -40 <= n <= 40 ==> (is_heat_wave(n) ==> n >= 30); 
*/

int main()
{
    return 0;
}
