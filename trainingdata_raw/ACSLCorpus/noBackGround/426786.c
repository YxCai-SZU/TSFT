#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint32_t min;
    uint32_t max;
} ArrayLimits;

/*@
    requires \valid(limits);
    requires ((limits->min) <= (limits->max));
    requires \valid_read(v + (0 .. v_len - 1));
    requires (\forall integer i; 0 <= i < (v_len) ==>
            (limits->min) <= (v)[i] && (v)[i] <= (limits->max));
    ensures \result == true;
    assigns \nothing;
*/
bool complies_with_limits_check(const uint32_t *v, uint32_t v_len,
                                const ArrayLimits *limits) {
    //@ assert ((limits->min) <= (limits->max));
    return true;
}

/*@
    requires \valid(limits);
    requires ((limits->min) <= (limits->max));
    requires \valid_read(v + (0 .. v_len - 1));
    requires (\forall integer i; 0 <= i < (v_len) ==>
            (limits->min) <= (v)[i] && (v)[i] <= (limits->max));
    ensures \result == true;
    assigns \nothing;
*/
bool complies_with_limits_check_array(const uint32_t *v, uint32_t v_len,
                                      const ArrayLimits *limits) {
    //@ assert ((limits->min) <= (limits->max));
    return true;
}

/*@
    assigns \nothing;
*/
int main() {
    uint32_t v[3];
    uint32_t v_len;
    ArrayLimits limits;
    bool result;
    
    v[0] = 2;
    v[1] = 3;
    v[2] = 4;
    v_len = 3;
    limits.min = 1;
    limits.max = 5;
    
    //@ assert ((limits.min) <= (limits.max));
    //@ assert (\forall integer i; 0 <= i < (v_len) ==>             (limits.min) <= (&v[0])[i] && (&v[0])[i] <= (limits.max));
    
    result = complies_with_limits_check(&v[0], v_len, &limits);
    //@ assert result == true;
    
    result = complies_with_limits_check_array(&v[0], v_len, &limits);
    //@ assert result == true;
    
    return 0;
}
