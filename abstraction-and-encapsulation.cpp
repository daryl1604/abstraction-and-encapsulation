//Daryl De Castro C2A embarcaderro c++
#include<iostream>
#include<iomanip>

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
			}else if(amount>0&&getBalance()<amount){
  				  cout<<"Cannot withdraw. Insufficient balance.\n\n";
			}else if(amount>0){
				cout<<"\nMinimum balance should remain Php 1000.\n\n";
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
			else if(amount>0&&getBalance()<amount){
  				cout<<"Cannot withdraw. Insufficient balance.\n\n";	
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
	
	cout<<"Simple Bank Account System\n\n";
	cout<<"1 - Savings Account\n";
	cout<<"2 - Current Account\n";
	cout<<"3 - Exit\n";
	cout<<"\nSelect your choice: ";
	
		
	while(condition){
		cin>>choice;
		system("cls");
		
		switch(choice){
			case'1':
				cout<<"---Savings Account---"<<endl;
				subMenu(s1);
				break;
				
			case'2':
				cout<<"---Current Account---"<<endl;
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
	
	cout<<"\nSub Menu\n";

	while(condition){
		cout<<"1 - Deposit\n";
		cout<<"2 - Withdraw\n";
		cout<<"3 - Check Balance\n";
		cout<<"4 - Back\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		system("cls");
		switch(choice){
			case'1':
				cout<<"Enter amount you want to deposit: ";
				cin>>amount;
				while (cin.fail()||amount<0){
					cout<<"\nInvalid input. Please enter a non-negative number: ";
					cin.clear();
					cin.ignore(10000,'\n');
					cin>>amount;
				}
				cout<<"\nYou have successfully deposited Php "<<fixed<<setprecision(2)<<amount<<endl<<endl;	
				account.deposit(amount);
				break;
				
			case'2':
				cout<<"Enter amount you want to withdraw: ";
				cin>>amount;
				cout<<endl;
				while (cin.fail()||amount<0){
					cin.clear();
					cin.ignore(10000,'\n');
					cout<<"\nInvalid input. Please enter a non-negative number: ";
					cin>>amount;
				}
				account.withdraw(amount);
				break;
				
			case'3':
				cout<<"Your Current Balance is Php "<<fixed<<setprecision(2)<<account.getBalance()<<endl<<endl;
				break;
				
			case'4':
				condition=false;
				
				cout<<"Simple Bank Account System\n\n";
				cout<<"1 - Savings Account\n";
				cout<<"2 - Current Account\n";
				cout<<"3 - Exit\n";
				cout<<"\nSelect your choice: ";
				break;
				
			default:
				cout<<"Invalid choice. Please try again.\n";
		}
	}
}

