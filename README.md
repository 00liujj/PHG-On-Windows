# PHG-On-Windows

PHG(http://lsec.cc.ac.cn/phg/) 是张林波研究员设计的并行自适应有限元平台。
这里是phg-0.9.2的一个windows二进制版本，希望能给在windows下编写PHG应用程序的人提供方便。

用户可以将这个库集成到自己的Visual Studio开发环境。可以使用MSVC自带编译器cl或者Clang的编译器clang-cl。

examples下的应用程序编译方式如下：
```bash
cd examples
clang-cl poisson.c -I ..\include ..\lib\phg.lib
```
运行方式如下：
```bash
cd bin
mpiexec -n 1 ..\examples\poisson.exe
```

注意：由于MSVC不支持C89标准，MSVC不支持可变长数组，而张老师在examples中使用了少量可变长数组。
所以examples下面的应用程序用MSVC编译是有错误的。
也就是说，对于如下代码
```c
int main() {
  int n = 10;
  double a[n];
}
```
MSVC是没法编译的。

此时，如果您有MSVC编译器，建议下载一个Clang编译器。用clang-cl代替MSVC自带的cl即可。



PHG(http://lsec.cc.ac.cn/phg/) is a parallel adaptive FEM platform designed by Prof. Linbo Zhang, LSEC. 
This is a windows binary version of the original source code phg-0.9.2, which includes 
related dynamic loading libraries and MSMPI. 
I have tested it for Clang and MSVC compilers. 
Now you can use Visual Studio IDE to develop PHG applications!

