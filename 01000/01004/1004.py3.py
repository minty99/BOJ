# import sys
def isIn(cx, cy, cr, px, py):
	r2 = (px - cx) ** 2 + (py - cy) ** 2
	cr2 = cr ** 2
	if r2 < cr2: return True
	else: return False

# sys.stdin = open("in.txt", "r")
t = int(input())
for _ in range(t):
	x1, y1, x2, y2 = [ int(x) for x in input().split() ]
	n = int(input())
	cx = []
	cy = []
	cr = []
	for i in range(n):
		tx, ty, tr = [ int(x) for x in input().split() ]
		cx.append(tx)
		cy.append(ty)
		cr.append(tr)

	answer = n
	for i in range(n):
		if isIn(cx[i], cy[i], cr[i], x1, y1) == isIn(cx[i], cy[i], cr[i], x2, y2):
			answer -= 1
	print(answer)
