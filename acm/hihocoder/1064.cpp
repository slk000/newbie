#include <cstdio>
struct Circle{
    double x, y;
    int value;
};
struct Event{
    double deg;
    int value;
};
int main (){
    int sum;
    scanf("%d", &sum);
    Circle circles[sum];
    for(int i = 0; i < sum; i++){
        scanf("%lf %lf %d", circles[i].x,circles[i].y,circles[i].value);
    }
    return 0;
}
