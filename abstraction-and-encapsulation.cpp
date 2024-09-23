//Daryl De Castro C2A embarcaderro c++
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Bank{
	private:
		double balance;
	protected:
		Bank(){
			balance=0;
		}
	public:
		void setBalance(double b){
			balance=b;
		}
		double getBalance()const{
			return balance;
		}
		virtual void deposit(double amount)=0;
		virtual void withdraw(double amount)=0;
};

class savingsAccount:public Bank{
	public:
		savingsAccount(){
			setBalance(1000);
		}
		void deposit(double amount)override{
			if(amount>0){
				setBalance(getBalance()+amount);
			}
		}
		void withdraw(double amount)override{
			if(amount>0&&getBalance()-amount>=1000){
				setBalance(getBalance()-amount);
			}else if(amount>0){
				cout<<"Cannot withdraw. Minimum balance must be 1000.\n";
			}
		}
};

class currentAccount:public Bank{
	public:
		currentAccount(){
			setBalance(0);
		}
		
		void deposit(double amount)override{
			if(amount>0){
				setBalance(getBalance()+amount);
			}
		}
		
		void withdraw(double amount)override{
			if(amount>0&&amount<=getBalance()){
				setBalance(getBalance()-amount);
			}
		}
};

void menu();
void subMenu(Bank& account);

int main(){
	menu();
	return 0;
}

void menu(){
	savingsAccount s1;
	currentAccount c1;
	char choice;
	bool condition=true;
	
	cout<<"\nSimple Bank Account System\n";
	cout<<"1 - Savings Account\n";
	cout<<"2 - Current Account\n";
	cout<<"3 - Exit\n";
	cout<<"Select your choice: ";
	while(condition){
		cin>>choice;
		switch(choice){
			case'1':
				subMenu(s1);
				break;
				
			case'2':
				subMenu(c1);
				break;
				
			case'3':
				cout<<"Exiting...\n";
				condition=false;
				break;
				
			default:
				cout<<"Invalid choice. Please try again.\n";
		}
	}
}

void subMenu(Bank& account){
	char choice;
	double amount;
	bool condition=true;
	
	while(condition){
		cout<<"\nSub Menu\n";
		cout<<"1 - Deposit\n";
		cout<<"2 - Withdraw\n";
		cout<<"3 - Check Balance\n";
		cout<<"4 - Back\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case'1':
				cout<<"Enter amount to deposit: ";
				cin>>amount;
				while(amount<0){
					cout<<"Invalid amount. Enter again: ";
					cin>>amount;
				}
				account.deposit(amount);
				break;
				
			case'2':
				cout<<"Enter amount to withdraw: ";
				cin>>amount;
				while(amount<0){
					cout<<"Invalid amount. Enter again: ";
					cin>>amount;
				}
				account.withdraw(amount);
				break;
				
			case'3':
				cout<<"Current Balance: "<<fixed<<setprecision(2)<<account.getBalance()<<endl;
				break;
			case'4':	
				condition=false;
				break;
				
			default:
				cout<<"Invalid choice. Please try again.\n";
		}
	}
}