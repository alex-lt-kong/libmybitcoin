#include <iostream>
#include <stdexcept>
#include <math.h>
#include "../ecc.h"
#include "../utils.h"

using namespace std;

void testDivision() {
  FieldElement *a = new FieldElement(7, 19);
  FieldElement b = FieldElement(5, 19);
  cout << "Test division:\n"
       << (FieldElement(2, 19)/FieldElement(7, 19)).to_string() << "\n"
       << ((*a)/b).to_string() << endl;
  delete a;
}

void testPower() {
  FieldElement *a = new FieldElement(3, 13);
  FieldElement b = FieldElement(1, 13);
  cout << "Test power:\n"
      << ((*a).power(3) == b) << "\n"
      << (FieldElement(95, 97) * FieldElement(45, 97) * FieldElement(31, 97)).to_string()
      << endl;
  delete a;
}

void testAddition() {
  FieldElement *a = new FieldElement(7,  13);
  FieldElement b = FieldElement(12, 13);
  FieldElement c = FieldElement(6,  13);
  // We can define an object in two ways.
  // The 1st way, heap memory is used, we need to take care of it ourselves
  // The 2nd way, stack memory is used, the object will be destoryed automatically. 
  cout << "Test addition:\n" << (*a + b == c) << endl;
  cout << (c * (*a)).to_string() << endl;

  delete a;
}

void exercise8() {
  cout << "exercise8():" << endl;
  cout << (FieldElement(3, 31)/FieldElement(24, 31)).to_string() << endl;
  try {
    cout << (FieldElement(17, 31).power(-3)).to_string() << endl;
    cout << (FieldElement(4, 31).power(-4)*FieldElement(11, 31)).to_string() << endl;
  } catch (const invalid_argument& ia) {
    cerr << "Error: " << ia.what() << '\n';
  } catch (runtime_error& re) {
    cerr << "runtime_error: " << re.what() << '\n';
  }
}

void test_fermat_primality_test() {
  for (int i = 1; i < 1024; i++) {
    if (fermat_primality_test(i, 1024) == true) {
      cout << i << ", ";
    }
  }  
  cout << endl;
}

int main() {
  testAddition();
  cout << endl;
  testPower();
  cout << endl;
  testDivision();
  cout << endl;
  exercise8();
  cout << endl;
  test_fermat_primality_test();
  return 0;
}
