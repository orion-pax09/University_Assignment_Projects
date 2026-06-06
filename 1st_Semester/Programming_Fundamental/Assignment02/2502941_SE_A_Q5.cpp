/*Name:-
Muhammad Hamza Khan*/
/*Roll Number:- 
2502941*/
/*Program:-
SE_A*/
/*Question no. :
252941_SE_A_Q1.cpp*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string input;
    cout << "Start General diagnosis"<<endl;
    cout << "Recording system information....Done"<<endl;
    cout << "Rebooting server condition to see if condition still exists"<<endl;
    cout << "Is this newly installed server?"<<endl;
    cout<<"Enter either Y or N"<<endl;
    cin >> input;
    if (input =="yes"||input =="y" || input =="Y" ||input=="YES"){ 
        /*Condition for first part of reseat*/
        cout << "Reseat any components that may have come loose during shipping and reboot the server..."<<endl; 
        cout<<"Enter either Y or N"<<endl;
        cin >> input;
        if (input =="yes"||input =="y" || input =="Y" ||input=="YES"){ /*condition yes for reseat any components that may have....*/
            cout << "Were option added or was configuration changed recently?"<<endl;
            cout<<"Enter either Y or N"<<endl;;
            cin>> input;
            if (input =="yes"||input =="y" || input =="Y"||input=="YES" ){ /*condition yes for were option added or....part1*/
                cout << "Isolate what has changed. Verify it was installed correctly. Restore server to last known working state or original shipped configuration."<<endl;
                cout<< "Does condition still exist?"<<endl;
                cout<<"Enter either Y or N"<<endl;
                cin >> input;
                if (input =="yes"||input =="y" || input =="Y"||input=="YES" ){ /*Condition isolating what has changed...*/
                    cout<<"Isolating and minimizing the memory configuration..."<<endl;
                    cout << "Does condition still exist?"<<endl;
                    cin >>input;
                    if (input =="yes"||input =="y" || input =="Y"||input=="YES" ){ /*Condition yes for Isolating and minimizing configuration entering */
                        cout <<"Breaking server down to minimal configuration"<<endl;
                        cout<<"Does condition still exist?"<<endl;
                        cout<<"Enter either Y or N"<<endl;
                        cin>>input;
                        if (input =="yes"||input =="y" || input =="Y"||input=="YES" ){  /*Condition part of 2 after entering yes no.4*/
                            cout<< "Troubleshooting or replacing basic server spare parts"<<endl;
                            cout<< "Does condition still exist?"<<endl;
                            cout<<"Enter either Y or N"<<endl;
                            cin>>input;
                            if (input =="yes"||input =="y"||input=="YES" || input =="Y" ){
                                cout << "Ensure following information is available"<<endl<<"1.Survey configuration snapshot"<<endl<<"2.OS event log file"<<endl<<"3.Full crash damp"<<endl;
                                cout << "Call HP service provider"<<endl; /* yes condition ends here for Troubleshooting...and here begins for No condition*/
                            }
                            else if (input =="No"||input =="N" || input =="n"||input =="no" ){ /*No Condition for Troubleshooting or replacing basic server spare parts*/
                            cout<<"Recording symptom & error information on repair tag if sending back a failed part"<<endl;
                        }
                            else{
                            cout<<"Invalid input. Enter either N or Y"; /*Invalid condition for troubleshooting or replacing...*/
                        }
                    }
                    else if (input =="No"||input =="N" || input =="n"||input =="no" ){
                    cout << "Recording action taken"<<endl; /*No condition for isolating and minimizing configuration*/
                    cout<<"End";
                }
                else if (input =="No"||input =="N" || input =="n"||input =="no" ){
                    cout <<"Recording action taken"<<endl;  /*No condition for isolating what has changed.....*/
                    cout<<"End";
                }
                else{
                    cout << "Invalid input.Enter either Y or N"; /*Invalid condition for isolating what has changed...*/
                }
            }
            if (input =="yes"||input =="y" || input =="Y"||input =="YES" ){
                cout<<"Isolating and minimizing memory configuration"<<endl;
                cout<< "Does condition still exist?"<<endl;/*Condition for checking service notification after no 
                condition of were option added or was configuration changed */
                cout<<"Enter either Y or N"<<endl;
                cin>> input;
                if (input =="yes"||input =="y" || input =="Y"||input =="YES" ){
                    /*yes condition of isolating minimizing configuration after  no 
                    condition of were option added or was configuration changed*/
                    cout << "Breaking server down to minimal configuration"<<endl; /*Breaking server down to part 2*/
                    cout << "Does condition still exist"<<endl;
                    cin>>input;
                    if (input =="yes"||input =="y" || input =="Y"||input=="YES" ){  /*Condition yes part for breaking server 
                        down to minimal configurtion part 2*/
                        cout<< "Troubleshooting or replacing basic server spare parts"<<endl;
                        cout<< "Does condition still exist?"<<endl;
                        cout<<"Enter either Y or N"<<endl;
                        cin>>input;
                        if (input =="yes"||input =="y"||input=="YES" || input =="Y" ){
                            cout << "Ensure following information is available"<<endl<<"1.Survey configuration snapshot"<<endl<<"2.OS event log file"<<endl<<"3.Full crash damp"<<endl;
                            cout << "Call HP service provider"<<endl;/* yes condition ends here for Troubleshooting...
                            and here begins for No condition part 2*/
                        }
                        else if (input =="No"||input =="N" || input =="n"||input =="no" ){ /*No Condition for Troubleshooting 
                            or replacing basic server spare parts*/
                            cout<<"Recording symptom & error information on repair tag if sending back a failed part"<<endl;
                            cout << "End";
                        }
                        else{
                            cout<<"Invalid input. Enter either N or Y"; /*Invalid condition for troubleshooting or replacing...*/
                        }
                    }
                }
                else if (input =="No"||input =="N" || input =="n"||input =="no"){
                    cout <<"Recording action taken"<<endl;
                    cout <<"end";
                }
                else{
                    cout<<"Invalid input. Enter either N or Y";
                }
            }
              
            else if (input =="No"||input =="N" || input =="n"||input =="no"){
                cout << "Recording action taken"<<endl;
                cout << "end";
            }
            else{
                    cout<<"Invalid input. Enter either N or Y";
                }
            }
        else if (input =="No"||input =="N" || input =="n"||input =="no"){
            cout << "Recording action taken"<<endl;
            cout << "end";
        
        }
        else{
                cout<<"Invalid input. Enter either N or Y";
            }
        }
        else if (input =="No"||input =="N" || input =="n"||input =="no"){
            cout << "Checking for service notification"<<endl;
            cout<< "Downloading the latest software and firmware from the HP website"<<endl;
            cout<< "Does condition exist?"<<endl;
            cout<<"Enter either Y or N"<<endl;
            cin>> input;
            if (input =="yes"||input =="y" || input =="Y"||input =="YES" ){
                cout<<"Isolating and minimizing memory configuration"<<endl;
                cout<< "Does condition still exist"<<endl;
                cin>>input;
                if (input =="yes"||input =="y" || input =="Y"||input =="YES" ){
                    cout<< "Troubleshoot or replace basic server spare parts"<<endl;
                    cout << "Break server down to minimal configuration"<<endl;
                    cout<< "Does condition still exist?"<<endl;
                    cin>>input;
                    if (input =="yes"||input =="y" || input =="Y" || input =="YES"){
                        cout << "Ensure following information is available"<<endl<<"1.Survey configuration snapshot"<<endl<<"2.OS event log file"<<endl<<"3.Full crash dump"<<endl;
                        cout << "Call HP service provider";
                    }
                    else if (input =="No"||input =="N" || input =="n"||input =="no" ){
                        cout<<"Record symptom & error information on repair tag if sending back a failed part"<<endl;
                        cout<<"END";
                    }
                    else{
                        cout<<"Invalid input. Enter either N or Y";
                    }                
                }                
        else if (input =="No"||input =="n" || input =="N" || input =="no" ){
                cout<<"Recording action taken"<<endl;
                cout<< "End";
            }
            
        else{
            cout<<"Invalid input. Enter either N or Y";
            }
        }
         else if (input =="No"||input =="n" || input =="N" || input =="no" ){
                cout<<"Recording action taken"<<endl;
                cout<< "End";
            }
            
            else{
                cout<<"Invalid input. Enter either N or Y";
    }
  

}
}}  else if (input =="No"||input =="n" || input =="N" || input =="no" ){
        cout<<"Recording action taken"<<endl;
        cout<< "End";
    }}
