//AC
#include <cstdio>
int main (){
	int T;
	scanf("%d", &T);
	int i;
	for (i = 0; i < T; i++) {
		int sum, caps, bodies;
		scanf("%d", &sum);
		caps = bodies = sum;
		while (caps / 4 || bodies /3) {
			int cap2drink = caps/4;
			int body2drink = bodies/3;
			int newDrinks = cap2drink + body2drink;
			caps %= 4;
			bodies %= 3;

			caps += newDrinks;
			bodies += newDrinks;
			sum += newDrinks;

		}
		printf ("%d\n", sum);
	}
	return 0;
}
