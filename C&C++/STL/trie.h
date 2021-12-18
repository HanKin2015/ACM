typedef udev_info TRIE_DATA_STRUCT;

class Trie {
	struct TrieNode {
		bool is_end;				// 结束标志(树高固定9可以不使用)
		TRIE_DATA_STRUCT data;		// 节点数据
		map<char, TrieNode> next;	// pvid含有a-z,0-9两段字符不连续
		TrieNode()
		{
			is_end = false;
		}
	};


public:
	// 根节点
	TrieNode root;

	// 构造函数
	Trie()
	{

	}

	// 插入pvid
	void Insert(string pvid, TRIE_DATA_STRUCT data)
	{
		TrieNode* p = &root;
		for (int i = 0; i < pvid.size(); i++) {
			char c = pvid[i];
			if (p->next.find(c) == p->next.end()) {
				TrieNode tmp;
				p->next.insert(pair<char, TrieNode>(c, tmp));
			}
			p = &p->next[c];
		}
		p->data = data;
		p->is_end = true;
		return;
	}

	// 搜索pvid是否存在
	bool Search(string pvid)
	{
		TrieNode* p = &root;
		for (int i = 0; i < pvid.size(); i++) {
			char c = pvid[i];
			if (p->next.find(c) == p->next.end()) {
				return false;
			}
			p = &p->next[c];
		}
		return true;
	}

	// 输出所有树枝，即pvid
	void DFS(TrieNode r, string& pvid)
	{
		if (!r.next.empty()) {
			if (r.is_end) {
				cout << pvid << endl;
			}
			for (auto& it : r.next) {
				pvid.push_back(it.first);
				DFS(it.second, pvid);
				if (!pvid.empty()) {
					pvid.pop_back();
				}
			}
		} else {
			cout << pvid << endl;
		}
		return;
	}
};

/*
 * 从.\\others\\data.in文件输入测试数据
 * 
 * 结果: true false true false true
 */
void TestTrie()
{
    freopen(".\\others\\data.in", "r", stdin);
    int n, q;
    cin >> n;
    Trie *udev_tree = new Trie();
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        udev_info tmp;
        udev_tree->Insert(str, tmp);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> str;
        cout << boolalpha << udev_tree->Search(str) << endl;
    }
    string pvid = "";
    udev_tree->DFS(udev_tree->root, pvid);
    return;
}

```
5
babaab
babbbaaaa
abba
aaaaabaa
babaababb
5
babb
baabaaa
bab
bb
bbabbaab
```