#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;
bool hasOverlap(double x[], double y[], double r[], int n) {
	double lr = 1000000000;
	double rr = -1000000000;
	for (int i = 0; i < n; i++) {
		if(x[i] < lr) lr = x[i];
		if(x[i] > rr) rr = x[i];
	}

	bool lFlag = false;
	bool rFlag = false;
	double upper = 1000000000;
	double lower = -1000000000;
	int upIndex = 0;
	int lowIndex = 0;
	do {
		double cur = (lr + rr)/2.0;
		lFlag = false;
		rFlag = false;
		upper = 1000000000;
		lower = -1000000000;
		for(int i=0; i<n; i++) {
			if(x[i]+r[i]<=cur) { // shift left
				lFlag = true;
			}
			else if(x[i]-r[i]>=cur) { // shift right
				rFlag = true;
			}
			else { // has two point
				double tmp = sqrt((double)(r[i]*r[i]-(cur-x[i])*(cur-x[i])));
				if(y[i]+tmp<upper) {
					upper = y[i]+tmp;
					upIndex = i;
				}
				if(y[i]-tmp>lower) {
					lower = y[i]-tmp;
					lowIndex = i;
				}
			}
		}
		if(lFlag && rFlag) {
			return false;
		}
		else if(lFlag) rr = cur; // shift left
		else if(rFlag) lr = cur; // shift right
		else {	// all has two point
			if(upper > lower) {	// key condition
				return true;
			}
			// calcuate the length between two circles
			double leng = (x[upIndex]-x[lowIndex])*(x[upIndex]-x[lowIndex]) + (y[upIndex]-y[lowIndex])*(y[upIndex]-y[lowIndex]);
			if(leng >= (r[upIndex]+r[lowIndex])*(r[upIndex]+r[lowIndex])) { // has no intersection
				return false;
			}
			// decide the mid point of the intersecting segment is on which side, with specific formula
			double d = (r[upIndex]*r[upIndex] - r[lowIndex]*r[lowIndex] + leng) / (2.0*sqrt(leng));
			if((double)x[upIndex]+((double)(x[lowIndex]-x[upIndex]))*d/sqrt(leng) > cur) lr = cur; // shift right
			else rr = cur; // shift left
		}
	} while(rr-lr>0.1);
	return false;
}
int main(){
	int n;
	scanf("%d", &n);
	double xs[n];
	double ys[n];
	double rs[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf",&xs[i], &ys[i], &rs[i]);
	}
	printf("%s\n", hasOverlap(xs, ys, rs, n)?"YES":"NO");
	return 0;
}
