#include <stdbool.h>

struct Parallelogram {
    unsigned int base;
    unsigned int height;
};

/*@
    requires \valid(p);
    requires p->base <= 1000 && p->height <= 1000;
    requires p->base * p->height <= 1000000;
    ensures \result == true;
*/
bool check_area(const struct Parallelogram *p) {
    //@ assert p->base * p->height == p->base * p->height;
    return true;
}

/*@
    requires \valid(p);
    requires ((p->base) >= 0 && (p->height) >= 0);
    ensures ((\result.base) * (\result.height)) == ((p->base) * (p->height));
*/
struct Parallelogram flip_dimensions(const struct Parallelogram *p) {
    struct Parallelogram q;
    //@ assert p->height * p->base == p->base * p->height;
    q.base = p->height;
    q.height = p->base;
    return q;
}

int main() {
    return 0;
}
