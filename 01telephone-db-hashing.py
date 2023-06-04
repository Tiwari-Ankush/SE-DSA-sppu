# Consider telephone book database of N clients. Make use of a hash table 
# implementation to quickly look up client‘s telephone number. Make use of two collision 
# handling techniques and compare them using number of comparisons required to find a 
# set of telephone number

class Node:
    def __init__(self, name="", telephone=""):
        self.name = name
        self.telephone = telephone


class Hashing:
    def __init__(self):
        self.size = 100
        self.data = [[] for _ in range(self.size)]  # Separate Chaining - Each slot is a list

    def ascii_generator(self, s):
        total = 0
        for char in s:
            total += ord(char)
        return total % self.size

    def create_record(self, name, telephone):
        k = self.ascii_generator(name)
        record = Node(name, telephone)
        self.data[k].append(record)  # Inserting the record at the appropriate slot

    def search_record(self, name):
        k = self.ascii_generator(name)
        comparisons = 0
        for record in self.data[k]:
            comparisons += 1
            if record.name == name:
                print("\nRecord found")
                print("Name:", record.name)
                print("Telephone:", record.telephone)
                break
        else:
            print("Record not found")
        
        # print(comparisons)
        return comparisons

    def delete_record(self, name):
        k = self.ascii_generator(name)
        deleted = False
        for record in self.data[k]:
            if record.name == name:
                self.data[k].remove(record)
                print("\nRecord deleted successfully")
                deleted = True
                break
        if not deleted:
            print("Record not found")

    def update_record(self, name):
        k = self.ascii_generator(name)
        updated = False
        for record in self.data[k]:
            if record.name == name:
                print("Enter the new telephone number:")
                new_telephone = input()
                record.telephone = new_telephone
                print("\nRecord updated successfully")
                updated = True
                break
        if not updated:
            print("Record not found")

    def display_record(self):
        print("\tName\t\tTelephone")
        for slot in self.data:
            for record in slot:
                print("\t" + record.name + "\t\t" + record.telephone)


if __name__ == "__main__":
    s = Hashing()
    loop = True
    while loop:
        print("\n-------------------------")
        print(" Telephone book Database ")
        print("-------------------------")
        print("1. Create Record")
        print("2. Display Record")
        print("3. Search Record")
        print("4. Update Record")
        print("5. Delete Record")
        print("6. Exit")
        
        choice = int(input("enter your choice: "))

        if choice == 1:
            print("Enter name:")
            name = input()
            print("Enter telephone number:")
            telephone = input()
            s.create_record(name, telephone)

        elif choice == 2:
            s.display_record()

        elif choice == 3:
            print("Enter the name:")
            name = input()
            comparisons = s.search_record(name)
            print("Number of comparisons required:", comparisons)

        elif choice == 4:
            print("Enter the name:")
            name = input()
            s.update_record(name)

        elif choice == 5:
            print("Enter name to delete:")
            name = input()
            s.delete_record(name)

        elif choice == 6:
            loop = False

        else:
            print("You entered something wrong!")
