// Generated C + ACSL

typedef struct {
  int loaded;
  int washed;
  int addedDtgt;
} Dishwasher;

void Load(Dishwasher* this);
void AddDtgt(Dishwasher* this);
void Wash(Dishwasher* this);
void Unload(Dishwasher* this);

/*@
    assigns \nothing;
*/
void Test1(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test2(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0 && dishwasher.addedDtgt == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test3(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
  //@ assert dishwasher.loaded == 0 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0 && dishwasher.addedDtgt == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test4(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.washed == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test5(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void ExtraTest1(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void ExtraTest2(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Load(&dishwasher);
  //@ assert dishwasher.loaded == 1 && dishwasher.washed == 0;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  AddDtgt(&dishwasher);
  //@ assert dishwasher.addedDtgt == 1 && dishwasher.loaded == 1;
  Wash(&dishwasher);
  //@ assert dishwasher.washed == 1 && dishwasher.loaded == 1;
  Unload(&dishwasher);
}

/*@
  predicate Valid(int loaded, int washed, int addedDtgt) =
    ((!loaded && washed) || (!addedDtgt && washed)) ==> \false;
*/

/*@
    requires \valid(this);
    assigns this->loaded, this->washed;
    ensures this->loaded == 1;
    ensures this->washed == 0;
*/
void Load(Dishwasher* this)
{
  this->loaded = 1;
  this->washed = 0;
}

/*@
    requires \valid(this);
    assigns this->addedDtgt;
    ensures this->addedDtgt == 1;
*/
void AddDtgt(Dishwasher* this)
{
  this->addedDtgt = 1;
}

/*@
    requires \valid(this);
    requires this->addedDtgt == 1;
    requires this->loaded == 1;
    assigns this->addedDtgt, this->washed;
    ensures this->washed == 1;
    ensures this->addedDtgt == 0;
*/
void Wash(Dishwasher* this)
{
  this->addedDtgt = 0;
  this->washed = 1;
}

/*@
    requires \valid(this);
    requires this->loaded == 1;
    requires this->washed == 1;
    assigns this->loaded, this->washed;
    ensures this->loaded == 0;
    ensures this->washed == 0;
*/
void Unload(Dishwasher* this)
{
  this->loaded = 0;
  this->washed = 0;
}