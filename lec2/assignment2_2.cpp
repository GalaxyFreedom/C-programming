#include <iostream>
#include <string>

using namespace std;
class Department{
    private:
        string departmentName;
        int departmentId;
    public:
        void setDepartmentName(string departmentNameString) { departmentName = departmentNameString; }
        void setDepartmentId(int departmentIdString) { departmentId = departmentIdString; }

        string getDepartmentName() { return departmentName; }
        int getDepartmentId() { return departmentId; }
};
class Employee{
    private:
        int employeeId;
        string employeeName, gender;
        Department department;

    public:
        void setEmployeeId(int employeeIdSet) { employeeIdSet = employeeId; }
        void setEmployeeName(string employeeNameString) { employeeName = employeeNameString; }
        void setGender(string genderString) { gender = genderString; }

        int getEmployeeId() { return employeeId; }
        string getEmployeeName() { return employeeName; }
        string getGender() { return gender; }
};

int main(){

    return 0;
}
