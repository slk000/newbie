#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
    int distance, fuel;
    // Node( int a= 0, int b= 0 ):
    //     x(a), y(b) {}
} FuelStation;

bool operator<( FuelStation a, FuelStation b ){
    return a.distance < b.distance; 
}


int main(){
	priority_queue<int> q;
	int stationsNum;
	scanf("%d", &stationsNum);
	priority_queue<FuelStation> fuelStations;
	int tmpDistance, tmpFuel;
	
	for (int i = 0; i < stationsNum; i++){
		scanf("%d %d", &tmpDistance, &tmpFuel);
		fuelStations.push((FuelStation){tmpDistance, tmpFuel});
	}

	int distance, fuel;
	scanf("%d %d", &distance, &fuel);

	for (int i = 0; i < distance; ++i, fuel--)
	{
		if (i == (distance - fuelStations.top().distance))
		{
			q.push(fuelStations.top().fuel);
			fuelStations.pop();
		}
		if (fuel != 0){
			continue;
		}
		if (q.empty())
		{
			printf("-1\n");
			return 0;
		}
		else {
			//printf("add %d\n", q.top());
			fuel += q.top();
			q.pop();
		}
	}

	printf("%d\n", stationsNum - q.size());
	return 0;
}
