#include <stdint.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (m) && (m) <= (n));
  assigns \nothing;
  ensures \result == (int)(n - m);
*/
int func(uint32_t n, uint32_t m) {
    int n_int;
    int m_int;
    int result;
    
    n_int = (int)n;
    m_int = (int)m;
    
    //@ assert n_int == (int)n;
    //@ assert m_int == (int)m;
    //@ assert (1 <= (n) && (n) <= 100 &&       1 <= (m) && (m) <= (n));
    //@ assert n_int - m_int == (int)(n - m);
    
    result = n_int - m_int;
    return result;
}

/*@
  assigns *n, *m;
  ensures *n == 0 && *m == 0;
  ensures \result == 0;
*/
int read_vec(int *n, int *m) {
    *n = 0;
    *m = 0;
    return 0;
}

#ifdef TEST
#include <stdio.h>

void test_input(void) {
    int n;
    int m;
    int result;
    
    read_vec(&n, &m);
    result = func((uint32_t)n, (uint32_t)m);
    printf("%d\n", result);
}
#endif
