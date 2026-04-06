#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

class Service{
	private:
		string serviceName;
		double unitRate;
		int quantity;
	public:	
		Service (const string& n,double r,int q):serviceName(n),unitRate(r),quantity(q){}
	
		string getName() const{
		return serviceName;
		}
    	double getUnitRate() const{
		return unitRate;
		}
    	int getQuantity() const{
		return quantity;
		}
    	double getTotal() const{
		return unitRate * quantity;
		}
    
};
int main(){
	vector<Service>services;
	int numServices;
	
	cout<<"Enter the number of services:"<<endl;
	cin>>numServices;
	cin.ignore();
	
	for(int i=0;i<numServices;i++){
		string name;
		int quantity;
		double rate;
		
		cout<<"\nService "<<i+1<<" Name:";
		cin>>name;
		getline(cin,name);
		
		cout<<"Unit Rate($): ";
		cin>>rate;
		while(rate<=0){
			cout<<"Invalid unit rate: RE-ENTER"<<endl;
			cin>>rate;
		}
		
		cout<<"Quantity: ";
		cin>>quantity;
		while(quantity<0){
			cout<<"Invalid quantity:RE-ENTER"<<endl;
			cin>>quantity;
		}
		cin.ignore();
		
		services.emplace_back(name,rate,quantity);
	}
	
	double totalBill=0.0;
	cout<<"\n---Reciept---\n";
	for(auto& s:services){
		double serviceTotal=s.getTotal();
		totalBill +=serviceTotal;
		cout<<s.getName()<<"\nQuantity: "<<s.getQuantity()<<"\nUnit Price: $"<<fixed<<setprecision(2)<<s.getUnitRate()<<"\nService Total: $"<<serviceTotal<<endl;
	}
	cout<<"------------"<<endl;
	cout<<"Grand Total: $"<<fixed<<setprecision(2)<<totalBill<<endl;
	return 0;
}