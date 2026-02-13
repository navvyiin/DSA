class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> Node
        
        # Dummy head and tail
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        
        self.head.next = self.tail
        self.tail.prev = self.head

    # Remove node from list
    def _remove(self, node):
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    # Insert node right after head (most recent)
    def _insert(self, node):
        node.next = self.head.next
        node.prev = self.head
        
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        self._remove(node)
        self._insert(node)  # Move to front
        
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update value and move to front
            node = self.cache[key]
            node.value = value
            self._remove(node)
            self._insert(node)
        else:
            if len(self.cache) >= self.capacity:
                # Remove least recently used (tail.prev)
                lru = self.tail.prev
                self._remove(lru)
                del self.cache[lru.key]
            
            new_node = Node(key, value)
            self.cache[key] = new_node
            self._insert(new_node)