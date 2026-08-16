// Generated C + ACSL

/*@ logic integer add_logic(integer x, integer y); */

/*@
  requires y >= 0;
  decreases y;
  ensures \result == x + y;
*/
int add(int x, int y)
{
  return ((y == 0)) ? (x) : ((add(x, (y - 1)) + 1));
}

// ```acsl
// /*@
//   axiomatic zero_add_lemma_properties {
//     lemma zero_add_lemma_statement:
//       \forall integer x; x >= 0 ==> add(0, x) == x;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic add_zero_lemma_properties {
//     lemma add_zero_lemma_statement:
//       \forall integer x; x >= 0 ==> add(x, 0) == x;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic add_plus_one_properties {
//     lemma add_plus_one_statement:
//       \forall integer x, y; x >= 0 && y >= 0 ==>
//         add(x, y) + 1 == add(x, y + 1);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic one_plus_add_properties {
//     lemma one_plus_add_statement:
//       \forall integer x, y; x >= 0 && y >= 0 ==>
//         add(x, y) + 1 == add(x + 1, y);
//   }
// */
// ```

// ```c
// /*@
//   axiomatic add_comm_lemma_properties {
//     lemma add_comm_lemma_statement:
//       \forall integer x, y; x >= 0 && y >= 0 ==>
//         add(x, y) == add(y, x);
//   }
// */
// ```