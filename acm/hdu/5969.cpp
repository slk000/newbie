//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=5969
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <functional>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
typedef long long LL;
inline LL cntBit(LL a) { //计算a的二进制长度
	LL cnt = 1;
	while (a >>= 1) { cnt++; }
	return cnt;
}

int main() {
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	LL L, R;
	
	while (T--) {
		
		cin >> L >> R;
		
		LL LCnt = cntBit(L);
		LL RCnt = cntBit(R);
		if (LCnt < RCnt) { //如果两数长度不同，只需将较长的R 全部置1（除去R最高位的RCnt-1个1 大于 L）
			LL t = R;
			for (LL i = 0; i < RCnt-1LL; i++)t |= (1LL << i);
			cout << t << endl;
		}
		else if(LCnt == RCnt) {

			LL i = -1;
			for (i = LCnt-1; i >= 0LL; i--) { //若长度相同，从高到低找到第一个不同位i，
				LL mask = 1LL << (LL)i;
				if ((L&mask) == (R&mask)) continue;
				else break;
			}
			//因为要根据L来推X，所以以下直接用L代表X
			if (i > 0) //将L的i置零（保证L<R）然后将i之后的位都置1（保证L>左边界），这样的值满足题意
			{
				LL tail = (1LL << i) - 1LL; //（都是1的部分）
				LL head = L & ((-1LL) & (1LL << i)); //（构造一个111110000之类的值来取L的高位）
				L = head | tail;
				
			}
			//cout << L << "|" << R << "=" << (L | R) << endl;
			cout << (L|R)<< endl; //Y=R
		}
	}
	return 0;
}
/*生成测试数据
```ruby
(0..100000).each{a=Integer(rand(10**16..10**18)); print a;print ' '; p Integer(rand(a..10**18));}
```
*/
