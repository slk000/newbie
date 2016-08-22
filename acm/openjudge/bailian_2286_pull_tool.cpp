//http://bailian.openjudge.cn/practice/2286/
//http://bailian.openjudge.cn/2016acmmid/e/
#include <cstdio>
#define INF 0x3f3f3f3f
const int indexs[8][7] = {
	{ 0,2,6,11,15,20,22 },    //AF
	{ 1,3,8,12,17,21,23 },    //BE
	{ 10,9,8,7,6,5,4 },       //CH
	{ 19,18,17,16,15,14,13 }, //DG

	{ 23,21,17,12,8,3,1 },
	{ 22,20,15,11,6,2,0 },
	{ 13,14,15,16,17,18,19 },
	{ 4,5,6,7,8,9,10 },


};
const int reverseOp[] = { 5,4,7,6,1,0,3,2,-1 };
const int center[] = { 6,7,8,11,12,15,16,17 };
int min(int a, int b) { return a>b ? b : a; }
int max(int a, int b) { return a<b ? b : a; }
char map[24];
void print() {

	int i = 0;
	for (; i<4; i += 2)
		printf("		%d		%d\n", map[i], map[i + 1]);
	for (; i < 11; i++)
		printf("%d	", map[i]);
	printf("\n		%d		%d\n\n", map[i], map[i + 1]);
	i += 2;
	for (; i < 20; i++)
		printf("%d	", map[i]);
	printf("\n");
	for (; i<24; i += 2)
		printf("		%d		%d\n", map[i], map[i + 1]);
	printf("\n");
}
void pull(int op) {
	//printf("op %c:\n", op + 'A');
	//print();
	int tmp = map[indexs[op][0]];
	for (int i = 0; i < 7 - 1; i++) {
		map[indexs[op][i]] = map[indexs[op][i + 1]];
	}
	map[indexs[op][6]] = tmp;
}

int h() {
	int cnt[3] = { 0,0,0 }; // count for 1, 2, 3
	int maxStep = -1;
	for (int i = 0; i < 8; i++) {
		cnt[map[center[i]] - 1]++;
		maxStep = max(maxStep, cnt[map[center[i]] - 1]);
	}
	return 8 - maxStep;
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &map[i]);
		if (map[i] == 0) return 0;
	}
	char op;
	print();
	while(1){
        scanf("%c", &op);
        if(op=='\n')continue;
        pull(op-'A');
        print();
	}
	return 0;
}

