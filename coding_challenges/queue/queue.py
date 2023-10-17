MAX_TIME_LIMIT = 3000

queue = []
class RecentCounter(object):

    def __init__(self):
        self.queue = []

    def ping(self, t):
        queue.append(t)
        while (t - queue[0]) > MAX_TIME_LIMIT:
            queue.pop(0)

        print(queue)
        print(len(queue))
        return len(queue)
        
def main():
    obj = RecentCounter()
    param_1 = obj.ping(1178)
    param_2 = obj.ping(1483)
    param_3 = obj.ping(1563)
    param_4 = obj.ping(4054)
    param_5 = obj.ping(4152) 
  

if __name__ == "__main__":
    main()
# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)

