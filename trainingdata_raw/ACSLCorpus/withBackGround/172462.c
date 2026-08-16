#include <stdint.h>

/*@ predicate valid_radius(integer r) = 1 <= r <= 100; */
/*@ predicate valid_circumference(integer c) = 0 <= c <= 628; */
/*@ logic integer pi_approx = 314; */
/*@ logic integer divisor = 10000; */

/*@ lemma temp_bounds: \forall integer r; valid_radius(r) ==> 
      0 <= 2 * r * pi_approx <= 2 * 100 * 314; */

/*@ requires valid_radius(r);
    ensures valid_circumference(\result);
    assigns \nothing;
 */
int32_t func(int32_t r) {
    int32_t circumference;
    int32_t temp;
    int32_t divisor_local;
    
    circumference = 0;
    temp = 2 * r * 314;
    divisor_local = 10000;
    
    /*@ loop invariant valid_radius(r);
        loop invariant pi_approx == 314;
        loop invariant 2 * r * pi_approx == 2 * r * 314;
        loop invariant 0 <= circumference <= 2 * r * pi_approx / divisor;
        loop invariant temp == 2 * r * pi_approx - circumference * divisor;
        loop invariant 0 <= temp <= 2 * 100 * 314;
        loop invariant 0 <= circumference * divisor <= 2 * 100 * 314;
        loop assigns circumference, temp;
        loop variant temp;
     */
    while (temp >= divisor_local) {
        //@ assert temp >= divisor_local;
        temp -= divisor_local;
        circumference += 1;
        //@ assert temp == 2 * r * pi_approx - circumference * divisor;
    }
    
    //@ assert 0 <= circumference <= 628;
    return circumference;
}

int main() {
    return 0;
}
