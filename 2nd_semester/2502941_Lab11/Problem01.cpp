#include <iostream>
using namespace std;

// Base Class
class Project {
protected:
    string projectName, domain, teamLead;
    int totalDuration, developmentTime, testingTime;

public:
    Project(string name, string dom, string lead,
            int total, int dev, int test)
        : projectName(name), domain(dom), teamLead(lead),
          totalDuration(total), developmentTime(dev), testingTime(test) {}

    // Pure virtual functions
    virtual double CalculateCost() = 0;
    virtual void PrintImportantInformation() = 0;

    // Normal function
    void PrintProjectInfo() {
        cout << "Project Name: " << projectName << endl;
        cout << "Domain: " << domain << endl;
        cout << "Team Lead: " << teamLead << endl;
        cout << "Total Duration: " << totalDuration << endl;
        cout << "Development Time: " << developmentTime << endl;
        cout << "Testing Time: " << testingTime << endl;
    }

    // Virtual Destructor
    virtual ~Project() {
        cout << "Project destroyed" << endl;
    }
};

// Derived Class: Software Project
class SoftwareProject : public Project {
public:
    SoftwareProject(string name, string dom, string lead,
                    int total, int dev, int test)
        : Project(name, dom, lead, total, dev, test) {}

    double CalculateCost() override {
        return developmentTime * 600;
    }

    void PrintImportantInformation() override {
        cout << "\n--- Software Project Important Info ---" << endl;
        cout << "Project Name: " << projectName << endl;
        cout << "Team Lead: " << teamLead << endl;
        cout << "Development Time: " << developmentTime << endl;
        cout << "Cost: $" << CalculateCost() << endl;
    }
};

// Derived Class: Research Project
class ResearchProject : public Project {
public:
    ResearchProject(string name, string dom, string lead,
                    int total, int dev, int test)
        : Project(name, dom, lead, total, dev, test) {}

    double CalculateCost() override {
        return testingTime * 400;
    }

    void PrintImportantInformation() override {
        cout << "\n--- Research Project Important Info ---" << endl;
        cout << "Project Name: " << projectName << endl;
        cout << "Domain: " << domain << endl;
        cout << "Team Lead: " << teamLead << endl;
        cout << "Development Time: " << developmentTime << endl;
    }
};

// Main Function
int main() {
    Project* p;

    SoftwareProject sp("AI System", "Software", "Ali", 12, 10, 2);
    ResearchProject rp("Cancer Study", "Medical", "Sara", 18, 6, 12);

    // Polymorphism
    p = &sp;
    p->PrintProjectInfo();
    cout << "Cost: $" << p->CalculateCost() << endl;
    p->PrintImportantInformation();

    cout << "\n===========================\n";

    p = &rp;
    p->PrintProjectInfo();
    cout << "Cost: $" << p->CalculateCost() << endl;
    p->PrintImportantInformation();

    return 0;
}