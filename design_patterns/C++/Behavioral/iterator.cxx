#include <iostream>
#include <vector>
#include <cmath>

class RadioStation {
  protected:
	float frequency = 0.0;

  public:
	RadioStation(float frequency) {
		this->frequency = frequency;
	}

	float getFrequency() {
		return this->frequency;
	}
};

class StationList {
  protected:
	std::vector<RadioStation*> stations;
	int counter = 0;

  public:
	void addStation(RadioStation* station) {
		this->stations.push_back(station);
	}

	void remove(RadioStation* toRemove) {
		float toRemoveFrequency = toRemove->getFrequency();
		auto newEnd = std::remove_if(this->stations.begin(),
		this->stations.end(), [&toRemoveFrequency](RadioStation * station) {
			return fabs(station->getFrequency() - toRemoveFrequency)
			       <= std::numeric_limits<float>::epsilon();
		});
		this->stations.erase(newEnd, this->stations.end());
	}

	int count() {
		return this->stations.size();
	}

	RadioStation* current() {
		return this->stations[this->counter];
	}

	int key() {
		return this->counter;
	}

	void next() {
		++this->counter;
	}

	void rewind() {
		this->counter = 0;
	}

	bool valid() {
		return this->counter < this->count();
	}
};

int main() {
	auto stationList = new StationList();
	stationList->addStation(new RadioStation(89));
	stationList->addStation(new RadioStation(101));
	stationList->addStation(new RadioStation(102));
	stationList->addStation(new RadioStation(103.2));
	for (auto i = stationList->count(); i > 0; --i) {
		std::cout << stationList->current()->getFrequency() << std::endl;
		stationList->next();
	}
	// =====
	// 89
	// 101
	// 102
	// 103.2
	// =====
	stationList->remove(new RadioStation(89));
	stationList->rewind();
	for (auto i = stationList->count(); i > 0; --i) {
		std::cout << stationList->current()->getFrequency() << std::endl;
		stationList->next();
	}
	// =====
	// 101
	// 102
	// 103.2
	// =====
	return 0;
}
