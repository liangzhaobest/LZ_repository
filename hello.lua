#!/usr/local/bin/lua
print("Hello World! ")
print("Hello China! ")
--���������ǵ���ע��
--[[ ����ע��
����ע��
����ע��
--]]
--ʹ�ñ�ʶ��ʱ��ò�Ҫ���»��߼Ӵ�д��ĸ�ı�ʶ����
--Lua������һ�����ִ�Сд�ı������
--[[
�ؼ���
�����г��� Lua �ı����ؼ��֡������ؼ��ֲ�����Ϊ����������������û��Զ����ʾ����
and break
do else elseif end false
for function if
in  local  nil not or repeat
return then  true  until while

һ��Լ�������»��߿�ͷ����һ����д��ĸ�����֣����� _VERSION������������ Lua �ڲ�ȫ�ֱ�����
--]]
--Ĭ������£���������Ϊ��ȫ�ֵģ�Ҳ����˵��һ��������ֵ�󼴴��������ȫ�ֱ�����
--����û�г�ʼ����ȫ�ֱ����õ��Ľ���ǣ�nil
print(b)
b=10;
print(b)
--Ҫɾ��һ��ȫ�ֱ���ֻ��Ҫ��������ֵΪnil;



--[[��������
1.nil
2.boolean (������fasle true)
3.number (����˫�������ͺ�ʵ��������
4.string
5.function (��C��Lua��д�ĺ���)
5.userdata (��ʾ����洢�ڱ����е�C���ݽṹ)
6.thread (��ʾִ�еĶ���·�ߣ�����ִ��Эͬ����)
7.table (�� ����ʵ��һ����������)
--]]
print(type("Hello world!"))
print()type(10.4*3)
print(type(print))
--������[[ ]]��ʾ�ַ���
html = [[
<html>
<head></head>
<body>
    <a href="http://www.runoob.com/">����̳�</a>
</body>
</html>
]]
print(html)





--�ڶ�һ�������ַ����Ͻ�����������ʱ��Lua �᳢�Խ���������ַ���ת��һ������
--����
string1="1"+2;
print(type(string1));






--ʹ��#�������ַ����ĳ��ȣ������ַ�����ǰ��
string3="hello world!";
print(#string3);




--ע�⣺  ��Lua �����У������Ĭ�ϳ�ʼ����һ����1 ��ʼ
--table ����̶����ȴ�С�������������ʱtable���Ȼ��Զ�������û��ʼ��table����nil



--ע�⣺Lua�������Ļ�ķ�ʽ������ os.execute("cls")



--��Lua�С������Ǳ������ǵ�һ��ֵ��first-class value)
--�������Դ��ڱ�����  ʵ����
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


--[[Lua�ı������������ͣ�ȫ�֣��ֲ������е���
Lua�еı���ȫ��Ϊȫ�ֱ��� ,������������Ǻ����������local��ʽ�������ֲ�����
�ֲ�������������Ϊ������λ�ÿ�ʼ���������������
������Ĭ��ֵ��Ϊ nil��
--]]


--��ֵ���
a="hello".."world"
t=.n=t.n+1
--������ͬʱ�����ֵ

a,b=10,2*x;--�ȼ��ڣ�a=10;b=2*x;
--��������ֵ��������ұߵ�ֵȻ��ִ�и�ֵ�������磺
x,u=y,x;--swap'x'for'y'
����������ֵ�ĸ�����һ��ʱ��Lua��һֱ�Ա�������Ϊ������ȡһ�´�ʩ��
a. ��������>ֵ�ĸ���       ��������������nil
b.��������<ֵ�ĸ���        �����ֵ�ᱻ����

--��ֵ��ֵ�������������������򽫺������÷��ظ�����
a,b=f()

--Ӧ�������ܵ�ʹ�þֲ��������������ô�
--1.����������ͻ
--2.���ʾֲ��������ٶȱ�ȫ�ֱ�������






--Lua ѭ��


--���ַ�ʽ  ��
--while ѭ��  for ѭ��
--repeat   until
--ѭ��Ƕ��  ������ѭ��Ƕ����Ƕ��һ������ѭ����䣨while do ....end;  for... do...end;repeat....until;�


--Lua֧��break��䣬�˳���ǰѭ�������



--����ѭ��
while(true)
do
print ("ѭ������")
end;




--[[Lua ���̿���   (����false true  �ж�)
���ƽṹ���������ʽ����������κ�ֵ��Lua��Ϊfalse ��nil Ϊ�٣�true



�ṩ��  �� if ���
			if else  ���
			if Ƕ�����
--]]



--[[  Lua����
�����Ƚ��������Ĵ�С
function max(num1,num2)
if(num1>num2) then
result=num1;
else
result=num2;
end
return result;
end

�ɽ�������Ϊ�������ݸ�����
���Է��ض��������
���Խ��ܿɱ���Ŀ�Ĳ�������C�������ƣ��ڲ����б���ʹ��...��ʾ�����пɱ�Ĳ�����ʵ����

function average(...)
   result = 0
   local arg={...}    --> arg Ϊһ�����ֲ�����
   for i,v in ipairs(arg) do
      result = result + v
   end
   print("�ܹ����� " .. #arg .. " ����")
   return result/#arg
end

print("ƽ��ֵΪ",average(10,5,3,4,5,6))

��ʱ����Ҫ�����ɶ��������Ͽɱ������ע�⣺�̶�����������ڿɱ����֮ǰ
--]]
