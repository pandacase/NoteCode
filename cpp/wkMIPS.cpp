#include <bits/stdc++.h>
#define TRANS(s, len) (bitset<len>(stoi(s, 0, 0)).to_string())
using namespace std;
string compiler(string s)
{
	static unordered_map<string, string> mp{
		{"add", "000000"},
		{"sub", "000001"},
		{"addiu", "000010"},
		{"and", "010000"},
		{"andi", "010001"},
		{"ori", "010010"},
		{"xori", "010011"},
		{"sll", "011000"},
		{"slti", "100110"},
		{"slt", "100111"},
		{"sw", "110000"},
		{"lw", "110001"},
		{"beq", "110100"},
		{"bne", "110101"},
		{"bltz", "110110"},
		{"j", "111000"},
		{"jr", "111001"},
		{"jal", "111010"},
		{"halt", "111111"}};
	vector<string> v;
	for (char &c : s)
		if (!isgraph(c) || c == '$' || c == '(' || c == ')')
			c = ',';
	for (istringstream sin(s); getline(sin, s, ',');)
		if (!s.empty())
			v.push_back(s);
	if (v.empty())
		return "";
	s = mp[v[0]];
	if (v.size() == 1)
		s += string(26, '0');
	else if (v.size() == 2)
	{
		if (v[0] == "jr")
			s += TRANS(v[1], 5) + string(21, '0');
		else
			s += bitset<26>(stoi(v[1], 0, 0) >> 2).to_string();
	}
	else if (v.size() == 3)
	{
		if (v[0] == "bltz")
			s += TRANS(v[1], 5) + string(5, '0') + TRANS(v[2], 16);
		else
			s += TRANS(v[1], 5) + TRANS(v[2], 21);
	}
	else
	{
		if (v[0] == "sw" || v[0] == "lw")
			swap(v[2], v[3]);
		if (v[0] == "sll")
		{
			s += string(5, '0');
			s += TRANS(v[2], 5) + TRANS(v[1], 5);
			s += TRANS(v[3], 5) + string(6, '0');
		}
		else if (v[0].find('i') != v[0].npos || v[0] == "sw" || v[0] == "lw" || v[0] == "beq" || v[0] == "bne")
		{
			s += TRANS(v[2], 5) + TRANS(v[1], 5);
			s += TRANS(v[3], 16);
		}
		else
		{
			s += TRANS(v[2], 5) + TRANS(v[3], 5);
			s += TRANS(v[1], 5) + string(11, '0');
		}
	}
	return s;
}
int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	ifstream fin(argv[1]);
	ofstream fout(argv[argc - 1]);
	for (string s; getline(fin, s); fout << '\n')
	{
		s = compiler(s);
		for (int i = 0; i < s.size(); ++i)
		{
			fout << s[i];
			if (i % 8 == 7)
				fout << ' ';
		}
	}
}
