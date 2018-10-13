#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
using namespace std;

/**
*根据分隔符c进行字符串分割
*/
void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2) {
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length()) v.push_back(s.substr(pos1));
	return;
}

/**
*计算dblp属性频繁概率
*/
void Compute_Probability(char* fin, char* fout)
{
	FILE *attribute_fin = fopen(fin, "r");
	map<string, int> attributesCount;   //有多少的顶点拥有这个属性，即某个属性的数量
	unordered_set<string> attributes;			//存储属性
	set<int> nodes;
	while (!feof(attribute_fin)) {
		int node;
		char attr[200005];   //这里容易出现内存分配太小，出现段错误
		fscanf(attribute_fin, "%d\t%s\n", &node, &attr);

		vector<string> vec;
		SplitString(attr, vec, ",");
		for (int i = 0; i < vec.size(); i++) {
			attributesCount[vec[i]]++;
			attributes.insert(vec[i]);
		}
		nodes.insert(node);
	}
	fclose(attribute_fin);

	unordered_set<string> pro3, pro6, pro9, pro12, pro15;
	for (auto it = attributes.begin(); it != attributes.end(); it++) {
		double probability = attributesCount[*it] * 1.0 / nodes.size();
		if (probability >= 0.0025 && probability <= 0.0035) pro3.insert(*it);
		if (probability >= 0.0055 && probability <= 0.0065) pro6.insert(*it);
		if (probability >= 0.0085 && probability <= 0.0095) pro9.insert(*it);
		if (probability >= 0.0115 && probability <= 0.0125) pro12.insert(*it);
		if (probability >= 0.0145 && probability <= 0.0155) pro15.insert(*it);
	}

    FILE *attribute_out = fopen(fout, "w");
    fprintf(attribute_out, "*******************\n");
	fprintf(attribute_out, "概率为0.003\n");
	fprintf(attribute_out, "*******************\n");
	for (string elem : pro3) fprintf(attribute_out, "%s, ", elem.data());

	fprintf(attribute_out, "\n*******************\n");
	fprintf(attribute_out, "概率为0.006\n");
	fprintf(attribute_out, "*******************\n");
	for (string elem : pro6) fprintf(attribute_out, "%s, ", elem.data());

	fprintf(attribute_out, "\n*******************\n");
	fprintf(attribute_out, "概率为0.009\n");
	fprintf(attribute_out, "*******************\n");
    for (string elem : pro9) fprintf(attribute_out, "%s, ", elem.data());

	fprintf(attribute_out, "\n*******************\n");
	fprintf(attribute_out, "概率为0.012\n");
	fprintf(attribute_out, "*******************\n");
    for (string elem : pro12) fprintf(attribute_out, "%s, ", elem.data());

	fprintf(attribute_out, "\n*******************\n");
	fprintf(attribute_out, "概率为0.015\n");
	fprintf(attribute_out, "*******************\n");
    for (string elem : pro15) fprintf(attribute_out, "%s, ", elem.data());
    fclose(attribute_out);
	return;
}


int main()
{
    Compute_Probability("./dblp_attributes.txt", "./compute_probability.txt");
    return 0;
}
