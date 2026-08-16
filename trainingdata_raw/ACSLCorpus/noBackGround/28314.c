#include <stdint.h>

struct Vector2 {
    uint32_t x;
    uint32_t y;
};

/*@
    requires \valid(v1) && \valid(v2);
    requires ((*v1).x <= 10 && (*v1).y <= 10) && ((*v2).x <= 10 && (*v2).y <= 10);
    assigns \nothing;
    ensures \result == ((v1->x) * (v2->x) + (v1->y) * (v2->y));
    ensures \result <= 200;
*/
uint32_t dot_product(const struct Vector2* v1, const struct Vector2* v2) {
    //@ assert v1->x <= 10 && v1->y <= 10 && v2->x <= 10 && v2->y <= 10;
    
    //@ assert v1->x * v2->x <= 100;
    
    //@ assert v1->y * v2->y <= 100;
    
    uint32_t result;
    result = v1->x * v2->x + v1->y * v2->y;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
