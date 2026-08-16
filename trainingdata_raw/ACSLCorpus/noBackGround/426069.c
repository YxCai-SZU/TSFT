#include <stdint.h>

typedef struct {
    uint32_t base;
    uint32_t height;
} Triangle;

/*@
    requires ((t).base <= 0xFFFFFFFF && (t).height <= 0xFFFFFFFF);
    ensures ((\result).base * (\result).height / 2) == ((t).base * (t).height / 2);
    assigns \nothing;
*/
Triangle base_height_flip(Triangle t) {
    Triangle new_t;
    
    //@ assert t.base * t.height == t.height * t.base;
    
    new_t.base = t.height;
    new_t.height = t.base;
    
    //@ assert ((new_t).base * (new_t).height / 2) == ((t).base * (t).height / 2);
    
    return new_t;
}
