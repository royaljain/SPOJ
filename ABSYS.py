

num = input()


for t in range(0,num):
	blankline = input()
	line = input()
	x = line.split('+')
	a = x[0].strip()
	y = x[1].split('=')
	b = y[0].strip()
	c = y[1].strip()


	if a.contains('machula'):
		b1 = int(b)
		c1 = int(c)
		a1 = c1 - b1
	elif b.contains('machula'):
		a1=int(a)
		c1=int(c)
		b1 = c1-a1
	elif c.contains('machula'):
		a1=int(a)
		b1=int(b)
		c1=a1+b1
	
	out = str(a1) + " + " + str(b1) + " = " + str(c1) 
	
	print(out)
