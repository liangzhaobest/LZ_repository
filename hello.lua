#!/usr/local/bin/lua
print("Hello World! ")
print("Hello China! ")
--两个减号是单行注释
--[[ 多行注释
多行注释
多行注释
--]]
--使用标识符时最好不要用下划线加大写字母的标识符。
--Lua语言是一个区分大小写的编程语言
--[[
关键词
以下列出了 Lua 的保留关键字。保留关键字不能作为常量或变量或其他用户自定义标示符：
and break
do else elseif end false
for function if
in  local  nil not or repeat
return then  true  until while

一般约定，以下划线开头连接一串大写字母的名字（比如 _VERSION）被保留用于 Lua 内部全局变量。
--]]
--默认情况下，变量总认为是全局的，也就是说给一个变量赋值后即创建了这个全局变量过
--访问没有初始化的全局变量得到的结果是：nil
print(b)
b=10;
print(b)
--要删除一个全局变量只需要将变量赋值为nil;



--[[数据类型
1.nil
2.boolean (包含：fasle true)
3.number (包含双精度类型和实浮点数）
4.string
5.function (由C或Lua编写的函数)
5.userdata (表示任意存储在变量中的C数据结构)
6.thread (表示执行的独立路线，用于执行协同程序)
7.table (表 ，其实是一个关联数组)
--]]
print(type("Hello world!"))
print()type(10.4*3)
print(type(print))
--可以用[[ ]]表示字符块
html = [[
<html>
<head></head>
<body>
    <a href="http://www.runoob.com/">菜鸟教程</a>
</body>
</html>
]]
print(html)





--在对一个数字字符串上进行算术操作时，Lua 会尝试将这个数字字符串转成一个数字
--例如
string1="1"+2;
print(type(string1));






--使用#来计算字符串的长度，放在字符串的前面
string3="hello world!";
print(#string3);




--注意：  在Lua 语言中，数组的默认初始索引一般以1 开始
--table 不会固定长度大小，有新数据添加时table长度会自动增长，没初始的table都是nil



--注意：Lua中清空屏幕的方式：输入 os.execute("cls")



--在Lua中。函数是被看作是第一类值（first-class value)
--函数可以存在变量里  实例：
function factorial1(n)
if n==0 then
return 1
else
return n*factorial1(n-1)
end
end
print(factorial1(5))
factorial2=factorial1
print(factoraial2(5))


--[[Lua的变量有三种类型：全局，局部，表中的域
Lua中的变量全部为全局变量 ,哪怕是语句块或是函数里，除非用local显式的声明局部变量
局部变量的作用域为从声明位置开始到所在语句块结束。
变量的默认值均为 nil。
--]]


--赋值语句
a="hello".."world"
t=.n=t.n+1
--还可以同时多个赋值

a,b=10,2*x;--等价于：a=10;b=2*x;
--当遇到赋值语句会计算右边的值然后执行赋值操作，如：
x,u=y,x;--swap'x'for'y'
当变量和数值的个数不一致时，Lua会一直以变量个数为基础采取一下措施：
a. 变量个数>值的个数       按变量个数补足nil
b.变量个数<值的个数        多余的值会被忽略

--多值赋值经常用来交换变量，或将函数调用返回给变量
a,b=f()

--应当尽可能的使用局部变量，有两个好处
--1.避免命名冲突
--2.访问局部变量的速度比全局变量更快






--Lua 循环


--四种方式  ：
--while 循环  for 循环
--repeat   until
--循环嵌套  可以在循环嵌套内嵌套一个或多个循环语句（while do ....end;  for... do...end;repeat....until;�


--Lua支持break语句，退出当前循环或语句



--无限循环
while(true)
do
print ("循环无限")
end;




--[[Lua 流程控制   (利用false true  判断)
控制结构的条件表达式结果可以是任何值，Lua认为false 和nil 为假，true



提供了  ： if 语句
			if else  语句
			if 嵌套语句
--]]



--[[  Lua函数
例：比较两个数的大小
function max(num1,num2)
if(num1>num2) then
result=num1;
else
result=num2;
end
return result;
end

可将函数作为参数传递给函数
可以返回多个返回中
可以接受可变数目的参数，和C语言类似，在参数列表中使用...表示函数有可变的参数。实例：

function average(...)
   result = 0
   local arg={...}    --> arg 为一个表，局部变量
   for i,v in ipairs(arg) do
      result = result + v
   end
   print("总共传入 " .. #arg .. " 个数")
   return result/#arg
end

print("平均值为",average(10,5,3,4,5,6))

有时会需要几个股东参数加上可变参数，注意：固定参数必须放在可变参数之前
--]]
