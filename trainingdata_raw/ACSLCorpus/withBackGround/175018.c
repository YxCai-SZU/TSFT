/*@
predicate trichotomy(integer a, integer b) = a == b || a < b || a > b;

lemma lemma_trichotomy: \forall integer a, b; trichotomy(a, b) ==> trichotomy(a, b);

predicate leq(integer a, integer b) = a <= b;

lemma lemma_leq: \forall integer a, b; leq(a, b) ==> leq(a, b);

logic integer mult_2(integer n) = n * 2;
lemma calc_example_5: \forall integer n; n == 10 ==> mult_2(n) == 20;

logic integer mult_3(integer n) = n * 3;
lemma calc_example_4: \forall integer n; n == 10 ==> mult_3(n) == 30;

logic integer mult_4(integer n) = n * 4;
lemma calc_example_3: \forall integer n; n == 10 ==> mult_4(n) == 40;

logic integer mult_5(integer n) = n * 5;
lemma calc_example_2: \forall integer n; n == 10 ==> mult_5(n) == 50;

logic integer mult_6(integer n) = n * 6;
lemma calc_example_1: \forall integer n; n == 10 ==> mult_6(n) == 60;

logic integer mult_7(integer n) = n * 7;
lemma calc_example_6: \forall integer n; n == 10 ==> mult_7(n) == 70;

logic integer mult_8(integer n) = n * 8;
lemma calc_example_7: \forall integer n; n == 10 ==> mult_8(n) == 80;

logic integer mult_9(integer n) = n * 9;
lemma calc_example_8: \forall integer n; n == 10 ==> mult_9(n) == 90;

logic integer mult_10(integer n) = n * 10;
lemma calc_example_9: \forall integer n; n == 10 ==> mult_10(n) == 100;

logic integer mult_11(integer n) = n * 11;
lemma calc_example_10: \forall integer n; n == 10 ==> mult_11(n) == 110;

logic integer mult_12(integer n) = n * 12;
lemma calc_example_11: \forall integer n; n == 10 ==> mult_12(n) == 120;

logic integer mult_13(integer n) = n * 13;
lemma calc_example_12: \forall integer n; n == 10 ==> mult_13(n) == 130;

logic integer mult_14(integer n) = n * 14;
lemma calc_example_13: \forall integer n; n == 10 ==> mult_14(n) == 140;

logic integer mult_15(integer n) = n * 15;
lemma calc_example_14: \forall integer n; n == 10 ==> mult_15(n) == 150;

logic integer mult_16(integer n) = n * 16;
lemma calc_example_15: \forall integer n; n == 10 ==> mult_16(n) == 160;

logic integer mult_17(integer n) = n * 17;
lemma calc_example_16: \forall integer n; n == 10 ==> mult_17(n) == 170;

logic integer mult_18(integer n) = n * 18;
lemma calc_example_17: \forall integer n; n == 10 ==> mult_18(n) == 180;

logic integer mult_19(integer n) = n * 19;
lemma calc_example_18: \forall integer n; n == 10 ==> mult_19(n) == 190;

logic integer mult_20(integer n) = n * 20;
lemma calc_example_19: \forall integer n; n == 10 ==> mult_20(n) == 200;

logic integer mult_21(integer n) = n * 21;
lemma calc_example_20: \forall integer n; n == 10 ==> mult_21(n) == 210;

logic integer mult_22(integer n) = n * 22;
lemma calc_example_21: \forall integer n; n == 10 ==> mult_22(n) == 220;

logic integer mult_23(integer n) = n * 23;
lemma calc_example_22: \forall integer n; n == 10 ==> mult_23(n) == 230;

logic integer mult_24(integer n) = n * 24;
lemma calc_example_23: \forall integer n; n == 10 ==> mult_24(n) == 240;

logic integer mult_25(integer n) = n * 25;
lemma calc_example_24: \forall integer n; n == 10 ==> mult_25(n) == 250;
*/

int main() {
    return 0;
}
