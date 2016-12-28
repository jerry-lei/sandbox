#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

class Superhero {
public:
  // ACCESSORS
  Superhero(const std::string& n, const std::string& p, const std::string& ti){
    name = n;
    power = p;
    true_identity = ti;
  }
  const string& getName() const { return name; }
  const string& getPower() const { return power; }
  //Superhero& operator /=(const std::string& str_name);
  // INPUT STREAM OPERATOR
  friend Superhero& operator /= (Superhero& a, string guess);
  friend istream& operator>>(istream &istr, Superhero &hero);
private:
  // REPRESENTATION
  string name;
  string true_identity;
  string power;
};
// OUTPUT STREAM OPERATOR
ostream& operator<<(ostream &ostr, const Superhero &hero) {
  if (hero.getPower() == "")
  ostr << hero.getName() << " has no power" << endl;
  else
  ostr << "Superhero " << hero.getName() << " has power " << hero.getPower() << endl;
  return ostr;
}

/*
Superhero& Superhero::operator/=(const string& ti_guess){
  if(true_identity == ti_guess)
    power = "";
  return *this;
}
*/

Superhero& operator /= (Superhero& a, string guess){
  if(a.true_identity == guess)
    a.power = "";
  return a;
}

void foo(const std::map<int,std::string> haha){
  std::map<int,std::string>::const_iterator itr = haha.begin();
}

int main(){
  Superhero elastigirl("Elastigirl","Flexible","Zoe");
  cout << elastigirl;
  elastigirl /= ("Zoe");
  cout << elastigirl;
  std::map<int, std::string> temporary;
  temporary.insert(std::pair<int, std::string>(14,"hello"));
  foo(temporary);
}
