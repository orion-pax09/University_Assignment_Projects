#include <iostream>
using namespace std;
class person {
    protected:
    int age;
    string name;
    public:
    person(){
        age = 0;
        name = "-";
    }
    person(int A , const string&n){
        age = A;
        name = n;
    }
    virtual void accessing_condition() = 0;
    virtual void display(){
        cout << "Age: "<<age<<endl;
        cout << "Name: "<<name<<endl;
    }
    int get_age(){
        return age;
    }
    string getname(){
        return name;
    }
    virtual ~person(){
        cout << "Base virtual destructor called"<<endl;
    }
};
class patient:public person{
    protected:
    int patient_ID;
    string disease_name;
    string date_Admission;
    string medication;
    public:
    patient(){
        patient_ID = 0;
        disease_name = "-";
        date_Admission = "-";
        medication = "-";
    }
    patient(int A , const string&n , int ID , const string&DN , const string&DA,const string&medicine):person(A , n){
        patient_ID = ID;
        disease_name = DN;
        date_Admission = DA;
        medication = medicine;
    }
    void accessing_condition()override{   
        if (patient_ID>0){
            cout <<"Access Granted"<<endl;
        }    
        else{
            cout << "Access denied"<<endl;
        }
    }
    int getID(){
        return patient_ID;
    }
    string get_diseasename(){
        return disease_name;
    }
    string get_Dateadmission(){
        return date_Admission;
    }
    string get_medication(){
        return medication;
    }
    void display(){
        person::display();
        cout << "Patient ID: "<<patient_ID<<endl;
        cout << "Disease name: "<<disease_name<<endl;
        cout << "Date Admission: "<<date_Admission<<endl;
        cout << "Medication: "<<medication<<endl;
    }
    ~patient()override{
        cout << "patient class destructor called"<<endl;
    }
};
class medicalDevice{
    protected:
    int Device_ID;
    string device_name;
    public:
    medicalDevice(){
        Device_ID = 0;
        device_name = "-";
    }
    medicalDevice(int ID , const string&devicename){
        Device_ID = ID;
        device_name = devicename;
    } 
    void display(){
        cout << "Device ID: "<<Device_ID<<endl;
        cout << "Device name: "<<device_name<<endl;
    }
};
class criticalPatient:public patient{
    protected:
    medicalDevice *Device;
    int severity_level;
    float heart_rate;
    float blood_pressure;
    public:
    criticalPatient(){
        Device = nullptr;
        severity_level = 0;
        heart_rate = 0.0;
        blood_pressure = 0.0;
    }
    criticalPatient(medicalDevice*d ,int A , const string&n , int ID , const string&DN , const string&DA,const string&medicine,int sl , float hr , float bp):patient(A , n , ID , DN , DA , medicine){
        severity_level = sl ; 
        heart_rate = hr ;
        blood_pressure = bp;
        Device = d;
    }
    criticalPatient& operator++(){
        ++severity_level;
        try
        {
            if (severity_level < 1 || severity_level > 10){
                throw severity_level;
            }
        }
        catch(int x) {
            cout << "Invalid severity level: "<<severity_level<<endl;
            severity_level = 10;
        }
        return *this;
    }
    criticalPatient&operator++(int dummy){
        criticalPatient temp = *this;
        severity_level++;
        return temp;
    }
    void accessing_condition()override{
        if (severity_level >=8){
            cout<<"ICU ward access is granted"<<endl;
        }
        else if (severity_level <=8 && severity_level >= 5){
            cout << "general ward access is granted"<<endl;
        }
        else if (severity_level>=1 && severity_level <=5){
            cout << "Diagnosis medical check-up is granted"<<endl;
        }
    }
    
    friend ostream&operator<<(ostream&out , criticalPatient&obj){
        if (obj.Device!=nullptr){
            obj.Device->display();
        }
        obj.patient::display();
        out << "Heart rate: "<<obj.heart_rate<<endl;
        out << "Blood pressure: "<<obj.blood_pressure<<endl;
        out << "Severity level: "<<obj.severity_level<<endl;
        return out;
    }
    ~criticalPatient()override{
        cout << "Critical patient destructor called"<<endl;
        delete Device;
    }
};
class Nurse{
    private:
    int nurse_Id;
    string nurse_name;
    string hospitAL_name;
    string shift;
    public:
    Nurse(){
        nurse_Id = 0;
        nurse_name = "-";
        hospitAL_name = "-";
        shift = "-";
    }
    Nurse(int ID , const string&name , const string&hn , const string&shift){
        nurse_Id = ID;
        nurse_name = name;
        hospitAL_name = hn;
        this->shift = shift;
    }
    void display(){
        cout << "nurse name: "<<nurse_name<<endl;
        cout << "nurse id: "<<nurse_Id<<endl;
        cout << "hospital name: "<<hospitAL_name<<endl;
        cout << "Duty shift: "<<shift<<endl;
    }
    ~Nurse(){
        cout << "Nurse destructor called"<<endl;
    }
};
int main(){
    person*ptr;
    patient p(24 , "Son Soku" , 394 , "Heart attack" , "22 / 04 / 2026" , "Aspirin" );
    ptr = &p;
    ptr->accessing_condition();
    ptr->display();
    medicalDevice*d = new medicalDevice(45 , "ECG meter");
    d->display();
    criticalPatient c1 (d , 33 , "Shane watson " , 45 , "Heart attack" , "05 / 08 / 2026 " , "Aspirin" , 6, 98.0 , 122.2f);
    c1.display();

}