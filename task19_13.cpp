#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned char UCHAR;

int toInt(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 10;
	}
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	return -1;
}

char toChar(int v) {
	if (v >= 0 && v <= 9) {
		return char(v + '0');
	}
	if (v >= 10 && v <= 35) {
		return char(v - 10 + 'A');
	}
	return '?';
}

bool isValid(char c, int base) {
	int v = toInt(c);
	if (v == -1 || v >= base) {
		return false;
	} else {
		return true;
	}
}

vector<int> addition(const vector<UCHAR>& A, int baseA, const vector<UCHAR>& B, int baseB, int baseResult) {
	if (baseA < 2 || baseB < 2 || baseResult < 2) {
		return {};
	}

	for (char c : A) {
		if (!isValid(c, baseA)) {
			return {};
		}
	}
	for (char c : B) {
		if (!isValid(c, baseB)) {
			return {};
		}
	}

	unsigned long long numA = 0;
	unsigned long long mul = 1;
	for (int i = int(A.size()) - 1; i >= 0; --i) {
		numA += toInt(A[i]) * mul;
		mul *= baseA;
	}

	unsigned long long numB = 0;
	mul = 1;
	for (int i = int(B.size()) - 1; i >= 0; --i) {
		numB += toInt(B[i]) * mul;
		mul *= baseB;
	}

	unsigned long long sum = numA + numB;

	if (sum == 0) {
		return {0};
	}

	vector<int> res;
	while (sum > 0) {
		res.push_back(int(sum % baseResult));
		sum /= baseResult;
	}

	int n = int(res.size());
	for (int i = 0; i < n / 2; ++i) {
		int temp = res[i];
		res[i] = res[n - 1 - i];
		res[n - 1 - i] = temp;
	}

	return res;
}

bool parseLine(const string& line, int& base, vector<UCHAR>& vec) {
	vec.clear();
	int colon = -1;
	for (int i = 0; i < int(line.size()); ++i) {
		if (line[i] == ':') {
			colon = i;
			break;
		}
	}
	if (colon == -1) return false;

	base = 0;
	for (int i = 0; i < colon; ++i) {
		if (line[i] < '0' || line[i] > '9') return false;
		base = base * 10 + (line[i] - '0');
	}

	int q1 = -1, q2 = -1;
	for (int i = colon; i < int(line.size()); ++i) {
		if (line[i] == '"') {
			q1 = i;
			break;
		}
	}
	for (int i = int(line.size()) - 1; i > colon; --i) {
		if (line[i] == '"') {
			q2 = i;
			break;
		}
	}
	if (q1 == -1 || q2 == -1 || q1 == q2) return false;

	for (int i = q1 + 1; i < q2; ++i) {
		vec.push_back(line[i]);
	}

	return true;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	if (!fin.is_open() || !fout.is_open()) {
		cout << "Cannot open files\n";
		return 1;
	}

	string line1, line2;
	if (!getline(fin, line1) || !getline(fin, line2)) {
		cout << "Invalid input\n";
		return 1;
	}

	vector<UCHAR> A, B;
	int baseA, baseB, baseResult;

	if (!parseLine(line1, baseA, A) || !parseLine(line2, baseB, B)) {
		cout << "Parse error\n";
		return 1;
	}

	cout << "Enter base for result: ";
	cin >> baseResult;

	vector<int> res = addition(A, baseA, B, baseB, baseResult);

	if (res.empty()) {
		fout << "Error";
		cout << "Error in addition\n";
	} else {
		fout << "\"";
		for (int x : res) {
			fout << toChar(x);
		}
		fout << "\"\n";
		cout << "Result written\n";
	}

	fin.close();
	fout.close();
	return 0;
}
