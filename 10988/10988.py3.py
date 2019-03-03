import sys
s = input()

left = 0
right = len(s) - 1
while True:
    if s[left] != s[right]:
        print(0)
        sys.exit()
    left += 1
    right -= 1
    if left > right: break
print(1)