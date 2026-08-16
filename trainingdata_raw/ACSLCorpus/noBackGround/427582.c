#include <stdint.h>

/*@
    requires 1 <= a && a <= 123;
    requires 1 <= b && b <= 123;
    requires 1 <= c && c <= 123;
    requires 1 <= d && d <= 123;
    requires 1 <= e && e <= 123;
    ensures \result <= 1200;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e) {
    uint32_t result = 0;
    
    //@ assert (1 <= (a) && (a) <= 123);
    //@ assert (1 <= (b) && (b) <= 123);
    //@ assert (1 <= (c) && (c) <= 123);
    //@ assert (1 <= (d) && (d) <= 123);
    //@ assert (1 <= (e) && (e) <= 123);
    
    result += a > 10 ? a - 10 : 0;
    //@ assert result == ((a) > 10 ? (a) - 10 : 0);
    
    result += b > 10 ? b - 10 : 0;
    //@ assert result == ((a) > 10 ? (a) - 10 : 0) + ((b) > 10 ? (b) - 10 : 0);
    
    result += c > 10 ? c - 10 : 0;
    //@ assert result == ((a) > 10 ? (a) - 10 : 0) + ((b) > 10 ? (b) - 10 : 0) + ((c) > 10 ? (c) - 10 : 0);
    
    result += d > 10 ? d - 10 : 0;
    //@ assert result == ((a) > 10 ? (a) - 10 : 0) + ((b) > 10 ? (b) - 10 : 0) + ((c) > 10 ? (c) - 10 : 0) + ((d) > 10 ? (d) - 10 : 0);
    
    result += e > 10 ? e - 10 : 0;
    //@ assert result == ((((a)) > 10 ? ((a)) - 10 : 0) + (((b)) > 10 ? ((b)) - 10 : 0) + (((c)) > 10 ? ((c)) - 10 : 0) + (((d)) > 10 ? ((d)) - 10 : 0) + (((e)) > 10 ? ((e)) - 10 : 0));
    
    //@ assert ((((a)) > 10 ? ((a)) - 10 : 0) + (((b)) > 10 ? ((b)) - 10 : 0) + (((c)) > 10 ? ((c)) - 10 : 0) + (((d)) > 10 ? ((d)) - 10 : 0) + (((e)) > 10 ? ((e)) - 10 : 0)) <= 1200;
    return result;
}
