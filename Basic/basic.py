class Tree:
	def __init__(self,data=None):
		self.data=data
		self.lchild=None
		self.rchild=None

	def insert(self,data):
		if(self.data):
			if(self.data>=data):
				if(self.lchild==None):
					self.lchild=Tree(data)
				else:
					self.lchild.insert(data)
			else:
				if(self.rchild==None):
					self.rchild=Tree(data)
				else:
					self.rchild.insert(data)
		else:
			self.data=Tree(data)


	def level(self):
		l=[]
		l.append(self)
		while(len(l)>0):
			d=l[0]
			print(l[0].data)
			l.pop(0)
			if(d.lchild is not None):
				l.append(d.lchild)
			if(d.rchild is not None):
				l.append(d.rchild)

	@staticmethod
	def search(root,data):
		if(root.data):
			if(root.data>data):
				if(root.lchild!=None):
					return Tree.search(root.lchild,data)

				else:
					return False
			elif(root.data<data):
				if(root.rchild!=None):
					return Tree.search(root.rchild,data)
				else:
					return False
			else:
				return True
		else:
			return False


	def width(self):
		if(self.data):

			if(self.lchild):
				lh=self.lchild.width()

			if(self.rchild):
				rh=self.rchild.width()
			return lh+rh

		else:
			print("Tree doesnt exist")






tree=Tree(56)
tree.insert(5)
tree.insert(78)
tree.insert(67)
tree.insert(4)
print(tree.width())


