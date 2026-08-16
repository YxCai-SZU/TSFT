#include <stdbool.h>

typedef enum {
    Mammal,
    Arthropod,
    Plant
} LifeTag;

typedef struct {
    LifeTag tag;
    union {
        struct {
            int legs;
            bool has_pocket;
        } mammal;
        struct {
            int legs;
            int wings;
        } arthropod;
        struct {
            int leaves;
        } plant;
    };
} Life;

/*@
    requires \true;
    ensures \result ==> (((l).tag == Mammal) || ((l).tag == Arthropod));
    assigns \nothing;
*/
bool check_cuddly(Life l) {
    bool matches_mammal;
    bool matches_arthropod;
    bool cuddly;
    
    matches_mammal = (l.tag == Mammal);
    matches_arthropod = (l.tag == Arthropod);
    cuddly = matches_mammal || matches_arthropod;
    
    //@ assert cuddly ==> (((l).tag == Mammal) || ((l).tag == Arthropod));
    
    return cuddly;
}

/*@
    assigns \nothing;
*/
void test() {
    Life l;
    
    l.tag = Mammal;
    l.mammal.legs = 4;
    l.mammal.has_pocket = true;
    
    //@ assert (((l).tag == Mammal && (l).mammal.has_pocket) ||       ((l).tag == Arthropod && (l).arthropod.wings == 0));
}
