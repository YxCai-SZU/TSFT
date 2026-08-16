#include <limits.h>

/*@
    requires \valid(max);
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    assigns *max;
    ensures (((*max) == (a) || (*max) == (b) || (*max) == (c)) &&
        (*max) >= (a) && (*max) >= (b) && (*max) >= (c));
 */
void maximum_of_three(int a, int b, int c, int *max) {
    int local_max;
    
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;
    
    if (a > b) {
        if (a > c) {
            local_max = a;
        } else {
            local_max = c;
        }
    } else {
        if (b > c) {
            local_max = b;
        } else {
            local_max = c;
        }
    }
    
    *max = local_max;
    
    //@ assert (((*max) == (a) || (*max) == (b) || (*max) == (c)) &&         (*max) >= (a) && (*max) >= (b) && (*max) >= (c));
}
