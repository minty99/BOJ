x, y, w, h = (int(x) for x in input().split())
print(min(abs(w-x), abs(h-y), x, y))
