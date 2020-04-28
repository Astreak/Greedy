class Graph:
    def __init__(self):
        self.path=[]

        self.dict={}

    def VERTEX(self):
        return list(self.dict.keys())

    def add_vertex(self,v):
        self.dict[v]=[]

    def add_edge(self,u,v):
        if u in self.dict:
            if v not in self.dict[u]:
                self.dict[u].append(v)
                self.dict[v].append(u)
        else:
            self.dict[u]=[v]
            self.dict[v].append(u)

    def find_path(self,start,end):
        if start in self.dict and end in self.dict:
            if start not in self.path:
                self.path.append(start)
                if end in self.dict[start]:
                    self.path.append(end)
                    print(self.path)
                    return 
                else:
                    for i in self.dict[start]:
                        self.find_path(i,end)









        else:
            print("Any of the nodes are not present in your path")

                








    def ok(self):
        return self.dict
        

g=Graph()
g.add_vertex("a")
g.add_vertex("b")
g.add_vertex("d")
g.add_vertex("c")
g.add_edge("a","b")

g.add_edge("c","b")
g.add_edge("a","d")
g.add_edge("d","c")

print(g.ok())


g.find_path("a","c")




