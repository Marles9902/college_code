# constant for modulo divisor
clock = 24

# get inputs for current time and number of hours until alarm goes off
currentTime = int(input("Enter the time now (in hours): "))
alarmHours = int(input("Enter the number of hours to wait for the alarm: "))

# calculate time when alarm goes off
alarmTime = (currentTime + alarmHours) % clock

# print results 
print("The time will be", alarmTime, "on the clock when the alarm goes off")
