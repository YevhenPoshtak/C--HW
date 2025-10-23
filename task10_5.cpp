#include <iostream>
using namespace std;

struct Mountain {
    string name;
    int height;
};

void inputMountains(Mountain arr[], int N) {
    for(int i = 0; i < N; i++) {
        cout << "Enter name of mountain #" << i+1 << ": ";
        cin >> arr[i].name;
        cout << "Enter height of " << arr[i].name << ": ";
        cin >> arr[i].height;
    }
}

void outputMountains(Mountain arr[], int N) {
    for(int i = 0; i < N; i++) {
        cout << arr[i].name << " - " << arr[i].height << " m" << endl;
    }
}

string findHighestMountain(Mountain arr[], int N) {
    int maxIndex = 0;
    for(int i = 1; i < N; i++) {
        if(arr[i].height > arr[maxIndex].height)
            maxIndex = i;
    }
    return arr[maxIndex].name;
}

void printHeightByName(Mountain arr[], int N, string searchName) {
    for(int i = 0; i < N; i++) {
        if(arr[i].name == searchName) {
            cout << "Height of " << searchName << " is " << arr[i].height << " m" << endl;
            return;
        }
    }
    cout << "No mountain with the name " << searchName << " found in the array." << endl;
}

int main() {
    int N;
    cout << "Enter number of mountains: ";
    cin >> N;
    Mountain mountains[N];
    inputMountains(mountains, N);
    cout << "\nList of mountains:\n";
    outputMountains(mountains, N);
    cout << "\nHighest mountain: " << findHighestMountain(mountains, N) << endl;
    string searchName;
    cout << "\nEnter mountain name to search for its height: ";
    cin >> searchName;
    printHeightByName(mountains, N, searchName);
    return 0;
}
