#include <stdbool.h>
#include <stddef.h>

struct NestedStruct {
    int *a;
    size_t a_len;
    int *b;
    size_t b_len;
};

enum NestedEnum_Tag {
    SeqVariant,
    SetVariant,
    CustomVariant
};

struct NestedEnum_seq_variant {
    int *sequence;
    size_t seq_len;
};

struct NestedEnum_set_variant {
    int *set;
    size_t set_len;
};

struct NestedEnum_custom_variant {
    int *sequence;
    size_t seq_len;
    int *set;
    size_t set_len;
};

union NestedEnum_union {
    struct NestedEnum_seq_variant seq_variant;
    struct NestedEnum_set_variant set_variant;
    struct NestedEnum_custom_variant custom_variant;
};

struct NestedEnum {
    enum NestedEnum_Tag tag;
    union NestedEnum_union variant;
};

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
