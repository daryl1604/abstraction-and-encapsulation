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
				cout<<"Minimum balance should remain Php 1000.\n\n";
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
	cout<<"\nEnter your choice: ";
	
		
	while(condition){
		cin>>choice;
		system("cls");
		
		switch(choice){
			case'1':
				cout<<"---Savings Account---"<<endl<<endl;
				subMenu(s1);
				break;
				
			case'2':
				cout<<"---Current Account---"<<endl<<endl;
				subMenu(c1);
				break;
				
			case'3':
				cout<<"Exiting...\n";
				condition=false;
				break;
				
			default:
				cout<<"Invalid choice. Please try again.\n\n";
		}
	}
}

void subMenu(Bank& account){
	char choice;
	double amount;
	bool condition=true;

	while(condition){
		cout<<"Sub Menu\n";
		cout<<"1 - Deposit\n";
		cout<<"2 - Withdraw\n";
		cout<<"3 - Check Balance\n";
		cout<<"4 - Back\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		system("cls");
		switch(choice){
			case'1':
				cout<<"D E P O S I T"<<endl;
				cout<<"\nEnter amount you want to deposit: ";
				cin>>amount;
				while (cin.fail()||amount<0){
					cout<<"\nInvalid input. Please enter a non-negative number: ";
					cin.clear();
					cin.ignore(10000,'\n');
					cin>>amount;
				}
				while(amount==0){
					cout<<"\nInvalid Input. You cannot deposit Php. 0.00"<<endl;
					cout<<"\nEnter amount you want to deposit: ";
					cin>>amount;
				}
				cout<<"\nYou have successfully deposited Php "<<fixed<<setprecision(2)<<amount<<endl;	
				cout<<"------------------------------------------------------"<<endl<<endl;
				account.deposit(amount);
				break;
				
			case'2':
				cout<<"W I T H D R A W"<<endl;
				cout<<"\nEnter amount you want to withdraw: ";
				cin>>amount;
				cout<<endl;
				while (cin.fail()||amount<0){
					cin.clear();
					cin.ignore(10000,'\n');
					cout<<"\nInvalid input. Please enter a non-negative number: ";
					cin>>amount;	
				}
				while(amount==0){
				cout<<"\nInvalid Input. You cannot withdraw Php. 0.00"<<endl;
				cout<<"\nEnter amount you want to withdraw: ";
				cin>>amount;
				}
				cout<<"--------------------------------------------------------"<<endl<<endl;
				account.withdraw(amount);
				break;
				
			case'3':
				cout<<"C H E C K  B A L A N C E"<<endl;
				cout<<"\nYour Current Balance is Php "<<fixed<<setprecision(2)<<account.getBalance()<<endl;
				cout<<"---------------------------------------------------------"<<endl<<endl;
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