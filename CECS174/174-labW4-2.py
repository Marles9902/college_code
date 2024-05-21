# constant for modulo divisor
clock = 24

# get inputs for current time and number of hours until alarm goes off
currentTime = int(input("Enter the time now (in hours): "))
alarmHours = int(input("Enter the number of hours to wait for the alarm: "))

# calculate time when alarm goes off
alarmTime = (currentTime + alarmHours) % clock

# MODIFICATION MADE HERE
# statement if alarm is set in AM or PM
if alarmTime > 12:
    # reverts military time to standard time if clock goes over 12 
    alarmTime -= 12
    print("The time the alarm will go off is:", alarmTime, "PM")
else:
    print("The time the alarm will go off is:", alarmTime, "AM")
