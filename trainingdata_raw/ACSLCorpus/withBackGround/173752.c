#include <stdbool.h>

/*@ predicate is_concert_ready_piano(integer keys) = keys == 88;
    predicate is_concert_ready_violin(integer strings) = strings == 4;
    predicate is_concert_ready_drums(integer pieces) = pieces == 5;
 */

/*@ logic integer is_concert_ready(integer tag, integer keys, integer strings, integer pieces) =
        (tag == 0) ? (keys == 88 ? 1 : 0) :
        (tag == 1) ? (strings == 4 ? 1 : 0) :
        (pieces == 5 ? 1 : 0);
 */

/*@ lemma piano_ready: \forall integer keys; keys == 88 ==> is_concert_ready(0, keys, 0, 0) == 1;
    lemma violin_ready: \forall integer strings; strings == 4 ==> is_concert_ready(1, 0, strings, 0) == 1;
    lemma drums_ready: \forall integer pieces; pieces == 5 ==> is_concert_ready(2, 0, 0, pieces) == 1;
 */

struct MusicalInstrument {
    int tag;
    union {
        struct { unsigned int keys; } piano;
        struct { unsigned int strings; } violin;
        struct { unsigned int pieces; } drums;
    } data;
};

/*@ requires i.tag == 0 || i.tag == 1 || i.tag == 2;
    requires i.tag == 0 ==> i.data.piano.keys == 88;
    requires i.tag == 1 ==> i.data.violin.strings == 4;
    requires i.tag == 2 ==> i.data.drums.pieces == 5;
    ensures \result == is_concert_ready(i.tag, i.data.piano.keys, i.data.violin.strings, i.data.drums.pieces);
    assigns \nothing;
 */
bool tune_instrument(struct MusicalInstrument i)
{
    bool concert_ready;
    
    //@ assert i.tag == 0 || i.tag == 1 || i.tag == 2;
    
    if (i.tag == 0) {
        //@ assert i.data.piano.keys == 88;
        concert_ready = (i.data.piano.keys == 88);
        //@ assert concert_ready == is_concert_ready(0, i.data.piano.keys, 0, 0);
    } else if (i.tag == 1) {
        //@ assert i.data.violin.strings == 4;
        concert_ready = (i.data.violin.strings == 4);
        //@ assert concert_ready == is_concert_ready(1, 0, i.data.violin.strings, 0);
    } else {
        //@ assert i.data.drums.pieces == 5;
        concert_ready = (i.data.drums.pieces == 5);
        //@ assert concert_ready == is_concert_ready(2, 0, 0, i.data.drums.pieces);
    }
    
    return concert_ready;
}

/*@ ensures is_concert_ready(0, 88, 0, 0) == 1;
    assigns \nothing;
 */
void test_instrument(void)
{
    struct MusicalInstrument grand_piano;
    grand_piano.tag = 0;
    grand_piano.data.piano.keys = 88;
    
    //@ assert grand_piano.data.piano.keys == 88;
    //@ assert is_concert_ready(0, 88, 0, 0) == 1;
}

/*@ assigns \nothing;
 */
int main(void)
{
    test_instrument();
    return 0;
}
