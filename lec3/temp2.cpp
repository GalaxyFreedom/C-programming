#include <iostream>
#include <string>
using namespace std;

class Club {
    private:
        string name;
        string building;
    public:
        void setName(string name) { this->name = name; }
        void setBuilding(string building) { this->building = building; }

        string getName() { return name; }
        string getBuilding() { return building; }

        void print() {
            cout << "Club name: " << name <<endl;
            cout << "Building name: " << name <<endl;
        }
};
class Campus {
    private:
        string name;
        string address;
        double distance;
        Club club;
    public:
        void setName(string name) { this->name = name; }
        void setAddress(string address) { this->address = address; }
        void setDistance(double distance) { this->distance = distance; }
        void setClub(Club club) { this->club = club; }

        void print() {
            cout << "Campus name: " << name <<endl;
            cout << "Campus address: " << address <<endl;
            cout << "Distance: " << distance <<endl;
            cout << "Club name: " << club.getName() << endl;
            cout << "--------------------------------------" << endl;
        }
};

class University {
    private:
        int index=0;
        Campus campuses[1024];
    public:
        void addCampus(Campus campus) {
            if (index < 1024){
                campuses[index] = campus;
                index++;
            }
        }
        void print() {
            for(int i=0; i<index; i++){
                campuses[i].print();
            }
        }
};

int main() {
    Club club1;
    club1.setName("Jogging");

    Campus campus1;
    campus1.setName("Campus 1");
    campus1.setDistance(20);
    campus1.setClub(club1);

    Club club2;
    club2.setName("Running");

    Campus campus2;
    campus2.setName("Campus 2");
    campus2.setDistance(30);
    campus2.setClub(club2);

    University uni;
    uni.addCampus(campus1);
    uni.addCampus(campus2);
    uni.print();
    return 0;
}