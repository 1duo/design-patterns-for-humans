#include <iostream>
#include <string>
#include <vector>

class JobPost {
  protected:
	std::string title = "";

  public:
	JobPost(std::string title) {
		this->title = title;
	}

	std::string getTitle() {
		return this->title;
	}
};

class JobSeeker {
  protected:
	std::string name = "";

  public:
	JobSeeker(std::string name) {
		this->name = name;
	}

	void onJobPosted(JobPost* job) {
		std::cout << "Hi " << this->name << "! New job posted: "
		          << job->getTitle() << std::endl;
	}
};

class JobPostings {
  protected:
	std::vector<JobSeeker*> observers;

  public:
	void notify(JobPost* jobPosting) {
		for (auto observer : this->observers) {
			observer->onJobPosted(jobPosting);
		}
	}

	void attach(JobSeeker* observer) {
		this->observers.push_back(observer);
	}

	void addJob(JobPost* jobPosting) {
		this->notify(jobPosting);
	}
};

int main() {
	// create subscribers
	auto john = new JobSeeker("John Doe");
	auto jane = new JobSeeker("Jane Doe");
	// create publisher and attach subscribers
	auto jobPostings = new JobPostings();
	jobPostings->attach(john);
	jobPostings->attach(jane);
	// add a new job and see if subscribers get notified
	jobPostings->addJob(new JobPost("Software Engineer"));
	// ==============================================
	// Hi John Doe! New job posted: Software Engineer
	// Hi Jane Doe! New job posted: Software Engineer
	// ==============================================
	return 0;
}
