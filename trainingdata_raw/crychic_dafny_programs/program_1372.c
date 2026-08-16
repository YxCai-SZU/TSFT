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
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test2(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  AddDtgt(&dishwasher);
  Load(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test3(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  AddDtgt(&dishwasher);
  Unload(&dishwasher);
  Load(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test4(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void Test5(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  Load(&dishwasher);
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void ExtraTest1(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  Load(&dishwasher);
  Load(&dishwasher);
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
    assigns \nothing;
*/
void ExtraTest2(void)
{
  Dishwasher dishwasher = {0, 0, 0};
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Load(&dishwasher);
  AddDtgt(&dishwasher);
  AddDtgt(&dishwasher);
  Wash(&dishwasher);
  Unload(&dishwasher);
}

/*@
  predicate Valid(integer loaded, integer washed, integer addedDtgt) =
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
    ensures this->loaded == \old(this->loaded);
    ensures this->washed == \old(this->washed);
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
    ensures this->loaded == \old(this->loaded);
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
*/
void Unload(Dishwasher* this)
{
  this->loaded = 0;
  this->washed = 0;
}