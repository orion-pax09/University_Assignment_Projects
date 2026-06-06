#include <iostream>
using namespace std;
class SmartDevice{
    protected:
    bool Status;
    public:
    SmartDevice(){
        Status = false;
    }
    SmartDevice (bool s):Status(s){}
    virtual void turnoff()=0;
    virtual void  turnon()=0;
    virtual void getstatus(){
        cout << "SmartDevice() calling getstatus()"<<endl;    
    }
    virtual void  performaction(){
        cout<< "SmartDevice()calling performaction()"<<endl;
    }
    virtual ~SmartDevice(){
        cout << "Base class destructor called"<<endl;
    }
};
class SmartLight:public SmartDevice{
    private:
    int n;
    public:
    SmartLight(){
        n = 0;
        Status = false;
    }
    SmartLight(int N,bool status):SmartDevice(status){
        n=N;
    }
    void turnon()override{
        Status = true;
        cout << "Smart Light is turned on"<<endl;
    }
    void turnoff()override{
        Status = false;
        cout << "Smart light is turned off"<<endl;
    }
    void performaction()override{
        cout << "Adjusting brightness to: "<<" watt "<<n<<endl;
    }
    void getstatus() override {
        cout << "Smart Light is " << (Status ? "on" : "off") << endl;
    }
    ~SmartLight(){
        cout << "~Smartlight() called"<<endl;
    }
};
class SmartThermostat:public SmartDevice{
    private:
    int temp;
    public:
    SmartThermostat(){
        temp = 0;
        Status =false;
    }
    SmartThermostat(bool s , int T):SmartDevice(s){
        temp =T;
    }
    void turnoff()override{
        Status= false;
        cout << "Smart Thermostat is turned off"<<endl;
    }
    void turnon()override{
        Status = true;
        cout << "Smart thermostat is turned on"<<endl;
    }
    void getstatus () override{
        cout << (Status?"Thermostat is turned ON":" Thermostats is turned OFF")<<endl;
    }
    void performaction() override{
        cout << "Setting temperature to "<<temp<< " F"<<endl;
    }
    ~SmartThermostat(){
        cout << "~SmartThermostat called"<<endl;
    }
};
class SmartLockDoor:public SmartDevice{
    public:
    SmartLockDoor(){
        Status = false;
    }
    SmartLockDoor(bool s):SmartDevice(s){}
    void turnoff() override{
        Status = false;
        cout << "Smart Lock door is turned off"<<endl;
    }
    void turnon() override{
        Status = true;
        cout << "Smart lock door is turned on"<<endl;
    }
    void getstatus()override{
        if (Status==true){
            cout << "Smart door is locked"<<endl;
        }
        else{
            cout << "Smart door is unlocked"<<endl;
        }
    }
    void performaction() override{
        if (Status==true){
        cout << "Performing action: Locking the door"<<endl;
        }
        else{
        cout << "Performing action: unlocking the door"<<endl;
        }
    }
    ~SmartLockDoor(){
        cout << "~SmartLockDoor called"<<endl;
    }
};
class SmartCamera:public SmartDevice{
    public:
    SmartCamera():SmartDevice(false){}
    SmartCamera(bool s):SmartDevice(s){}
    void turnoff() override{
        Status = false;
        cout << "Smart camera is turned off"<<endl;
    }
    void turnon() override{
        Status = true;
        cout << "Smart camera is turned on"<<endl;
    }
    void getstatus()override{
        if (Status==true){
            cout << "Recording video"<<endl;
        }
        else{
            cout << "Recording is turned off"<<endl;
        }
    }
    void performaction() override{
        if (Status==true){
        cout << "Performing action: monitoring area"<<endl;
        }
        else{
        cout << "Performing action: not monitoring area"<<endl;
        }
    }
    ~SmartCamera(){
        cout << "~SmartCamera() called"<<endl;
    }
};
int main(){
    SmartDevice*device[4];
    device[0] = new SmartLight(78 , true);
    device[1] = new SmartCamera(true);
    device[2] = new SmartLockDoor(false);
    device[3] = new SmartThermostat(true , 28);
    cout << "----------Checking device status----------"<<endl;
    for (int i = 0 ; i < 4 ; i++){
        device[i]->getstatus();
    }
    cout << "----------Checking perform action----------"<<endl;
    cout << "Device performing action "<<endl;
    for (int i = 0 ; i < 4 ; i++){
        device[i]->performaction();
    }
    cout << " ---------- Device turning on ---------- "<<endl;
    for (int i = 0 ; i < 4 ; i++){
        device[i]->turnon();
    }
    cout << " ---------- Device turning off ---------- "<<endl;
    for (int i = 0 ; i < 4 ; i++){
        device[i]->turnoff();
    }
    for (int i = 0 ; i < 4 ; i++){
        delete device[i];
    }
}