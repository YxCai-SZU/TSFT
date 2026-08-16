#include <stdint.h>

/*@
    predicate valid_input(integer i) = 0 <= i <= 65535;
    
    logic integer triangular_number(integer i) = (i * (i + 1)) / 2;
    
    lemma triangular_bound: \forall integer i; valid_input(i) ==> triangular_number(i) <= i * i;
    lemma no_overflow: \forall integer i; valid_input(i) ==> triangular_number(i) <= 2147483647;
*/

/*@
    requires valid_input(i);
    ensures \result == triangular_number(i);
    ensures \result <= i * i;
    assigns \nothing;
*/
uint32_t count_triangular_number(uint32_t i)
{
    //@ assert valid_input(i);
    
    //@ assert triangular_number(i) <= 2147483647;
    //@ assert triangular_number(i) <= i * i;
    
    return (i * (i + 1)) / 2;
}
