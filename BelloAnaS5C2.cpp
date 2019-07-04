#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

double derivada(double funcion);
void euler(double a, double b,double delta, int npuntos, string filename);

int main(){

	double x_0;
	x_0= 0.0;
	double x_f;
	x_f= 2.0;
	double dt;
	int N;
	euler(x_0,x_f, 0.1,100, "datos.txt");
	return 0;
	
}

double y_prime(double y0)
{
	return -y0;	
}

void euler(double a, double b,double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);
	double y;
	double y_0=1;
	//y=y_0;
	double x_0;
	x_0=0;
	double dx= (b-a)/(npuntos-1);

	double* arreglox= new double [npuntos];
	double* arregloy= new double [npuntos];
	arreglox[0]= a;
	arregloy[0]= b;

	for(int i=1; i<npuntos+1 ; i++)// para crear linspace con npuntos determinado
    {  
      arreglox[i]= arreglox[i-1]+dx;
    }

	for(int i=0; i< npuntos; i++)
	{
		arregloy[i]= arregloy[i-1] + (delta*y_prime(arregloy[i-1]));
		y=arregloy[i];
		//outfile << arreglox[i] << endl;
		outfile << arreglox[i] << " " << y << endl;
	}

	outfile.close();
}
