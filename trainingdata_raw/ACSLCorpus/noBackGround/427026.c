#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(m_len);
    ensures *m_len == \old(*m_len);
    assigns \nothing;
*/
void map_len(int *m_len) {
    //@ assert *m_len == *m_len;
}
