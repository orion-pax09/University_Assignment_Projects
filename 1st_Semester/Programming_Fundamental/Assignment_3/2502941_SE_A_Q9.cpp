/*
Name ;- Muhammad Hamza Khan
ROll No:- 2502941
Assignment No 3
Question No. 9*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    int star;
    cout << "Enter the number:"<<endl;
    cin >> n;
    if (n<1)
    {
        cout << "Inavlid.Enter the number greater than 0"<<endl;
    }
    else
    {
        cout << "--------------------pattern 2----------------------"<<endl;
        cout << "Pattern 2"<<endl;
        for(int i=1; i<=n; i++){
            for (int j=1; j <=i ; j++){
        cout << "*" ;
            }
            for (int s=1; s <= 2*(n-i);s++){
                cout << " ";
            }
            for (int j=1; j <=i ; j++){
            cout << "*"  ;
            }
        cout <<endl;
    }
    for (int i=n-1; i >=1; i-- ){
        for (int j=1; j<=i ; j++){
            cout << "^";
        }
        for (int s=1; s<=2*(n-i);s++){
        cout << " ";
        }
        for (int j=1; j <=i ;j++){
            cout << "*";

        }
        cout << endl;
    }
    cout << "-------------------------pattern 1----------------------------"<<endl;
    cout << endl;
    
	for (int i = 1; i <= n / 3; i++) {
		cout << " ";
	}
	for (int k = 1; k <= 2 * n - 2 * n / 3; k++) {
		cout << "*";
	}
	cout << endl;

	for (int i = 1; i <= n / 3; i++) {
		for (int j = 1; j <= n / 3; j++) {
			if (i + j == n / 3 + 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		for (int k = 1; k <= 2 * n - 2 * n / 3; k++) {
			cout << " ";
		}
		for (int l = 1; l <= n / 3; l++) {
			if (i == l) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}

		for (int k = 0; k <= 2 * n - 2 * i; k++) {
			cout << "*";
		}
		cout << endl;
	}
	
cout<<endl<<endl;


        cout << "-----------------------Pattern 3-----------------------"<<endl;
int height;
	int no_of_pyramid;
	cout << "Enter the height of paramid : ";
	cin >> height;
	cout << "Enter the number of paramids : ";
	cin >> no_of_pyramid;
		for (int i = 1; i <= height; i++) {
			for (int c = 1; c <= no_of_pyramid; c++) {
				for (int j = 1; j <= height - i; j++) {
					cout << " ";
				}

				for (int k = 1; k <= 2 * i - 1; k++) {
					cout << "*";
				}

				for (int j = 1; j <= height - i; j++) {
					cout << " ";
				}
			}
			cout << endl;
		}
        	cout << "--------------------- Pattern 04 --------------------------" << endl << endl;
	int h;
	cout << "Enter the height of paramid : ";
	cin >> h;
	int number;
	cout << "Enter the number of paramids : ";
	cin >> number;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int u = 1; u <= h - i; u++) {
				cout << " ";
			}

			if (i == h) 
            {
				for (int k = 1; k <= 2 * h - 1; k++) {
					cout << "*";
				}
			}
			else {
				for (int k = 1; k <= 2 * i - 1; k++) {

					if (k == 1 || k == 2 * i - 1) {
						cout << "*";

					}
					else {
						cout << " ";
					}

				}
			}


			for (int j = 1; j <= h - i; j++) {
				cout << " ";
			}
		}
		cout << endl;
	}   
}
        
}
