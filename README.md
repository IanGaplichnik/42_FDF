# 42_FDF
This project allows you to create a mesh, using data, extracted from a file. 

![example screenshot](https://github.com/IanGaplichnik/42_FDF/blob/master/img/1.png)
![example screenshot](https://github.com/IanGaplichnik/42_FDF/blob/master/img/2.png)
![example screenshot](https://github.com/IanGaplichnik/42_FDF/blob/master/img/3.png)


Information in the file can be, for example, represented in the next way:
```
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```
where first number, before comma, represents the height of the starting/ending point of the line, value after comma is a hex color value, applied to the line.


## Usage

_REQUIRES MINILIB X INSTALLED_
