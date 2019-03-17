#include<iostream>
#include<cmath>
using namespace std;


class homogeneous_differential{
	protected:
		double a1,b1; //for legendre
		double x,x1,x2; //for entering values of coefficients y'' , y' and y
		double y,y1; // storing values of roots
		double D; //discriminant
	public:
		double calcD(); //calculating discriminant
		void calcroot(); //calculating roots
		void print(); //print func()
		void initialize(); //function for taking input values
		void forim(double); //for special case i.e of imaginary roots
};
void homogeneous_differential :: initialize(){
	double a,b,c;
	cout<<"Enter the coefficients of y'' , y' and y"<<endl;
	cin>>a>>b>>c;
	x = a;
	x1 = b;
	x2 = c;
}
double homogeneous_differential :: calcD(){
	D = (pow(x1,2) - (4*x*x2)); // b^2 - 4ac
	return D;
}
void homogeneous_differential :: calcroot(){
	calcD();
	double m;
	m = calcD();
	if(m<0){
		 forim(m);   //calling func() forim
	}
	if (m> 0)
    {
        y = (-x1+sqrt(m))/(2*x);     //calculating roots
        y1 = (-x1-sqrt(m))/(2*x);
        cout<<endl<<"y="<<"Ae^("<<y<<"x)+Be^("<<y1<<"x)"<<endl;
    }
    else if (m == 0)
    {
        y = y1 = -x1/(2*x);
        cout<<endl<<"y="<<"(A+Bx)e^("<<y<<"x)"<<endl;
		}
    }
void homogeneous_differential :: forim(double o){
	double real,imag;
	real = -x1/(2*x);
	imag = sqrt(-o)/(2*x);
	cout<<"y=e^("<<real<<"x)*(Acos("<<imag<<"x)+Bsin("<<imag<<"x))"<<endl;  //printing answer
}
class legendre : public homogeneous_differential
{ 
	protected:
		double n1,n2,n3;
	public:
		void initialize()
		{ 
			cout<<"Enter a and b ((a+bx)^2)y''"<<endl;
			cin>>a1>>b1;
			cout<<endl<<"Enter coefficients other than them(enter 1 if none)"<<endl;
			homogeneous_differential :: initialize();
		}
		void new_eqn(){
			n1 = pow(b1,2)*x;
			n2 = b1*x1 - pow(b1,2)*x1;
		}
		double caclcD(){
			D = (pow(n2,2) - (4*n1*x2)); // b^2 - 4ac
			return D;
		}
		
};
int main()
{
int n,i,c;
cout<<"\t\t\t\t\t\t\t\t\t\t\t CONDITION!! all equations be in Homogenous form"<<endl<<endl;
cout<<"Enter Number of Homogeneous differential Equations"<<endl;						//enter num differential equation
cin>>n;
homogeneous_differential equ;
legendre equn;
for(int i = 1;i<=n;i++){
cout<<"Enter type of Homogeneous differential Equation"<<endl<<"1. General"<<endl<<"2. Legendre"<<endl;
cin>>c;
switch(c){
	case 1:
			cout<<"Enter"<<" equation "<<i<<"'s"<<"Differential's coffecients"<<endl;
			cout<<"Coefficient of y'' cannot be 0"<<endl;	
			equ.initialize();      //calling to initilization function
			equ.calcroot();			//calling to calcutate roots
			cout<<"___________________________________________________________________________________________________________"<<endl;
		
		break;
	case 2:	//for legendre's differential equation
	
		break;
}
}
return 0;
}
