class JobPost:

    def __init__(self, title):
        self.title = title

    def get_title(self):
        return self.title


class JobSeeker:

    def __init__(self, name):
        self.name = name

    def on_job_post(self, job):
        print('Hi {}! New job posted: {}'.format(self.name, job.title))


class JobPostings:

    def __init__(self):
        self.observers = list()

    def notify(self, job_posting):
        for observer in self.observers:
            observer.on_job_post(job_posting)

    def attach(self, observer):
        self.observers.append(observer)

    def add_job(self, job_posting):
        self.notify(job_posting)


if __name__ == '__main__':

    # create subscribers
    john_doe = JobSeeker('John Doe')
    jane_doe = JobSeeker('Jane Doe')
    kane_doe = JobSeeker('Kane Doe')

    # create publisher and attach subscribers
    job_posting = JobPostings()
    job_posting.attach(john_doe)
    job_posting.attach(jane_doe)

    # add a new job and see if subscribers get notified
    job_posting.add_job(JobPost('Software Engineer'))

    # output:
    # Hi John Doe! New job posted: Software Engineer
    # Hi Jane Doe! New job posted: Software Engineer
