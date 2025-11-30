#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct House {
	int x;
	int y;
};

struct Street {
	int x;
	int y;
};

class Town {
private:
	string name;
	vector<House> houses;
	vector<Street> streets;

	int randomInt(int min, int max) {
		return min + rand() % (max - min);
	}

public:
	Town(const string& townName = "Unnamed") : name(townName) {
		generate();
	}

	void generate() {
		houses.clear();
		streets.clear();

		int houseCount = randomInt(100, 1000000);
		int streetCount = randomInt(2500, 3500);

		houses.reserve(houseCount);
		streets.reserve(streetCount);

		for (int i = 0; i < houseCount; ++i) {
			houses.push_back({ randomInt(0, 8000), randomInt(0, 8000) });
		}

		for (int i = 0; i < streetCount; ++i) {
			streets.push_back({ randomInt(0, 8000), randomInt(0, 8000) });
		}
	}

	void printSummary() const {
		cout << "Town: " << name << "\n";
		cout << "Number of houses: " << houses.size() << "\n";
		cout << "Number of streets: " << streets.size() << "\n";

		if (!houses.empty()) {
			cout << "First 5 houses coordinates:\n";
			for (size_t i = 0; i < min(size_t(5), houses.size()); ++i) {
				cout << "\tHouse " << i + 1 << ": (" << houses[i].x << ", " << houses[i].y << ")\n";
			}
		}

		if (!streets.empty()) {
			cout << "First 5 streets coordinates:\n";
			for (size_t i = 0; i < min(size_t(5), streets.size()); ++i) {
				cout << "\tStreet " << i + 1 << ": (" << streets[i].x << ", " << streets[i].y << ")\n";
			}
		}
	}

	const vector<House>& getHouses() const { return houses; }
	const vector<Street>& getStreets() const { return streets; }
	const string& getName() const { return name; }
};

int main() {
	Town myTown("SampleTown");
	myTown.printSummary();

	return 0;
}
