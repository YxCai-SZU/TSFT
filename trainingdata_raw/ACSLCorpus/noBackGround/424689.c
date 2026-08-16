#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m) - ((m) * 100));
    ensures \result >= 0;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    int32_t n_value;
    int32_t m_value;
    
    n_value = 0;
    m_value = 0;
    
    if (n == 1) {
        n_value = 100;
    } else if (n == 2) {
        n_value = 200;
    } else if (n == 3) {
        n_value = 300;
    } else if (n == 4) {
        n_value = 400;
    } else if (n == 5) {
        n_value = 500;
    } else if (n == 6) {
        n_value = 600;
    } else if (n == 7) {
        n_value = 700;
    } else if (n == 8) {
        n_value = 800;
    } else if (n == 9) {
        n_value = 900;
    } else if (n == 10) {
        n_value = 1000;
    } else if (n == 11) {
        n_value = 1100;
    } else if (n == 12) {
        n_value = 1200;
    } else if (n == 13) {
        n_value = 1300;
    } else if (n == 14) {
        n_value = 1400;
    } else if (n == 15) {
        n_value = 1500;
    } else if (n == 16) {
        n_value = 1600;
    } else if (n == 17) {
        n_value = 1700;
    } else if (n == 18) {
        n_value = 1800;
    } else if (n == 19) {
        n_value = 1900;
    } else if (n == 20) {
        n_value = 2000;
    }
    
    if (m == 1) {
        m_value = 100;
    } else if (m == 2) {
        m_value = 200;
    } else if (m == 3) {
        m_value = 300;
    } else if (m == 4) {
        m_value = 400;
    } else if (m == 5) {
        m_value = 500;
    }
    
    result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m - (m * 100);
    
    //@ assert result == (100 * ((n) - (m)) + 1900 * (m) - ((m) * 100));
    
    return result;
}
