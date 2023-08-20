 #include <bits/stdc++.h>
#include <cstdlib> // for system("cls")
#include <conio.h> // for getch()

using namespace std;

class ATM {
private:
    long long int accountNumber;
    string name;
    int PIN;
    double balance;
    string mobileNumber;

public:
	void changePIN(int newPIN) {
    PIN = newPIN;
    cout << "PIN changed successfully!" << endl;
    getch();
    }
	void reportProblem() {
        string problemDescription;
        cout << "Please describe the problem: ";
        cin.ignore(); // Clear the newline character left in the buffer
        getline(cin, problemDescription);

        cout << "Thank you for reporting the problem. We will investigate it." << endl;
        getch();
    }
	void depositMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " successfully. Updated balance: " << balance << endl;
        } else {
            cout << "Invalid amount. Please enter a positive amount." << endl;
        }
        getch();
    }
    void setData(long long int accNumber, string nm, int pin, double bal, string mobNumber) {
        accountNumber = accNumber;
        name = nm;
        PIN = pin;
        balance = bal;
        mobileNumber = mobNumber;
    }

    long long int getAccountNumber() {
        return accountNumber;
    }

    string getName() {
        return name;
    }

    int getPIN() {
        return PIN;
    }

    double getBalance() {
        return balance;
    }

    string getMobileNumber() {
        return mobileNumber;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
        getch();
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        getch();
    }

    void updateMobileNumber(string newMobileNumber) {
        mobileNumber = newMobileNumber;
        cout << "Mobile Number updated successfully!" << endl;
        getch();
    }
};

int main() {
    
    ATM users[3]; // Array of ATM instances for three users
    
    // Set data for three users
    users[0].setData(2101017, "ZUNAID",1234, 500000.0, "01799086601");
    users[1].setData(2101014, "IFTY", 4567, 75000.0, "01887766554");
    users[2].setData(2101012, "SOHIDUL", 8910, 100000.0, "01666557788");

    int choice;
    int pin;
    long long int accountNumber;
    string newMobileNumber;

    while (true) {
        system("cls");
        cout << "***WELCOME TO SIZ BANK ATM***" <<endl;
        cout<<"--------------------------------"<<endl;
        cout << "Enter your Account Number: ";
        cin >> accountNumber;
        cout << "Enter your PIN: ";
        cin >> pin;

        ATM *currentUser = NULL;
        for (int i=0;i<3;++i){
            if (accountNumber == users[i].getAccountNumber() && pin == users[i].getPIN()) {
                currentUser = &users[i];
                break;
            }
        }

        if (currentUser != NULL) {
            while (true) {
                system("cls");
                cout << "Welcome, " << currentUser->getName() << "!" << endl;
                cout << "Choose an option:" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Deposit Money" << endl;
                cout << "4. Display Account Details" << endl;
                cout << "5. Update Mobile Number" << endl;
                cout << "6. Change PIN" << endl;
                cout << "7. Report a Problem" << endl;
                cout << "8. Exit" << endl;
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Your Balance: " << current User->getBalance() << endl;
                        getch();
                        break;

                    case 2:
                        double amount;
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        currentUser->withdraw(amount);
                        break;

                    case 3:
                    	double depositAmount;
                        cout << "Enter deposit amount: ";
                        cin >> depositAmount;
                        currentUser->depositMoney(depositAmount);
                        break;
                    

                    case 4:
                        currentUser->displayDetails();
                        break;
                    case 5: 
                        cout << "Enter new Mobile Number: ";
                        cin >> newMobileNumber;
                        currentUser->updateMobileNumber(newMobileNumber);
                        break;  
                    
                    case 6: 
                        int newPIN;
                        cout << "Enter new PIN: ";
                        cin >> newPIN;
                        currentUser->changePIN(newPIN);
                        break;
                    case 7:
                        currentUser->reportProblem();
                        break;
                    case 8:
                        cout << "As-salamu alaykum.<<endl Have a nice day!" << endl;
                        exit(0);

                    default:
                        cout << "Invalid choice. Please select a valid option." << endl;
                        getch();
                }
            }
        } else {
            cout << "Invalid Account Number or PIN. Please try again." << endl;
            getch();
        }
    }
 
    
	
	return 0;
}

