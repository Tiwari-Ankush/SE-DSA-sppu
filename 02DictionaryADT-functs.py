# Implement all the functions of a dictionary (ADT) using hashing and handle collisions
# using chaining  with / wothout replacement.
# Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
# Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)


# with replacement for keys must be unique
#without - no need for unique keys
class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


class HashDictionary:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        new_node = Node(key, value)

        if self.table[index] is None:
            self.table[index] = new_node

# ************with replacement *************
        else:
            current = self.table[index]
            while current:
                if current.key == key:
                    current.value = value  # Replace the existing value
                    return
                if current.next is None:
                    break
                current = current.next
            current.next = new_node


# **************without replacement ************
   
        # else:
        #     current = self.table[index]
        #     while current.next:
        #         current = current.next
        #     current.next = new_node
# ----------------------

    def find(self, key):
        index = self.hash_function(key)

        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def delete(self, key):
        index = self.hash_function(key)

        if self.table[index] is None:
            return

        if self.table[index].key == key:
            self.table[index] = self.table[index].next
            return
        
        # chaining deletion
        current = self.table[index]
        while current.next:
            if current.next.key == key:
                current.next = current.next.next
                return
            current = current.next

    def display(self):
        print("Dictionary Contents:")
        for index in range(self.size):
            current = self.table[index]
            while current:
                print(f"Key: {current.key}, Value: {current.value}")
                current = current.next


if __name__ == "__main__":
    size = int(input("Enter the size of the hash table: "))
    dictionary = HashDictionary(size)

    while True:
        print("\nDictionary Operations")
        print("1. Insert")
        print("2. Search")
        print("3. Delete")
        print("4. Display")
        print("5. Exit")
        choice = int(input("Enter choice: "))

        if choice == 1:
            key = input("Enter key: ")
            value = input("Enter value: ")
            dictionary.insert(key, value)
            print("Key-Value pair inserted successfully.")

        elif choice == 2:
            key = input("Enter key to find: ")
            value = dictionary.find(key)
            if value is not None:
                print(f"Value: {value}")
            else:
                print("Key not found.")

        elif choice == 3:
            key = input("Enter key to delete: ")
            dictionary.delete(key)
            print("Key deleted successfully.")

        elif choice == 4:
            dictionary.display()

        elif choice == 5:
            break

        else:
            print("Invalid choice. Please try again.")
