class Tree:
     def __init__(self,data):
          self.data=data
          self.lchild=None
          self.rchild=None
     
     def  insert(self,data):
          if self.data:
               if data>self.data:
                    if self.rchild:
                         self.rchild.insert()
                    else:
                         self.rchild=Tree(data)
               else:
                    if self.lchild:
                         self.lchild.insert()
                    else:
                         self.lchild=Tree(data)
          else:
               self.data=data
     
     def preorder(self):
          if self.data:
               print(self.data)
               if self.lchild:
                    self.lchild.preorder()
               if self.rchild:
                    self.rchild.preorder()
     
     def  inorder(self):
          if self.data:
               if self.lchild:
                    self.lchild.inorder()
               print(self.data)
               if self.rchild:
                    self.rchild.inorder()
     
     def  level_order(self):
          l=[]
          l.append(self.data)
          while len(l):
               print(l[0])
               if self.lchild:
                    l.append(self.lchild.data)
               if self.rchild:
                    l.append(self.rchild.data)
               
               l=l.pop(0)





     

t=Tree(45)
t.insert(89)
t.insert(8)
t.preorder()
t.level_order()

t.inorder()