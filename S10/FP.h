//Primer programa en c++
//Steven Rubio
//12/11/2020

#include<iostream>
using namespace :: std;			//Omitt this call in the code
const double m_to_k = 1.609;

//Keyword = Optimaze a function
inline double convert(int mi){return (mi*m_to_k);}

int main(void){
	
	int miles = 1;
	
	while(miles !=0){
		cout << "Input a distance in miles or 0 to terminate: ";
		cin >> miles;
		cout << "\nDistance is" << convert(miles) << " km." << endl;
	}
	cout <<endl;
	
}