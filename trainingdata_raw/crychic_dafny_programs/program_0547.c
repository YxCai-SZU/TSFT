// Generated C + ACSL

// Define state enum
typedef enum { I, T, C, E } State;

// Define structure for top
typedef struct {
  State *n;
  int x;
} Top;

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i];
*/
void n_Tryinv__1_0(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i];
*/
void n_Tryinv__1_1(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i];
*/
void n_Tryinv__1_2(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = T;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i], top->x;
*/
void n_Critinv__1_0(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires 0 <= p__Inv3 < N0;
    requires 0 <= p__Inv4 < N0;
    requires p__Inv3 != p__Inv4;
    requires i == p__Inv3;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    requires \forall integer ii, jj;
        0 <= ii < N0 && 0 <= jj < N0 && ii != jj ==>
        top->n[ii] != top->n[jj];
    requires !(top->n[p__Inv4] == C && top->x == 1);
    requires top->n[i] == T && top->x == 1;
    assigns top->n[i], top->x;
*/
void n_Critinv__1_1(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i], top->x;
*/
void n_Critinv__1_2(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = C;
  top->x = 0;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i];
*/
void n_Exitinv__1_0(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i];
*/
void n_Exitinv__1_1(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    requires \forall integer ii, jj; 0 <= ii < N0 && 0 <= jj < N0 && ii != jj ==> top->n[ii] != top->n[jj];
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires !(top->n[p__Inv4] == C && top->n[p__Inv3] == C);
    requires top->n[i] == C;
    assigns top->n[i];
*/
void n_Exitinv__1_2(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = E;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv4;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i], top->x;
*/
void n_Idleinv__1_0(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires i == p__Inv3;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i], top->x;
*/
void n_Idleinv__1_1(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}

/*@
    requires 0 <= i < N0;
    requires N0 > 0;
    requires p__Inv3 != p__Inv4;
    requires p__Inv4 < N0;
    requires p__Inv3 < N0;
    requires i != p__Inv3;
    requires i != p__Inv4;
    requires \valid(top);
    requires \valid(top->n + (0 .. N0-1));
    assigns top->n[i], top->x;
*/
void n_Idleinv__1_2(Top *top, int i, int N0, int p__Inv3, int p__Inv4)
{
  top->n[i] = I;
  top->x = 1;
}