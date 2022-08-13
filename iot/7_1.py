import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.output)

num = int(input("Enter the number"))

if num == 1:
    GPIO.output(17, GPIO.HIGH)
    time.sleep(1)
    while(True):
        num = int(input())
        if num == 0:
            GPIO.output(17, GPIO.LOW)
            break


GPIO.cleanup()
