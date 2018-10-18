#include "stdafx.h"
#include "POJ2318_Toys.h"
#include <unordered_map>


POJ2318_Toys::POJ2318_Toys()
{

}


POJ2318_Toys::~POJ2318_Toys()
{
}

bool POJ2318_Toys::in()
{
	cin >> n;
	if (n == 0)return false;
	pointer L, R;
	cin >> m >> L.x >> L.y >> R.x >> R.y;
	LU.push_back(L);
	RD.push_back(R);
	vector<pointer> toys;
	vector<line> pors;
//	porlines.clear();
	//toypointers.clear();
	for (int i = 0; i < n; i++) {
		pointer start, end;
		cin >> start.x >> end.x;
		start.y = L.y;
		end.y = R.y;
		line l = line(start, end);
		pors.push_back(l);
	}
	for (int j = 0; j < m; j++) {
		pointer p;
		cin >> p.x >> p.y;
		toys.push_back(p);
	}
	porlines.push_back(pors);
	toypointers.push_back(toys);
	return true;
}

//返回的是toy是否在l的左侧
bool POJ2318_Toys::left(line l, pointer p)
{
	//利用C++的短路效应
	return p.x < l.xmin || (p.x < l.xmax && (l.en.x - l.st.x)*(p.y - l.st.y) - (p.x - l.st.x)*( l.en.y - l.st.y) < 0);
}

//返回的是toy所在的分区号
int POJ2318_Toys::judge(pointer p, vector<line> porlines)
{
//	int res = 0;
//	while (res < porlines.size() && !left(porlines[res], p))res++;
	if (!left(porlines.back(), p)) return porlines.size();
	int l = 0, r = porlines.size() - 1;
	while (l <= r) {
		int suanz = (l + r) / 2;
		if (!left(porlines[suanz], p))l = suanz + 1;
		else r = suanz - 1;
	}
	return l;
}

void POJ2318_Toys::doing()
{
	cout << "the result is:" << endl;
	for (int i = 0; i < toypointers.size(); i ++) {
		vector<pointer> toys = toypointers[i];
		vector<line> pors = porlines[i];
		unordered_map<int, int>m;
		for (int i = 0; i < toys.size(); i++) {
			m[judge(toys[i], pors)] ++;
		}
		for (int i = 0; i <= pors.size(); i++)
			cout << i << ": " << m[i] << endl;
		if (!toypointers.empty())cout << endl;
	}
}



