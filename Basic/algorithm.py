class Binary_Tree:
	def __init__(self,data):
		self.data=data
		self.lchild=None
		self.rchild=None

	def insert(self,data):
		if self.data:
			if data<self.data:
				if self.lchild==None:
					self.lchild=Tree(data)
				else:
					self.lchild.insert(data)
			else:
				if self.rchild==None:
					self.rchild=Tree(data)
				else:
					self.rchild.insert(data)


		else:
			self.data=data


	def inorder(self):
		d={}
		if self.lchild:
			self.lchild.inorder()
		print(self.data,end=" ")
		d[self.data]+=1
		if self.rchild:
			self.rchild.inorder()
		print(d)
	def preorder(self):
		print(self.data)
		if self.lchild:
			self.lchild.preorder()
		if self.rchild:
			self.rchild.preorder()


	def level_order(self):
		l=[]
		d={}
		l.append(self.data)
		while len(l)>0:
			print(l[0])
			
			if self.lchild:
				l.append(self.lchild.data)
			if self.rchild:
				l.append(self.rchild.data)

			l.remove(l[0])

		print(d)

	def search(self,value):
		if self.data>value:
			if self.lchild:
				self.lchild.search(value)
			else:
				return "Not Found"
		elif self.data<value:
			if self.rchild:
				self.rchild.search(value)
			else:
				return "Not Found"
		
		return "FOund"

		
	def however(self):
		d={}
		l=[]
		if self.lchild:
			self.lchild.however()
		if self.rchild:
			self.rchild.however()
		d[self.data]+=1

		print(d)
		


class Tree:
	def __init__(self,data,nodes):
		self.data=data
		self.nodes=nodes
	def set(self):
		children=[]
		for i in range(self.nodes):
			children.append(self)


		














root=Binary_Tree(12)
root.insert(4)
root.insert(1)
root.insert(67)
root.insert(67)
root.insert(89)
root.insert(899)

root.inorder()
root.however()
print(root.search(67))
