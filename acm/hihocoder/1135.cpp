//AC
//http://hihocoder.com/problemset/problem/1135
#include <cstdio>
#include <string>
#include <iostream>
int absS(int a, int b) {return a>b?a-b:b-a;}//绝对值减法
void cmp(int &a, int &b, int &c){//比较三个数 返回a<b<c
	int min=a,mid=a+b+c,max=a;
	if (b<min) min = b;
	if (c<min) min = c;
	if (b>max) max = b;
	if (c>max) max = c;
	mid -= (max+min);
	a = min;
	b = mid;
	c = max;
}
using namespace std;
int main (){
	int x, y, z;
	int cr,cy,cb;
	cr = cy = cb = 0;
	scanf("%d %d %d", &x, &y, &z);
	cmp(x,y,z);//排序，方便比较
	string str;
	cin >> str;
	int res = 0, count=0;
	for (int i = 0; i < str.length(); i++) {
		count++;
		switch(str[i]) {
			case 'R':
				cr++;
				break;
			case 'B':
				cb++;
				break;
			case 'Y':
				cy++;
				break;
		}
		int diffRY = absS(cr, cy);
		int diffYB = absS(cy, cb);
		int diffBR = absS(cb, cr);
		cmp(diffRY, diffYB, diffBR);//排序，方便比较
		if (count>res)res=count;
		if (diffRY == x && diffYB == y && diffBR == z) {
		//	printf("vanish at %d\n", i);
			cr=cb=cy=count=0;
		}
	}
	printf("%d\n", res);
	return 0;
}
