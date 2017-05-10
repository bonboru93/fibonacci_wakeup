gcc -fPIC -o fibonacciInterval.so -shared ./fibonacciInterval.c
gcc -fPIC -o randomInterval.so -shared ./randomInterval.c
gcc -fPIC -o randomFixInterval.so -shared ./randomFixInterval.c
pip install matplotlib
apt-get install python-tk
echo ==========
echo RUNNING
echo ==========
python stat.py
