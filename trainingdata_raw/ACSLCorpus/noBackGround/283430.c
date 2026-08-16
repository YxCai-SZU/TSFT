#include <stdbool.h>

typedef enum {
    NECKLACE,
    BRACELET,
    EARRING
} AccessoryTag;

typedef struct {
    AccessoryTag tag;
    union {
        unsigned int weight;
        unsigned int circumference;
        unsigned int length;
    } data;
} Accessory;

/*@
    requires \true;
    ensures \true;
*/
void test_accessory() {
    Accessory gold_bracelet;
    
    gold_bracelet.tag = BRACELET;
    gold_bracelet.data.circumference = 20;
    
    //@ assert ((1) == 0 ? (0) :         (1) == 1 ? (20) :         (0)) == 20;
}

/*@
    requires \true;
    ensures \true;
*/
int main() {
    test_accessory();
    return 0;
}
