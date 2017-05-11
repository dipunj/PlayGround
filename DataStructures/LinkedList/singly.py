class node(object):
	"""docstring for node"""
	def __init__(self,data,nxt):
		super(node, self).__init__()
		self.data = data
		self.next = nxt

def create_node(data,nxt):
	tmp = node(data,nxt)
	return tmp

def showMenu():
	print('___________________________________')
	print('\ta. Create a new node')
	print('\tb. Delete a node at a position')
	print('\tc. Insert a node after a position')
	print('\te. Exit')
	var = input('Your preference : ')
	return var

def displayList():
	print('___________________________________')
	i = 0
	trvl = mylist
	print('The list is')
	while trvl != None :
		i = i + 1
		print('\t' + str(i) + '. ' + str(trvl.data))
		trvl = trvl.next

def trvl2Parent(pos):
	trvl = mylist
	i = 1
	while int(i) < int(pos):
		trvl = trvl.next
		i = i + 1
	return trvl


import subprocess as sp
tmp = sp.call('clear',shell=True)

print('Welcome, this is a python program to demonstrate linear singly linked list')
var = showMenu()
while var != 'e':
	if var == 'a' :
		data = input('Input data for node')
		mylist = create_node(data, None)
	elif var == 'b' :
		pos = input('Position :')
		if pos == '1' :
			tempo = mylist
			mylist = mylist.next
			del(tempo)
		else :
			mynode = trvl2Parent(pos)
			mynode.next = mynode.next.next
	elif var == 'c' :
		pos = input('Position :')
		data = input('Enter data for node')
		
		if pos == '0':
			tempo = create_node(data,mylist)
			mylist = tempo
		else :
			mynode = trvl2Parent(pos)
			temp = mynode.next
			mynode.next = create_node(data,None)
			mynode.next.next = temp

	tmp = sp.call('clear',shell=True)
	displayList()
	var = showMenu()
print('Exiting...')