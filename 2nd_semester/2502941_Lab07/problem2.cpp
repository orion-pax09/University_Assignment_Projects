#include <iostream>
#include <string>
using namespace std;
class Patient {
    private:
    string* name;
    int patientID;
    float billAmount;
    static int patientCount;
    public:
    Patient(){
        name = new string;
        *name = "Unknown";
        patientID = 0;
        billAmount = 0.00;
        patientCount++;
    }
    Patient(int id , float bill , string n="unknown"): patientID(id) , billAmount(bill){
        name = new string;
        *name = n;
        patientCount++;
    }
    void setdata(int id , string n , float bill){
        *name = n ; 
        this -> patientID = id;
        this ->billAmount = bill;
    }
    void display(){
        cout << "Patient name: "<<*name<<endl;
        cout << "Patient id: "<<patientID<<endl;
        cout << *name<< "'s bill amount: "<<billAmount<<endl;
    }
    void isCritical(){
        if (billAmount > 50000){
            cout << "Patient's status: Critical"<<endl;
        }
        else{
            cout << "Patient's status: Normal"<<endl;
        }
    }
    float getbill(){
        return billAmount;
    }
    static void totalpatient(){
        cout << "Total patients: "<<totalpatient<<endl;
    }
    ~Patient(){
        delete name;
    }
};
int Patient::patientCount=0;
int main(){
    Patient p(3 , 50000,"Muhammad hamza khamn");
    p.display();
    p.isCritical();
    p.totalpatient();
    string name;
    int patientID;
    float billamount;
    int size;
    cout << "How many patient detail do u want to enter: "<<endl;
    cin >> size;
    cin.ignore();
    Patient* patient = new Patient [size];
    for (int i = 0 ; i < size ; i++){
        cout << "Enter the patient name: "<<endl;
        getline(cin,name);
        cout << "Enter the Patien ID: "<<endl; 
        cin >> patientID;
        cout << "Patient bill amount: "<<endl;
        cin>>billamount;
        cin.ignore();
        patient[i].setdata(patientID , name , billamount);
    }
    float max =patient[0].getbill() ;
    int index = 0;
    for (int i = 0 ; i < size ; i++){
        patient[i].display();
        if (patient[i].getbill() > max)
        max = patient[i].getbill();
        index = i ; 
    }
    cout << "Highest bill among patient is "<<index <<" : "<<max<<endl;
    delete [] patient;
    patient = nullptr;
}