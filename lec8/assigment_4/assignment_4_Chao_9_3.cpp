// (c) Dorothy R. Kirk. All Rights Reserved.
// Purpose: To illustrate virtual base classes.
// Virtual base classes resolve duplications which can exist with
// multiple inheritance when two or more base classes for a class share
// a common ancestor class.
// In this example, only one copy of the LifeForm sub-object will exist for each
// instance of a Centaur.

#include <iostream>

using std::cout;    // preferred to: using namespace std;
using std::endl;
using std::string;
using std::to_string;

class LifeForm
{
private:
   int lifeExpectancy = 0;   // in-class initialization
public:
   LifeForm() = default;
   LifeForm(int life) : lifeExpectancy(life) { }
   LifeForm(const LifeForm &form) = default;
   // If we wanted to write the copy constructor, this is what it would look like:
   // LifeForm(const LifeForm &form) : lifeExpectancy(form.lifeExpectancy) { }   OR
   // LifeForm(const LifeForm &form) { lifeExpectancy = form.lifeExpectancy; }
   virtual ~LifeForm() = default;
   [[nodiscard]] int GetLifeExpectancy() const { return lifeExpectancy; }

   // Virtual functions will (almost) never be inlined since their method must be determined
   // at run time using the v-table (except a few rare situations).
   virtual void Print() const = 0;   // pure virtual functions specify the interface but
   virtual string IsA() const = 0;   // most often do not specify a default behavior
   virtual string Speak() const = 0;
};

// Here, LifeForm is a virtual base class of Horse.  This means that if
// Horse is ever combined with a sibling (or cousin) of another base class which inherits
// from LifeForm, those siblings will SHARE their copy of LifeForm,
// reducing storage, extra constructor calls, and eliminating ambiguity.
// This will not at all affect instances of Horse (only instances of
// derived classes which would otherwise have duplicate LifeForm sub-objects).

class Horse: public virtual LifeForm
{
private:
   string name;
   static constexpr int HORSE_LIFE = 35; // life expectancy of a Horse
public:
   Horse(): LifeForm(HORSE_LIFE) { }
   Horse(const string &n);
   // Remember, it isn't necessary for us to prototype default copy constructor
   // Horse(const Horse &) = default;
   // Because base class destructor is virtual, ~Horse() is automatically virtual (overridden) whether or not explicitly prototyped
   // ~Horse() override = default;
   const string &GetName() const { return name; }
   void Print() const override;
   string IsA() const override;
   string Speak() const override;
};

// Notice that the base class initialization list is ignored
// if LifeForm actually is a shared virtual base class.
// Most often the default construcor will instead be called for LifeForm.
// The remainder of the member initialization list will be used as expected.
Horse::Horse(const string &n) : LifeForm(HORSE_LIFE), name(n)
{
}

// We are using the default (system supplied) copy constructor, but if we wanted to write it, it would look like:
// Remember to prototype it if you define it yourself.
/*
Horse::Horse(const Horse &h) : LifeForm (h), name(h.name)
{
}
*/

void Horse::Print() const
{
   cout << name << endl;
}

string Horse::IsA() const
{
   return "Horse";
}

string Horse::Speak() const
{
   return "Neigh!";
}

// LifeForm is a virtual base class of Person.
class Person: public virtual LifeForm
{
private:
   // data members
   string firstName;
   string lastName;
   char middleInitial = '\0';   // in-class initialization
   string title;  // Mr., Ms., Mrs., Miss, Dr., etc.
   static constexpr int PERSON_LIFE = 80;  // Person life expextancy
protected:
   void ModifyTitle(const string &);  // Make this operation available to derived classes
public:
   Person();   // programmer supplied default constructor
   Person(const string &, const string &, char, const string &);  // alternate constructor
   // Remember, default copy constructor prototype is not necessary
   Person(const Person &) = default;  // copy constructor
   // Because base class destructor is virtual, ~Person() is automatically virtual (overridden) whether or not explicitly prorotyped
   // ~Person() override = default;  // destructor

   // inline function definitions
   const string &GetFirstName() const { return firstName; }  // firstName returned as ref to const string
   const string &GetLastName() const { return lastName; }    // so is lastName (via implicit cast)
   const string &GetTitle() const { return title; }
   char GetMiddleInitial() const { return middleInitial; }

   // Virtual functions will (most often) not be inlined since their method must be determined at run time using the v-table.
   void Print() const override;
   string IsA() const override;
   string Speak() const override;
};

// Notice that the base class init list specification of LifeForm is ignored if LifeForm ACTUALLY is a shared virtual base class.
// Remember, string members are automatically initialized to empty with the default string constructor
Person::Person() : LifeForm(PERSON_LIFE)
{
}

Person::Person(const string &fn, const string &ln, char mi, const string &t) : LifeForm(PERSON_LIFE),
                             firstName(fn), lastName(ln), middleInitial(mi), title(t)

{
}

// We're using default copy constructor. But if we wanted to write it, this is what it would look like:
// Remember to prototype it if you define it yourself.
/*
Person::Person(const Person &p) : LifeForm(p), firstName(p.firstName), lastName(p.lastName),
                                               middleInitial(p.middleInitial), title(p.title)
{
}
*/

// We're using the default destructor, but if we wrote it, this is what it would look like:
/*
Person::~Person()
{
}
*/

void Person::ModifyTitle(const string &newTitle)
{
    title = newTitle;
}

void Person::Print() const
{
    cout << title << " " << firstName << " ";
    cout << middleInitial << ". " << lastName << endl;
}

string Person::IsA() const
{
    return "Person";
}

string Person::Speak() const
{
    return "Hello!";
}

class Centaur: public Person, public Horse
{
private:
   // no additional data members required , but the below static constexpr eliminates a magic number of 1000
   static constexpr int CENTAUR_LIFE = 1000;  // life expectancy of a Centaur
public:
   Centaur(): LifeForm(CENTAUR_LIFE) { }
   Centaur(const string &, const string &, char = ' ', const string & = "Mythological Creature");  // note default args in alt ctor
   // Note: we do not want default copy constructor here, due to virtual base class use in member init list
   Centaur(const Centaur &c): Person(c), Horse(c), LifeForm(CENTAUR_LIFE) { } // notice initialization of shared base class object
   // Because base class' destructors are virtual, ~Centaur() is automatically virtual (overridden) whether or not explicitly prorotyped
   // ~Centaur() override = default;
   void Print() const override;
   string IsA() const override;
   string Speak() const override;
};

// Constructors for Centaur need to specify how the shared
// base class LifeForm will be initialized. This is only allowed because LifeForm is a
// virtual base class of Person and Horse
Centaur::Centaur(const string &fn, const string &ln, char mi, const string &title):
                 Person(fn, ln, mi, title), Horse(fn),
                 LifeForm(CENTAUR_LIFE)
{
   // All initialization has been taken care of in init. list
}

void Centaur::Print() const
{
   cout << "My name is " << GetFirstName();
   cout << ".  I am a " << GetTitle() << endl;
}

string Centaur::IsA() const
{
   return "Centaur";
}


string Centaur::Speak() const
{
   return "Neigh! and Hello! I'm a master of two languages.";
}

int main()
{
   Centaur beast("Wild", "Man");
   cout << beast.Speak() << endl;
   cout << "I am a " << beast.IsA() << ". ";
   beast.Print();
   cout << "I will live: ";
   cout << beast.GetLifeExpectancy();  // no longer ambiguous!
   cout << " years" << endl;
   return 0;
}
