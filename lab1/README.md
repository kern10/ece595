# [ECE595 Programming Project 1](https://engineering.purdue.edu/~ece595/labs_2018/lab1.html)
## Description
> This first project first sets up the DLXOS directory structure and dev environment on an ECN Linux machine. Then, a new user trap called "Getpid" is implemented. This trap returns an integer representing the ID of the current process. When DLXOS is run on the hardware simulator, the integer PID is printed.

## Getting started
1. Enter the lab1 directory. <br/>
	``` $ cd  ~/ece595/lab1```
2. First we will compile the OS. This is made easy by make. <br/>
	``` $ cd os/```<br/>
	``` $ make```
3. Next, we will compile the user program. This is made easy by make.<br/>
	``` $ cd  ~/ece595/lab1```<br/>
	``` $ cd apps/```<br/>
	``` $ make```
4. Now we will run the program.<br/> 
	``` $ cd  ~/ece595/lab1```<br/>
	``` $ dlxsim -x ~/ece595/lab1/os/work/os.dlx.obj -a -u ~/ece595/lab1/apps/work/userprog.dlx.obj```

## Expected 
