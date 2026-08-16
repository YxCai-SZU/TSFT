#include <stdbool.h>

enum AccessoryTag { Necklace, Bracelet, Earring };

struct Accessory {
    enum AccessoryTag tag;
    union {
        unsigned int weight;
        unsigned int circumference;
        unsigned int length;
    } data;
};

/*@
    requires \valid(e);
    requires e->tag == Necklace || e->tag == Bracelet || e->tag == Earring;
    ensures \result == true <==> (((e->tag) == 0 && (e->data.weight) > 10) ||
        ((e->tag) == 1 && (e->data.circumference) > 18) ||
        ((e->tag) == 2 && (e->data.length) > 5));
*/
bool evaluate_accessory(struct Accessory *e)
{
    bool result;
    //@ assert e->tag == Necklace || e->tag == Bracelet || e->tag == Earring;
    
    switch (e->tag) {
        case Necklace:
            //@ assert e->tag == Necklace;
            result = e->data.weight > 10;
            break;
        case Bracelet:
            //@ assert e->tag == Bracelet;
            result = e->data.circumference > 18;
            break;
        case Earring:
            //@ assert e->tag == Earring;
            result = e->data.length > 5;
            break;
        default:
            result = false;
            break;
    }
    
    //@ assert result == true <==> (((e->tag) == 0 && (e->data.weight) > 10) ||         ((e->tag) == 1 && (e->data.circumference) > 18) ||         ((e->tag) == 2 && (e->data.length) > 5));
    return result;
}

void test_accessory(void)
{
    struct Accessory gold_bracelet;
    gold_bracelet.tag = Bracelet;
    gold_bracelet.data.circumference = 20;
    
    //@ assert ((gold_bracelet.tag) == 0 ? (gold_bracelet.data.weight) :         (gold_bracelet.tag) == 1 ? (gold_bracelet.data.circumference) :         (gold_bracelet.data.length)) == 20;
}
