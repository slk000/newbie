#include <cstdio>
#include <set> 
using namespace std;
typedef struct OB {
    long long x, y;
} OB;
bool operator<(const OB a, const OB b){
    if (a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
#define lld long long
#define P 110119
int Pow(lld a,lld n,lld p)
{
	lld x = a;
	lld res = 1;
	while(n)
	{
		if(n & 1)
		{
			res = ((lld)res * (lld)x) % p;
		}
		n >>= 1;
		x = ((lld)x*(lld)x) % p;
	}
	return res;
}

int Cm(lld n,lld m,lld p)
{
	lld a = 1,b = 1;
	if(m > n) return 0;
	//实现(a!/(a-b)!) * (b!)^(p-2)) mod p,由于n比较大，所以，此处不知道有什么好的优化
	while(m)
	{
		a = (a * n) % p;
		b = (b * m) % p;
		m--;
		n--;
	}
	return ((lld)a * (lld)Pow(b,p-2,p))%p;
}
int Lucas(lld n,lld m,lld p)
{
	if(m==0)
		return 1;
	return((lld)Cm(n%p,m%p,p)*(lld)Lucas(n/p,m/p,p))%p;
}
long long dx, dy;
int obstacles;
set<OB> obs;
bool trans(long long &x, long long &y){
    if ((x+y-2)%3 == 0 && (2*y-x-1)%3 == 0){
        x = (x+y-2)/3;
        y = y-x-1;
        return (x>=0&&y>=0);
    }
    return false;
}
int Case;
int main (){
    
    while(EOF != scanf("%lld %lld %d", &dx, &dy, &obstacles)){
        long long ans = 0;
        printf("Case #%d: ", ++Case);
        if(!trans(dx,dy)){
            printf("0\n");
            continue;
        }
        printf("%lld %lld\n", dx,dy);
        
        for (int i = 0; i < obstacles; i++) {
            OB t;
            scanf("%lld %lld", &t.x, &t.y);
            obs.insert(t);
        }
        while(!obs.empty()){
            OB t = *obs.begin();
            obs.erase(obs.begin());
            if(trans(t.x,t.y))
                ans += (Lucas(t.x,t.y, P)*Lucas(dx-t.x,dy-t.y, P))%P;
            printf("ans: %lld\n", ans);
        }
        ans = Lucas(dx,dy, P)-ans;
        printf("%lld\n", ans%P);
    } 
    return 0;
}
