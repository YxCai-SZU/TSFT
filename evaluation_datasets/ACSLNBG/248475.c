#include <stdint.h>


int32_t func(int32_t n, int32_t m) {
    int32_t n_local;
    int32_t m_local;
    int32_t sum;
    int32_t result;
    int32_t count;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    n_local = (n >= 0) ? n : 0;
    m_local = (m >= 0) ? m : 0;
    sum = n_local + m_local;
    result = 0;
    count = 0;
    
    
    while (sum >= 4 && count < m_local) {
        //@ assert sum >= 4 && count < m_local;
        sum -= 4;
        result += 1;
        count += 1;
        //@ assert sum == n_local + m_local - 4 * count;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n_local + m_local;
    return result;
}
