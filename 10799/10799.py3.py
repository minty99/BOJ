s = input()
level = 0
answer = 0
for i in range(len(s) - 1):
    if s[i] == '(' and s[i + 1] == ')':
        answer += level
    elif s[i] == ')' and s[i - 1] == '(':
        continue
    elif s[i] == '(':
        answer += 1
        level += 1
    elif s[i] == ')':
        level -= 1

print(answer)
