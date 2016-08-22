#include <cstdio>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846264338
void exchange(double &a, double &b){double t = a; a = b; b = t;}
double max(double &a, double &b){return a>b?a:b;}
double ABS(double &a){return a>0?a:-a;}
int main (){
	double d1, d2, th;
	scanf("%lf %lf %lf", &d1, &d2, &th);
	if (max(d1, d2)!=d1)exchange(d1,d2);
	double r1 = d1/2., r2 = d2/2.;
	double ab, ao, ac;
//	while(th<0) th+=360;
	if(ABS(th) == 180 || abs(th)==360||abs(th)==540||abs(th)==720||abs(th)==900){
//	if(th/180.==0){
		ac = r1+r2;
		
		goto show;
	}
	if(d2==0){
		ac = r1;
		
		goto show;
	}


	//ab = r1*sin(th/2.*PI/180.);
	//ao = sqrt(r1*r1-ab*ab);
	//ac = ao * sin((th/2.+(45-th/4.))*PI/180) / sin((45-th/4.)*PI/180);
	ac = sqrt(r1*r1+r2*r2-2*r1*r2*cos(th*PI/180))+r1+r2;
	ac /= 2;
show:
	double res = ac*ac*PI;
	printf("%.10lf", res);
	return 0;
}

