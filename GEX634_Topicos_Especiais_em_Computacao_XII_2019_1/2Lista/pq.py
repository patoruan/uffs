# priority queue
class Priority_queue(object):
    def __init__(self):
        self.queue = []

    def __str__(self):
        return ' '.join([str(i) for i in self.queue])

    # Checking if the queue is empty
    def isEmpty(self):
        return len(self.queue) == []

    # To insert an element on queue
    def insert(self, data):
        self.queue.append(data)

    # To delete an elemente based on priority queue
    def delete(self):
        try:
            max = 0
            for i in range(len(self.queue)):
                if self.queue[i] > self.queue[max]:
                    max = i
            item = self.queue[max]
            del self.queue[max]
            return item
        except IndexError:
            print()
            exit()

