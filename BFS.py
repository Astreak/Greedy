class Linked:
	def __init__(self,data):
		self.data=data
		self.next=None
		self.head=None

	def insert(self,data):
		if not self.head:
			self.head=Linked(data)
		else:
			if(self.head.next):
				temp=self.head
				while(temp.next):
					temp=temp.next
				temp.next=Linked(data)
			else:
				self.head.next=Linked(data)

	def show(self):
		if(self.head):
			temp=self.head
			while(temp):
				print(temp.data)
				temp=temp.next













class Vertex:
	def __init__(self,data):
		self.value=data
		self.color="grey"
		self.neighbors=[]


class Graph:
	def __init__(self):
		self.gr={}
		self.nodes=[]

	def add_vertex(self,value):
		if not value in self.gr.keys():
			self.gr[value]=[]
			self.nodes.append(Vertex(value))

	def add_edge(self,u,v):
		if u and v in self.gr.keys():
			for i in self.nodes:
				if i.value==u:
					if not v in i.neighbors:
						i.neighbors.append(v)
				if i.value==v:
					if not u in i.neighbors:
						i.neighbors.append(u)
		else:
			raise("error")

	def bfs(self,s):
		l=[]
		d={}
		trav=[]
		pred={}

		for i in self.nodes:
			if i.value==s:
				l.append(i)
				i.color="black"
		d[0]=l[0].value
		pred[l[0].value]="O"

		while l:
			ok=l.pop(0)
			trav.append(ok)
			length=int(list(d.keys())[-1])		
			
			d[length+1]=[]
			flag=0
			for y in ok.neighbors:
				
				for k in self.nodes:

					if k.value==y and k.color=="grey":
						d[length+1].append(y)
						l.append(k)
						k.color="black"
						pred[y]=ok.value
						flag=1
					
			if not flag:
				del d[length+1]
						



		print(d)

		return (trav,d)

	def dfs(self,v):
		l=[]
		trav=[]
		for i in self.nodes:
			if i.value==v:
				l.append(i)
				i.color="black"
		while l:
			ok=l.pop(-1)
			trav.append(ok)
			for i in ok.neighbors:
				for j in self.nodes:
					if j.value==i and j.color!="black":
						l.append(j)
						j.color="black"

		return trav



















	def show(self):
		for i in self.nodes:
			self.gr[i.value]=i.neighbors
		return self.gr


g=Graph()
g.add_vertex("a")
g.add_vertex("b")
g.add_vertex("c")
g.add_vertex("d")
g.add_vertex("e")
g.add_vertex("f")

g.add_edge("a","b")
g.add_edge("a","e")
g.add_edge("c","d")
g.add_edge("c","b")
g.add_edge("e","f")


print(g.show())
print("-------------------")
G,M=g.bfs("a")
g=Graph()
g.add_vertex("a")
g.add_vertex("b")
g.add_vertex("c")
g.add_vertex("d")
g.add_vertex("e")
g.add_vertex("f")

g.add_edge("a","b")
g.add_edge("a","e")
g.add_edge("c","d")
g.add_edge("c","b")
g.add_edge("e","f")
V=g.dfs("a")
for j in V:
	print(j.value)
print("=++++++++")
for i in G:
	print(i.value)
print("DIFFERENT-------------------------------------------------------------------------------------------------------")
l=Linked(12)
l.insert(90)
l.insert(100)
l.insert(1)
l.show()

