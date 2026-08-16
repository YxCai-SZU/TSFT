#include <stdbool.h>

struct Page {
    char *content;
    bool immutable;
};

/*@ predicate valid(struct Page p) = 
        p.immutable == true; */

/*@ lemma page_is_valid: 
        \forall struct Page p1, struct Page p2; 
        valid(p1) && valid(p2) ==> true; */

int main() {
    //@ assert \true;
    return 0;
}
