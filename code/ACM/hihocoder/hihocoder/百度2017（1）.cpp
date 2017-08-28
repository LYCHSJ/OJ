#include<iostream>
#include<string>
using namespace std;

const int MAXN = 105;

struct Trie {
	char value;
	int layercount = 0;
	Trie *next[26];
	Trie() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};
class solution {
public:
	void insertWord(char str[]) {
		int len = strlen(str);
		Trie * head=&TrieTree;
		int index=0;//Æ«ÒÆÁ¿
		for (int i = 0; i<len; i++) {
			index = str[i] - 'a';
			if (head->next[index] == NULL) {
				Trie *node = new Trie;
				node->value = str[i];
				head->next[index] = node;
			}
			head = head->next[index];
			head->layercount++;
		}
	}
	void queryWord(char str[]) {
		int len = strlen(str);
		Trie * head = &TrieTree;
		int index = 0;
		int ans = 0;
		for (int i = 0; i < len; i++) {
			index = str[i] - 'a';
			if (head->next[index] == NULL) {
				ans = 0;
				break;
			}
			head = head->next[index];
			ans = head->layercount;
		}
		result = ans;
	}
	int getResult() const {
		return result;
	}
private:
	Trie TrieTree;
	int result=0;
};
int main()
{
	char str[MAXN];
	int n, m;
	solution s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s.insertWord(str);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		s.queryWord(str);
		cout << s.getResult() << endl;
	}
	return 0;
}