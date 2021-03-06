# fibonacci_wakeup

## USAGE

	chmod +x ./go.sh
	./go.sh

Change parameter i, rerun_time in stat.py and TOTAL_TIME in *.c to satisfy your requirement.

## OUTPUT

waitingTime: 两次有效唤醒的间隔时间

totWakeUp: 总唤醒次数，与耗电量正相关

totValidWakeup: 有效唤醒次数（无冲突）

validRate: 有效唤醒率

## SAMPLE OUTPUT (rerun_time = 1000, TOTAL_TIME = 1000000)

x轴: node

从图上看，在二者的waitingTime和totValidWakeup接近的情况下，fibonacciInterval有更高的validRate，更低的totWakeUp，也即fibonacciInterval更有效

### waitingTime:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/waitingTime_fix.png)

### totWakeUp:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/totWakeup_fix.png)

### totValidWakeup:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/totValidWakeup_fix.png)

### validRate:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/validRate_fix.png)

## SAMPLE OUTPUT (ZOOM IN TO COMPARE fibonacci AND random)

### waitingTime:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/waitingTime.png)

### totWakeUp:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/totWakeup.png)

### totValidWakeup:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/totValidWakeup.png)

### validRate:

![](https://github.com/bonboru93/fibonacci_wakeup/blob/master/validRate.png)
