import threading
import time

threadLock = threading.Lock()


class myThread(threading.Thread):
    def __init__(self, threadID, name, counter):
        super(myThread, self).__init__()
        self.threadID = threadID
        self.name = name
        self.counter = counter

    def run(self):
        print("Starting " + self.name)
        threadLock.acquire()
        print_time(self.name, self.counter, 3)
        threadLock.release()


def print_time(threadName, delay, counter):
    while counter:
        time.sleep(delay)
        print("%s: %s" % (threadName, time.ctime(time.time())))
        counter -= 1


threads = []

# Create new threads
thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

# Start new threads
thread1.start()
thread2.start()

# Add threads to thread list
threads.append(thread1)
threads.append(thread2)

# Wait for all threads to complete
for t in threads:
    t.join()
print("Exiting Main Thread")
