import matplotlib.pyplot as plt
from ctypes import *
class resultStruct(Structure):
	_fields_ = [("totWakeup", c_int), ("totValidWakeup", c_int), ("validRate", c_double), ("waitingTime", c_double)]
def plotResult(lb, cl):
	x = []
	y1 = []
	y2 = []
	y3 = []
	y4 = []
	i = 10
	rerun_time = 1000
	for node in range(0, 100):
		v1 = 0
		v2 = 0
		v3 = 0
		v4 = 0
		for rerun in range(0, rerun_time):
			result = clib.sim(i)
			v1 += result.contents.totWakeup
			v2 += result.contents.totValidWakeup
			v3 += result.contents.validRate
			v4 += result.contents.waitingTime
		x.append(i)
		y1.append(v1/rerun_time)
		y2.append(v2/rerun_time)
		y3.append(v3/rerun_time)
		y4.append(v4/rerun_time)
		i += 10

	plt.figure("totWakeup")
	plt.plot(x, y1, label = lb, color = cl)

	plt.figure("totValidWakeup")
	plt.plot(x, y2, label = lb, color = cl)

	plt.figure("validRate")
	plt.plot(x, y3, label = lb, color = cl)

	plt.figure("waitingTime")
	plt.plot(x, y4, label = lb, color = cl)


clib = cdll.LoadLibrary("./randomInterval.so")
clib.sim.restype = POINTER(resultStruct)
plotResult('random', 'b')

clib = cdll.LoadLibrary("./fibonacciInterval.so")
clib.sim.restype = POINTER(resultStruct)
plotResult('fibonacci', 'r')

plt.legend()
plt.show()
