# Time Stamping made Simple (tss)

It is a simple utility to prepend timestamp through pipelining. Linux users may want to look at 'ts' instead. Although this implementation also works on Linux, this utility was created due to the lack of 'ts' on OS X, macOS, or Unix in general.

Please feel free to use the code for commercial or non-commercial purposes. Write me if you added anything useful or spotted any issue.

## Build

Any GCC compiler should do the job just fine.
```
gcc -o tss tss.c
```

## Install
Administrative privilege required for system-wide installation:
```
sudo cp tss /usr/local/bin
```
otherwise, it can be called locally (see Example)

## Example of Usage
* Echo a string to stdout (you all know about this)
```
echo 'hello'
> hello
```
* Echo a string to stdout with timestamp
```
echo 'hello' | tss
> [2017-01-01 16:40:17.774178] hello
```
* Redirect output to a file
```
echo 'hello' | tss > program.log
```
* If tss is installed locally (in current directory)
```
echo 'hello' | ./tss > program.log
```
## TODO
Makefile for build configuration, dependency check, and system installation  
