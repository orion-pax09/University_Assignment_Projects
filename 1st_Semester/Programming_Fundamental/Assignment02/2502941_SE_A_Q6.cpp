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
    int choice;
    cout << "Here is the list of all ticket prices for night matches in Rawalpindi Cricket Stadium"<<endl;
    cout << "1. 27 February 2026--Islamabad United vs Quetta Gladiators,Pindi Cricket Stadium"<<endl<<"(7:00 PM-10:15 PM)"<<endl;
    cout << "2. 28 Feb 2026 -- Peshawar Zalmi vs Lahore Qalandars, Pindi Cricket Stadium"<<endl<<"(8:00 PM-11:15 PM)"<<endl;
    cout << "3. 29 Feb 2026 -- Islamabad United vs Peshawar Zalmi, Pindi Cricket Stadium"<<endl<<"(7:00 pm-10:15 PM)"<<endl;
    cout << "4. 1 Mar 2026  -- Islamabad United vs Karachi Kings, Pindi Cricket Stadium"<<endl<< "( 7:00 PM-10:15 PM)"<<endl;      
    cout << "5. 2 Mar 2026  -- Peshawar Zalmi vs Karachi Kings, Pindi Cricket Stadium"<<endl<<   "(7:00 PM-101:5 PM)"<<endl;
    cout << "6. 5 Mar 2026  -- Peshawar Zalmi vs Quetta Gladiators, Pindi Cricket Stadium"<<endl<<"(7:00 PM-10:15 PM)"<<endl;
    cout << "7. 7 Mar 2026  -- Peshawar Zalmi vs Islamabad United, Pindi Cricket Stadium"<<endl<<"(2:00 PM-5:15 PM)"<<endl;
    cout << "8. 8 Mar 2026  -- Multan Sultans vs Islamabad United, Pindi Cricket Stadium"<<endl<<"(2:00 PM-5:15PM)"<<endl;
    cout << "Enter your choice(1-8):";
    cin >> choice;
    int vip,premiumseat,firstclass,general;
    switch(choice){
        case 1:
        case 2:
        case 3:{
        vip =3000;
        premiumseat=1500;
        firstclass=1000;
        general=500;
        break;
        }
        case 4:
        case 7:{
        vip=2000;
        premiumseat=1000;
        firstclass=500;
        general=250;
        break;
        }
        case 5:
        case 6:
        case 8:{
        vip=1500;
        premiumseat=1000;
        firstclass=500;
        general=250;
        break;
        }
    }
    if (choice > 8|| choice <1){
        cout << "Invalid input.Enter your choice between 1 and 8";
    }
    else{
        /*I made two type of seat to generate different number of seats*/
        int ImranKhan=rand() % 1000+1;
        int ImranKhan2=rand() % 1000+1;
        int Imrankhanseat=ImranKhan;
        int Imrankhanseat1=ImranKhan2;                  
        int javedminand=rand() % 1000+1;
        int javedminand2=rand() % 1000+1;
        int javedminadseat= javedminand;
        int javedminadseat1=javedminand2;
        int javedakhtar=rand() % 1000+1;
        int javedakhtar2=rand() % 1000+1;
        int javedakhtarseat=javedakhtar;
        int javedakhtarseat1=javedakhtar2;
        int azharmehmood=rand() % 1000+1;
        int azharmehmood2=rand() % 1000+1;
        int azharmehmoodseats=azharmehmood;
        int azharmehmoodseats1=azharmehmood2;
        int sohailtanveer=rand() % 3000+1;
        int sohailtanveer2 = rand()% 3000+1;
        int sohailtanveer1=rand() % 3000+1;
        int sohailtanveerseats=sohailtanveer;
        int sohailtanveerseats1=sohailtanveer2;
        int shohaibakhtar =rand() % 3000+1;
        int sohaibakhtar2=rand() % 3000+1;
        int sohailbakhtarseats=shohaibakhtar;
        int sohailbakhtarseats1= sohaibakhtar2;
        int imranbuksh = rand() % 2500+1;
        int imranbuksh2= rand()% 2500+1;
        int imranbukshseats = imranbuksh; 
        int imranbukshseats1 = imranbuksh2;
        int arafat = rand() % 2500+1;
        int arafat2= rand()% 2500+1;
        int arafatseats=arafat;
        int arafatseats1=arafat2;
        int seat_availability;
        int choice1;
        /*Implement two types of seats for each enclosures when users enter input to select ticket,seats and enclosures*/
        cout << "Here is a list of names of all enclosures, their class, ticket price, and number of seats available"<<endl;
        cout << "-------------------Select seat type from Imran Khan enclosure--------------"<<endl;
        cout <<  "1.  Imran khan     - VIP         -- Rs."<< vip <<"--Seats left:"<<(Imrankhanseat*30)/100<<endl;
        cout <<  "2.  Imran Khan     - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(Imrankhanseat*20)/100<<endl;
        cout <<  "3.  Imran Khan     - First-class -- Rs."<<firstclass<<"--Seats left:"<<(Imrankhanseat1*30)/100<<endl;
        cout <<  "4.  Imran Khan     - General     -- Rs."<<general<<" --Seats left:"<<(Imrankhanseat1*20)/100<<endl;
        cout << "-------------------Select seat type Javed Minad enclosure------------------"<<endl;
        cout <<  "5.  Javed Minad    - VIP         -- Rs."<<vip<<"--Seats left:"<<(javedminadseat*30)/100<<endl;
        cout <<  "6.  Javed Minad    - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(javedminadseat*20)/100<<endl;
        cout <<  "7.  Javed Minad    - First-class -- Rs."<<firstclass<<"--Seats left:"<<(javedminadseat1*30)/100<<endl;  
        cout <<  "8.  Javed Minad    - General     -- Rs."<<general<<" --Seats left:"<<(javedminadseat1*20)/100<<endl;
        cout << "-------------------Select seat type Javed Akhtar enclosure------------------"<<endl;
        cout <<  "9.  Javed Akhtar   - VIP         -- Rs."<<vip<< "--Seats left:"<<(javedakhtarseat*30)/100<<endl;
        cout <<  "10. Javed Akhtar   - Premium     -- Rs."<<premiumseat<<" --Seats left:"<<(javedakhtarseat*20)/100<<endl;
        cout << "11.  Javed Akhtar   - First-class -- Rs."<<firstclass<<"--Seats left:"<<(javedakhtarseat1*30)/100<<endl;
        cout << "12.  Javed Akhtar   - General     -- Rs."<<general<< "--Seats left:"<<(javedakhtarseat1*20)/100<<endl;
        cout << "-------------------Select seat Azhar Mehmood enclosure----------------------"<<endl;
        cout << "13. Azhar Mehmood   - VIP         -- Rs."<<vip<<"--Seats left:"<<(azharmehmoodseats*30)/100<<endl;
        cout << "14. Azhar Mehmood   - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(azharmehmoodseats*20)/100<<endl;
        cout << "15. Azhar Mehmood   - First-class -- Rs."<<firstclass<<"--Seats left:"<<(azharmehmoodseats1*30)/100<<endl;
        cout << "16. Azhar Mehmood   - General     -- Rs."<<general<< "--Seats left:"<<(azharmehmoodseats1*20)/100<<endl;
        cout << "-------------------Select seat Sohail Tanveer enclosure----------------------"<<endl;
        cout << "17. Sohail Tanveer  - VIP         -- Rs."<<vip<<"--Seats left:"<<(sohailtanveerseats*30)/100<<endl;
        cout << "18. Sohail Tanveer  - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(sohailtanveerseats*20)/100<<endl;
        cout << "19. Sohail Tanveer  - First-class -- Rs."<<firstclass<<"--Seats left:"<<(sohailtanveerseats1*30)/100<<endl;
        cout << "20. Sohail Tanveer  - General     -- Rs."<<general<< "--Seats left:"<<(sohailtanveerseats1*20)/100<<endl;
        cout << "-------------------Select seat Sohaib Akhtar enclosure----------------------"<<endl;
        cout << "21. Sohaib Akhtar   - VIP         -- Rs."<<vip<<"--Seats left:"<<(sohailbakhtarseats*30)/100<<endl;
        cout << "22. Sohaib AKhtar   - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(sohailbakhtarseats*20)/100<<endl;
        cout << "23. Sohaib akhtar   - First-class -- Rs."<<firstclass<<"--Seats left:"<<(sohailbakhtarseats1*30)/100<<endl;
        cout << "24. Sohaib Akhtar   - General     -- Rs."<<general<< "--Seats left:"<<(sohailbakhtarseats1*20)/100<<endl;
        cout << "-------------------Select seat Imran Buksh enclosure-------------------------"<<endl;
        cout << "25. Imran Buksh     - VIP         -- Rs."<<vip<<"--Seats left:"<<(imranbukshseats*30)/100<<endl;
        cout << "26. Imran Buksh     - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(imranbukshseats*20)/100<<endl;
        cout << "27. Imran Buksh     - First-class -- Rs."<<firstclass<<"--Seats left:"<<(imranbukshseats1*30)/100<<endl;
        cout << "28. Imran Buksh     - General     -- Rs."<<general<< "--Seats left:"<<(imranbukshseats1*20)/100<<endl;
        cout << "------------------Select seat Yasir Arafat enclosure---------------------"<<endl;
        cout << "29. Yasir Arafat    - VIP         -- Rs."<<vip<<"--Seats left:"<<(arafatseats*30)/100<<endl;
        cout << "30. Yasir  Arafat   - Premium     -- Rs."<<premiumseat<<"--Seats left:"<<(arafatseats*20)/100<<endl;
        cout << "31. Yasir Arafat    - First-class -- Rs."<<firstclass<<"--Seats left:"<<(arafatseats1*30)/100<<endl;
        cout << "32. Yasir Arafat    - General     -- Rs."<<general<< "--Seats left:"<<(arafatseats1*20)/100<<endl;
        cout << "-------------------------------------------------------------------------"<<endl;
        cout<<"Choose only 1 above ticket menu:";
        cin >> choice1;
        int selected_ticket;
        /*Always enter the choice between 1 and 32*/
        if (choice1 <1 || choice1 > 32){
            cout<< "Invalid input. Enter the number between 1 and 32 to select ticket."<<endl;
        }
        else{
            /*Implementing all cases for every ticket chose by users that has different prices,seat no. avaialbility depending upon enclosures*/
        switch(choice1){
            case 1:
            cout << "You have selected VIP seat from Imran khan enclosure"<<endl;
            selected_ticket= vip;
            seat_availability=(Imrankhanseat*30)/100;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 2:
            seat_availability=(Imrankhanseat*20)/100;
            cout << "You have selected Premium seat from Imran khan enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;            
            case 3:
            seat_availability=(Imrankhanseat1*30)/100;
            cout << "You have selected First class seat from Imran khan enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;            
            case 4:
            seat_availability=(Imrankhanseat1*20)/100;
            cout << "You have selected General seat from Imran Khan enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 5:
            seat_availability=(javedminadseat*30)/100;
            cout << "You have selected VIP seat from Javed Minaad enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 6:
            seat_availability=(javedminadseat*20)/100;
            cout << "You have selected Premium seat from Javed Minaad enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 7:
            seat_availability=(javedminadseat1*30)/100;
            cout << "You have selected First class seat from Javed Minaad enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 8:
            seat_availability=(javedminadseat1*20)/100;
            cout << "You have selected General seat from Javed Minad enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 9:
            seat_availability=(javedakhtarseat*30)/100;
            cout << "You have selected VIP seat from Javed Akhtar enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 10:
            seat_availability=(javedakhtarseat*20)/100;
            cout << "You have selected Premium seat from Javed Akhtar enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 11:
            seat_availability=(javedakhtarseat1*30)/100;
            cout << "You have selected First class seat from Javed Akhtar enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 12:
            seat_availability=(javedakhtarseat1*20)/100;
            cout << "You have selected General seat from Javed Akhtar enclosure"<<endl;
            selected_ticket=general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 13:
            seat_availability=(azharmehmoodseats*30)/100;
            cout << seat_availability<<endl;
            cout << "You have selected VIP seat from Azhar Mehmood enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 14:
            seat_availability=(azharmehmoodseats*20)/100;
            cout << "You have selected Premium seat from Azhar Mehmood enclosure"<<endl;
            selected_ticket=premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 15:
            seat_availability=(azharmehmoodseats1*30)/100;
            cout << "You have selected  First class seat from Azhar Mehmood enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 16:
            seat_availability=(azharmehmoodseats1*20)/100;
            cout << "You have selected  General seat from Azhar Mehmood enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 17:
            seat_availability=(sohailtanveerseats*30)/100;
            cout << "You have selected  VIP seat from Sohail Tanveer enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 18:
            seat_availability=(sohailtanveerseats*20)/100;
            cout << "You have selected  Premium seat from Sohail Tanveer enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 19:
            seat_availability=(sohailtanveerseats1*30)/100;
            cout << "You have selected  First class seat from Sohail Tanveer enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 20:
            seat_availability=(sohailtanveerseats1*20)/100;
            cout << "You have selected  General seat from Sohail Tanveer enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 21:
            seat_availability=(sohailbakhtarseats*30)/100;
            cout << "You have selected VIP seat from Sohaib Akhtar enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 22:
            seat_availability=(sohailbakhtarseats*20)/100;
            cout << "You have selected Premium seat from Sohaib Akhtar enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 23:
            seat_availability=(sohailbakhtarseats1*30)/100;
            cout << "You have selected First class seat from Sohaib Akhtar enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 24:
            seat_availability=(sohailbakhtarseats1*20)/100;
            cout << "You have selected General seat from Sohaib Akhtar enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 25:
            seat_availability=(imranbukshseats*30)/100;
            cout << "You have selected VIP seat from Imran Buksh enclosure"<<endl;
            selected_ticket= vip;  
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;
            case 26:
            seat_availability=(imranbukshseats*20)/100;
            cout << "You have selected Premium seat from Imran Buksh enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 27:
            seat_availability=(imranbukshseats1*30)/100;
            cout << "You have selected First class seat from Imran Buksh enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 28:
            seat_availability=(imranbukshseats1*20)/100;
            cout << "You have selected General class seat from Imran Buksh enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 29:
            seat_availability=(arafatseats*30)/100;
            cout << "You have selected VIP seat from Yasir Arafat enclosure"<<endl;
            selected_ticket= vip;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 30:
            seat_availability=(arafatseats*20)/100;
            cout << "You have selected Premium seat from Yasir Arafat enclosure"<<endl;
            selected_ticket= premiumseat;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 31:
            seat_availability=(arafatseats1*30)/100;
            cout << "You have selected First class seat from Yasir Arafat enclosure"<<endl;
            selected_ticket= firstclass;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            
            break;
            case 32:
            seat_availability=(arafatseats1*20)/100;
            cout << "You have selected General seat from Yasir Arafat enclosure"<<endl;
            selected_ticket= general;
            cout << "Ticket price is:"<<" "<<selected_ticket<<endl;
            break;} 
            /*Choose whether to purchase tickets for family or adults*/
            int button2;
            cout << "1. Press 1 button to purchase a ticket for family"<<endl ;
            cout << "2. Press 2 to purchase a ticket for adults"<<endl;
            cin >> button2;
            switch(button2){
            case 1:
            int childrennumber;
            int adultnumber;
            int cnic;
            int discount1;
            int discount2;
            double total;
            int price;
            int price1;
            /*New seat is updated after purchasing tickets and selecting seats*/
            int updated_Seat;
            /*Total discount variable*/ 
            int adult_final;
            /*Users will enter 13 digits for entering CNIC ID number*/
            int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13;
            cout <<"Enter the number of adults(only upto 4):"<<endl;
            cin >> adultnumber;
            if (adultnumber>=1 && adultnumber<=4){
               
                price = adultnumber*selected_ticket; /*ticket total price*/
               
                discount1=price*0.10; /*Discount is applied for adult number between 1 and 4*/
                adult_final = price - discount1;
                cout << "Ticket price without discount:"<<"RS."<<price<<endl;
                cout<< "Ticket price with 10 percent discount:"<<" "<<adult_final<<endl;
                cout << "Enter the number of children(only upto 5):";
                cin >> childrennumber;
                total = adultnumber + childrennumber; /*total people selecting seat and purchasing tickets*/
                
                updated_Seat=seat_availability - total; /*No. of seats remaining*/
                
                if (total <=seat_availability){
                    cout<<"Seat number has successfully been updated from"<< seat_availability<<"to"<<updated_Seat<<endl;
                    cout <<"There is seat available.Paymant has been proceeded. Please collect your ticket at ticket encounter."<<endl;
            }
            /*If there is no seat available*/
                else{
                cout<<"Seats has already been limited. Please choose the seats from another enclosure."<<endl;
                cout <<"Seat number:"<<seat_availability<<endl;
                cout <<"No seats available.Please choose seat from other enclosure"<<endl;
                break;
            }
                if (childrennumber <=5 && childrennumber>=1){
                cout << "Childeren number:"<<childrennumber<<" "<<"have been selected "<<endl ;
                price1 = childrennumber * selected_ticket;
                discount2=price1 * 0.20;
                cout << "Ticket price without discount:"<<"RS."<<price1<<endl;
                cout << "Ticket price with 20 percent discount:"<<discount2<<endl;
                cout << "Enter the CNIC ID numbers upto 13 digits";
                cin>>d1>>d2>>d3>>d4>>d5>>d6>>d7>>d8>>d9>>d10>>d11>>d12>>d13;
                cout<< "CNIC confirmed:"<<d1<<d2<<d3<<d4<<d5<<d6<<d7<<d8<<d9<<d10<<d11<<d12<<d13<<endl;
                cout << "Children number:"<<childrennumber<<endl;
                cout <<"Adult number:"<<adultnumber<<endl;
                cout << "Discount for adult:"<<"Rs."<<discount1<<endl;
                cout <<"Discount for children:"<<"Rs."<<discount2<<endl;
                cout << "Price for adults without discount:"<<" "<<price<<endl;
                cout << "Price for children without discout:"<<" "<<price1<<endl;
                
                /*Total ticket price for whole family*/
                total= (price + price1)- (discount1 + discount2); 
                
                cout<<"Total ticket price:"<<"Rs."<<total<<endl;
            
                }
               
                else if(childrennumber<1){
                    cout << "Minimum 1 children ia required to book for family"<<endl;
                }
                else if(childrennumber > 5){
                    cout << "There is only maximum 5 children per ticket please buy new ticket"<<endl;
                }
                else{
                    cout << "Invalid input"<<endl;
                }
                
            
            }
             
            else if (adultnumber >4 ){
                cout << "Maximum 4 adults are allowed per ticket. please buy other ticket."<<endl;
            }
            else{
                cout<< "Minimum one adult is required to book for family"<<endl;
            }
            break;
            /*Condition for adults*/
            case 2:
            cout <<"Enter the number of adults:"<<endl;
            cin >>adultnumber;
            if (adultnumber >=1 && adultnumber <=4){
                cout<<"Discount is not applied for adult number between 1 and 4"<<endl;
                /*Setting price for adults according to number*/
                price = adultnumber*selected_ticket;
                total=adultnumber;
                updated_Seat=seat_availability-total;
                /*Setting seat available for adults*/
                if (total>=seat_availability){
                    cout<<"There is seat available.Please proceed to pay for ticket"<<endl;
                    cout<<"Seat number has successfully been updated from"<< seat_availability<<"to"<<updated_Seat<<endl;
                }
                else{
                    cout <<"Seat number:"<<seat_availability<<endl;
                    cout <<"No seats available.Please choose seat from other enclosure"<<endl;
                    break;
                }
                cout << "Enter the CNIC ID card:";
                cin>>d1>>d2>>d3>>d4>>d5>>d6>>d7>>d8>>d9>>d10>>d11>>d12>>d13;
                cout << "Ticket price:"<<"Rs."<<price<<endl;
                cout<< "CNIC confirmed:"<<d1<<d2<<d3<<d4<<d5<<d6<<d7<<d8<<d9<<d10<<d11<<d12<<d13<<endl;



                    }        
            else if  (adultnumber >=5 && adultnumber <=8){
                cout<<"10 percent discount has been applied.."<<endl;
                price1=adultnumber*selected_ticket;
                discount1=price1 *0.10;
                total = price1 - discount1;
                cout << "Enter the CNIC ID card:";
                cin>>d1>>d2>>d3>>d4>>d5>>d6>>d7>>d8>>d9>>d10>>d11>>d12>>d13;
                cout<< "CNIC confirmed:"<<d1<<d2<<d3<<d4<<d5<<d6<<d7<<d8<<d9<<d10<<d11<<d12<<d13<<endl;
                cout << "Price for adults:"<<price1<<endl;
                cout <<"Ticket price:"<<"Rs."<<total<<endl;
                
            }
            else if(adultnumber>8||adultnumber<1){
                cout <<"Invalid input.Enter adult number between 1 and 8"<<endl;

            }
            else{
                cout << "Enter number between 1 and 8 for adult..."<<endl;
            }
            break; 
        }    
}
}
}     
    


        
        
            
       
     
    
    