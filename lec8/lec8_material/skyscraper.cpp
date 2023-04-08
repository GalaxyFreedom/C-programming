#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
const int HEIGHT = 0;
const int FLOORS = 1;


using namespace std;

class Skyscraper {
    private:
        string m_name;
        double m_height;
        int m_nrFloors;
    public:
        Skyscraper(const string& name, double height, int nrFloors);
        double getHeight() const { return m_height; }
        string getName() const { return m_name; }
        void print() const;
        int getNrFloors() const { return m_nrFloors; }
        bool operator<(const Skyscraper& skyscraper) const;
};
Skyscraper::Skyscraper(const string& name, double height, int nrFloors) :
    m_name(name), m_height(height), m_nrFloors(nrFloors)
    {
    if (m_height < 0 || m_nrFloors < 0) {
        throw invalid_argument("Skyscraper height must be positive");
    }
}
void Skyscraper::print() const {
    cout << this->m_name <<" "<< this->m_height << " "
         << this->m_nrFloors << endl;
}
bool Skyscraper::operator<(const Skyscraper& skyscraper) const {
    return this->m_height < skyscraper.m_height;
}
struct EntityComp {
  int property;
  EntityComp(int property) {this->property = property;}
  bool operator()(const Skyscraper& s1, const Skyscraper& s2) const {
      if(property == FLOORS)
          return s1.getNrFloors() < s2.getNrFloors();
      else
          return s1.getHeight() < s2.getHeight();
  }
};
int main() {
    vector<Skyscraper> skyscrapers;
    skyscrapers.push_back(Skyscraper("Empire State", 381, 102));
    skyscrapers.push_back(Skyscraper("Petronas", 452, 88));
    skyscrapers.push_back(Skyscraper("Burj Khalifa", 828, 163));
    skyscrapers.push_back(Skyscraper("Taipei", 509, 101));
    sort(skyscrapers.begin(), skyscrapers.end(), EntityComp(FLOORS));
    for (auto i = 0; i < skyscrapers.size(); i++) {
        skyscrapers.at(i).print();
    }
    return 0;
}

