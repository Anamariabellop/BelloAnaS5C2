#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

double y_prime(double y0);
double y_p(double x0, double y0);
void euler(double a, double b,double delta, int npuntos, string filename);
void rungek4(double a, double b, double delta, int npuntos, string filename);

int main(){

	double x_0;
	x_0= 0.0;
	double x_f;
	x_f= 2.0;
	double dt;
	int N;
	euler(x_0,x_f, 0.1,100, "datos.dat");
	rungek4(x_0,x_f, 0.1,100,"datosr4.dat");
	return 0;
}

double y_prime(double y0)
{
	return -y0;	
}

double y_p(double x0, double y0)
{
	return -y0;
}

void euler(double a, double b,double delta, int npuntos, string filename){

	ofstream outfile;
	outfile.open(filename);
	double y;
	double y_0=1.0;
	//y=y_0;
	double x_0;
	x_0=0.0;
	double dx= (b-a)/(npuntos-1);

	double* arreglox= new double [npuntos];
	double* arregloy= new double [npuntos];
	arreglox[0]= a;
	arregloy[0]= y_0;

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

void rungek4(double a, double b, double delta, int npuntos, string filename){
	ofstream outfile;
	outfile.open(filename);

	double x_0=0.0;
	double x_f=2.0;
	double y_0=1.0;
	double arrx[npuntos];
	double arry[npuntos];
	arrx[0]=x_0;
	arry[0]=y_0;
	double promediok;
	double k1,k2,k3,k4;
	double dx= (b-a)/(npuntos-1);

	for(int i=1; i<npuntos; i++){

		k1=delta*y_p(arrx[i-1],arry[i-1]);
		k2=delta*y_p(arrx[i-1]+(0.5*delta),arry[i-1]+(0.5*k1));
		k3=delta*y_p(arrx[i-1]+(0.5*delta),arry[i-1]+(0.5*k1));
		k4=delta*y_p(arrx[i-1]+delta, arry[i-1]+k3);

		promediok=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		arrx[i]=arrx[i-1]+dx;// con dx que crea mi linspace determinado.
		arry[i]=arry[i-1]+promediok;

		outfile << arrx[i] << " " << arry[i] << endl;
	}
    outfile.close();
}
