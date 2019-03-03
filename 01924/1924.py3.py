day = ['', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
daycount = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
today = 0

a = input().split()
b = int(a[1])
a = int(a[0])

for i in range(1, a+1):
    for j in range(1, daycount[i]+1):
        today += 1
        if today > 7: today -= 7
        if i == a and j == b: break

print(day[today])