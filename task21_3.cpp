#include <iostream>
#include <vector>

using namespace std;

int sumKSmallest(const vector<int>& v, int k) {
    if (k <= 0 || v.empty()) return 0;
    int n = v.size();
    if (k > n) k = n;
    vector<int> copy = v;
    for (int i = 0; i < k; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (copy[j] < copy[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = copy[i];
            copy[i] = copy[minIndex];
            copy[minIndex] = temp;
        }
    }
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += copy[i];
    return sum;
}

vector<int> kLargest(const vector<int>& v, int k) {
    vector<int> result;
    if (k <= 0 || v.empty()) return result;
    int n = v.size();
    if (k > n) k = n;
    vector<int> copy = v;
    for (int i = 0; i < k; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (copy[j] > copy[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i) {
            int temp = copy[i];
            copy[i] = copy[maxIndex];
            copy[maxIndex] = temp;
        }
        result.push_back(copy[i]);
    }
    return result;
}

int sumKSmallestPointer(vector<int>* pv, int k) {
    if (!pv || k <= 0 || pv->empty()) return 0;
    int n = pv->size();
    if (k > n) k = n;
    vector<int> copy = *pv;
    for (int i = 0; i < k; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (copy[j] < copy[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = copy[i];
            copy[i] = copy[minIndex];
            copy[minIndex] = temp;
        }
    }
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += copy[i];
    return sum;
}

int maxElementPointer(vector<int>* pv) {
    if (!pv || pv->empty()) return 0;
    int maxVal = (*pv)[0];
    for (size_t i = 1; i < pv->size(); ++i) {
        if ((*pv)[i] > maxVal)
            maxVal = (*pv)[i];
    }
    return maxVal;
}

int main() {
    vector<int> v = {5, 2, 9, 1, 7};
    cout << sumKSmallest(v, 3) << "\n";
    vector<int> top2 = kLargest(v, 2);
    for (int x : top2) cout << x << " ";
    cout << "\n";
    cout << sumKSmallestPointer(&v, 3) << "\n";
    cout << maxElementPointer(&v) << "\n";
}
