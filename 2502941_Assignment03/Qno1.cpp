#include <iostream>
#include <string>
using namespace std;
class RescueUnit{
    protected:
    int unitID;
    string unit_name;
    string Deployment_Location;
    public:
    RescueUnit(){
        unitID = 0;
        unit_name = "-";
        Deployment_Location = "-";
        cout << "RescueUnit Default constructor called "<<endl;
    }
    RescueUnit(int id , const string& name , const string& DL){
        unitID = id;
        unit_name = name;
        Deployment_Location = DL;
        cout << "RescueUnit parameterized constructor called "<<endl;
    };
    void inputData(){
        cout << "Enter the unit ID: ";
        cin >> unitID;

        cin.ignore();
        cout << "Enter the unit name: ";
        getline(cin , unit_name);
        cout << "Enter the Deployment Location: ";
        getline(cin , Deployment_Location);
    }
    int getID(){
        return unitID;
    }
    string getname() const {
        return unit_name;
    }
    string getDL() const{
        return Deployment_Location;
    }
    virtual void displayData(){
    cout << "Unit ID: "<<unitID<<endl;
    cout << "Unit Name: "<<unit_name<<endl;
    cout << "Location deployed: "<<Deployment_Location<<endl;
    }
    virtual ~RescueUnit(){
    cout << "RescueUnit destructor called "<<endl;

    }
};
class GroundRobot:public RescueUnit{
    protected:
    string terrain_type;
    int Load_carrying_capacity;
    public:
    GroundRobot(){
        terrain_type = "-";
        Load_carrying_capacity = 0;
        cout << "GroundRobot Default constructor called "<<endl;

    }
    GroundRobot(int id , const string&name , const string&dl , const string&tp , int Capacity):RescueUnit(id , name , dl){
        terrain_type=tp;
        Load_carrying_capacity = Capacity;
        cout << "GroundRobot parametrized constructor called "<<endl;

    }
    void inputData(){
        RescueUnit::inputData();
        cout << "Enter the Terrain type: ";
        getline(cin , terrain_type);
        cout << "Enter the load carrying capacity: ";
        cin >> Load_carrying_capacity;
    }
    string get_terraintype(){
        return terrain_type;
    }
    int get_loadcarryingcapacity(){
        return Load_carrying_capacity;
    }
    void displayData () override{
    RescueUnit::displayData();
    cout << "Terrain Type robot: "<<terrain_type<<endl;
    cout << "Load carrying capacity: "<<Load_carrying_capacity<<endl;
    }
    ~GroundRobot()override{
        cout << "GroundRobot Destructor called "<<endl;

    }
};
class AerialDrone:public RescueUnit{
    protected:
    int Maximum_Flight_Altitude;
    int Flight_Duration;
    public:
    AerialDrone(){
        Maximum_Flight_Altitude = 0;
        Flight_Duration = 0;
        cout << "AerialDrone Default constructor called "<<endl;

    }
    AerialDrone(int id , const string&name , const string&dl , int MFA , int FD):RescueUnit(id , name ,dl){
        Maximum_Flight_Altitude = MFA;
        Flight_Duration=FD;
        cout << "Aerial Parametrized constructor called "<<endl;

    }
    void inputData(){
        RescueUnit::inputData();
        cout << "Enter the Maximum flight altitude: ";
        cin>>Maximum_Flight_Altitude;
        cout << "Enter the flight duration: ";
        cin>>Flight_Duration;
    }
    int get_maximulflightaltitude()const{
        return Maximum_Flight_Altitude;
    }
    int get_Flightduration()const{
        return Flight_Duration;
    }
    void displayData() override{
        RescueUnit::displayData();
        cout << "Maximum flight altitude: "<<Maximum_Flight_Altitude<<endl;
        cout << "Flight duration: "<<Flight_Duration<<endl;
    }
    ~AerialDrone()override{
        cout << "AerialDrone destructor called"<<endl;
    }
};
class MedicalSupport{
    protected:
    int number_of_kits;
    int emergency_Treatment_level;
    public:
    MedicalSupport(){
        number_of_kits = 0;
        emergency_Treatment_level = 0;
        cout << "MedicalSupport Default constructor called "<<endl;

    }
    MedicalSupport(int Numberofkits , int emergencylvl){
        number_of_kits = Numberofkits;
        emergency_Treatment_level= emergencylvl;
        cout << "MedicalSupport parametrized constructor called "<<endl;

    }
    void inputData(){
        cout << "Enter the number of kits available: ";
        cin>>number_of_kits;
        cout << "Enter the emergency treatment level: ";
        cin>>emergency_Treatment_level; 
    }
    void displayData(){
        cout << "Number of kits available: "<<number_of_kits<<endl;
        cout << "Emergency level: "<<emergency_Treatment_level<<endl;
    }
    ~MedicalSupport(){
        cout << "Medical support class destroyed"<<endl;
    }
};
class RescueDrone:public AerialDrone , public MedicalSupport{
    public:
    RescueDrone(){
        cout << "RescueDrone Default constructor called "<<endl;

    }
    RescueDrone(int id , const string& name , const string& DL ,int Numberofkits , int emergencylvl , int MFA , int FD ):AerialDrone(id , name , DL , MFA , FD),MedicalSupport(Numberofkits,emergencylvl){
        cout << "RescueDrone parametrized constructor called "<<endl;

    }
    void inputData(){
        AerialDrone::inputData();
        MedicalSupport::inputData();
    }

    void displayData () override{
        AerialDrone::displayData();
        MedicalSupport::displayData();
    }
    ~RescueDrone(){
        cout << "RescueDrone destructor called "<<endl;  
    }
};
int main(){
    GroundRobot G1;
    cout << "Enter the Ground robot data: "<<endl;
    G1.inputData();
    RescueDrone RD1;
    cout << "Enter the rescue drone data: "<<endl;
    RD1.inputData();
    G1.displayData();
    RD1.displayData();
}