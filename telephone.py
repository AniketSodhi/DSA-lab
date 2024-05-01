class Node: 
	def __init__(self):
		self.name = ""
		self.tel = 0
		self.id = 0


class Hashing:
	def __init__(self):
		self.data = [Node() for _ in range(100)]

	def create_record(self, size):
		i = 4
		n = "XYZ Gupta"
		t = 23451234
		print(f"\nEnter id : {i}")
		print(f"\nEnter name : {n}")
		print(f"\nEnter telephone number : {t}")
		
		index = i % size
		while True:
			if self.data[index].id == 0:
				self.data[index].id = i
				self.data[index].name = n
				self.data[index].tel = t
				break
			else:
				index = (index + 1) % size

	def search_record(self, size):
		key = 4
		print(f"\nEnter record id to search : {key}")
		index = key % size
		found = False
		for _ in range(size):
			if self.data[index].id == key:
				found = True
				print(f"\nRecord found:")
				print(f"ID\tNAME\t\tTELEPHONE")
				print(f"{self.data[index].id}\t{self.data[index].name}\t{self.data[index].tel}")
				break
			else:
				index = (index + 1) % size
		if not found:
			print("\nRecord not found")

	def delete_record(self, size):
		key = 4
		print(f"\nEnter record id to delete : {key}")
		index = key % size
		found = False
		for _ in range(size):
			if self.data[index].id == key:
				found = True
				self.data[index].id = 0
				self.data[index].name = ""
				self.data[index].tel = 0
				print("\nRecord deleted successfully")
				break
			else:
				index = (index + 1) % size
		if not found:
			print("\nRecord not found")

	def update_record(self, size):
		key = 4
		print(f"\nEnter record id to update : {key}")
		index = key % size
		found = False
		for _ in range(size):
			if self.data[index].id == key:
				found = True
				self.data[index].name = "XYZ Agarwal"
				self.data[index].tel = 23413421
				print(f"\nEnter name: {self.data[index].name}")
				print(f"Enter telephone number: {self.data[index].tel}")
				print("\nDetails updated:")
				print(f"ID\tNAME\t\tTELEPHONE")
				print(f"{self.data[index].id}\t{self.data[index].name}\t{self.data[index].tel}")
				break
			else:
				index = (index + 1) % size
		if not found:
			print("\nRecord not found")

	def display_record(self, size):
		print(f"ID\tNAME\t\tTELEPHONE")
		for node in self.data:
			if node.id != 0:
				print(f"{node.id}\t{node.name}\t{node.tel}")


if __name__ == "__main__":
	size = 20
	s = Hashing()

	print("\n1.CREATE record ")
	s.create_record(size)

	print("\n\n2.DISPLAY record ")
	s.display_record(size)

	print("\n\n3.SEARCH record")
	s.search_record(size)

	print("\n\n4.UPDATE record ")
	s.update_record(size)

	print("\n\n5.DELETE record ")
	s.delete_record(size)


