//AC
//http://hihocoder.com/problemset/problem/1014
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class Trie_node{
public:
	Trie_node *childs[26];
	bool isWord;
	int f;
	map<char, int> words;//数据不止有英文字母 所以需要给字符编号
	Trie_node(){
		for (int i = 0; i < 26; i++) childs[i] = NULL;
		f = 0;
		isWord = 0;
	}
	~Trie_node(){
	}
	void insert(char *str) {
		
		bool flag = 0;
		Trie_node *cur = this;
		vector<int*> adds;
		for (int i = 0; i < strlen(str); i++) {
			int index;
			if (words.find(str[i]) != words.end()) {
				
			}
			else {
				int tmp = words.size();
				words[str[i]] = tmp;
			}
			index = words[str[i]];
			//while(1){
			if (cur->childs[index]) {

			}
			else {
				cur->childs[index] = new Trie_node;
				//flag = 1;//如果new了说明这是一个新单词
			}
			cur->childs[index]->f++; //题目要求相同单词视为不同单词
			//adds.push_back(&(cur->childs[index]->f)); //否则用adds存下该单词所有f，
			cur = cur->childs[index];
			//}

		}
// 		if (flag)//再判断这回是否是一个新单词，若是，给得道它需经过的所有节点的f加1
// 		{
// 			for (int i = 0; i < adds.size(); i++)
// 			{
// 				*(adds[i]) += 1;
// 			}
// 		}
		cur->isWord = 1;
	}
	int getF(char *str) {
		Trie_node *cur = this;
		int res = 0;
		for (int i = 0; i < strlen(str); i++) {
			if (words.find(str[i]) == words.end()) return 0;
			int index = words[str[i]];
			if (cur->childs[index]) {
				res = cur->f;
				cur = cur->childs[index];
			}
			else {
				//if (i + 1 == strlen(str)) return res;
				return 0;
			}

		}
		res = cur->f;
		return res;

	}
};

int main(){
	Trie_node t;
	int dic_size;
	scanf("%d", &dic_size);
	char str[12];
	for (int i = 0; i < dic_size; i++) {
		scanf("%s", str);
		t.insert(str);
	}
	int query_sum;
	scanf("%d", &query_sum);
	char target[20];
	for (int i = 0; i < query_sum; i++)
	{
		scanf("%s", target);
		printf("%d\n", t.getF(target));
	}
	
	system("pause");
	return 0;
}
