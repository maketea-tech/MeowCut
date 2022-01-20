[TOC]

# 代码规范(参考Google C++ Style)
## 头文件
1. 文件命名
   **文件名采用“类名全小写，以下划线分割”**
   如：
	> 类名: `TestClass`
	> 文件名： `test_class.h`
2. 重复包含保护
   **所有头文件都应该有 #define 保护来防止头文件被多重包含**
   **命名格式当是:`<PROJECT>_<PATH>_<FILE>_H_`**
   如：
   > 项目`foo`中文件`foo/src/bar/baz.h`
   > 对应为`FOO_BAR_BAZ_H`
3. include规则
   - STL库直接使用`#include`包含
   - 头文件中，其他对象优先使用前置声明，而非`#include`
     - 三种必须使用`#include`的情景：**继承自其他类、含有其他类的实例、头文件中调用了其他类的某个函数**
   - 包含项目中的其他文件，使用相对项目源代码目录的全路径，避免使用"."或者".."
   - 包含顺序：系统头文件、STL库头文件、项目头文件
   - 条件编译可以放到其他includes后
   如： 工程树为`project/src/foo/internal/fooserver.cc`
    ```C++
	#include "foo/public/fooserver.h"

	#include <sys/types.h>
	#include <unistd.h>

	#include <hash_map>
	#include <vector>

	#include "base/basictypes.h"
	#include "base/commandlineflags.h"
	#include "foo/public/bar.h"
	```
5. 命名空间
	```C++
	// .h 文件
	namespace mynamespace {

	// 所有声明都置于命名空间中
	// 注意不要使用缩进
	class MyClass {
		public:
		...
		void Foo();
	};

	} // namespace mynamespace 记得此处注释
	```
6. 声明顺序
	1. typedefs && enums
	2. 常量
	3. 构造函数
	4. 析构函数
	5. 成员函数
	6. 成员变量
	（参考示例看当前部分末尾）
7. 缩进
   - 命名空间、类关键词 无缩进
   - 访问限定符 1空格缩进
   - typedef/enum/其他成员 2缩进
   - 枚举值  2缩进(相对enum关键字)
8. 命名<span id="naming_rules"></span>
   - 类型名(class/typedef/enum)  : 大小写混合、首字母大写
   - 普通(成员)函数命名：首字母大写、大小写混合
   - 存取函数命名：字母全小写、下划线分割(set_varname/get_varname)
   - 变量名： 字母全小写、下划线分割
   - 成员变量名： 字母全小写、下划线分割、**下划线结尾**
   - 常量名： 小写k开头，大小写混合
9.  内联函数
   - 不要超过10行，尽量不要有循环
10. 注释
   - 保护宏结尾加注释
   - 其他（参见注释部分）
11. 参考[https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/]
	```C++
	#ifndef PROJECT_EVENTLOOP_H
	#define PROJECT_EVENTLOOP_H
	
	class Channel;

	namespace mynamespace{

	class EventLoop : public CallbackInterface{
	>public:
	>>typedef vector<int> IntVector;
	>>enum UrlTableErrors{
	>>>>ERROR_OUT_OF_MEMORY = 0,
	>>>>ERROR_MALFORMED_INPUT,
	>>};
	>>explicit EventLoop(const int x);
	>>~EventLoop();

	>>void Add(const std::string& input, Channel* output);
	>>int num_entries() const {return num_entries_;}
	>>void set_num_entries() {num_entries_ = num_entries;}

	>private:
	>>DISALLOW_COPY_AND_ASSIGN(EventLoop);

	>>const int kDaysInWeek = 7;
	>>int num_entries_;
	>>int num_completed_connections_;

	>>Channel* channel_;
	};
	
	}
	#endif // PROJECT_EVENTLOOP_H
	```



## **实现文件 .cc**
### **文件命名**
文件名全部小写,以下划线(`_`)进行连接
C++文件以 `.cc`结尾
尽量让文件名更加明确
例如`http_server_logs.cc` 比 `logs.c`更好
文件名一般成对出现`foo_bar.h`和 `foo_bar.cc`, 对应于类`FooBar`.
### **include顺序**
1. 本类的声明
2. C系统文件
3. C++系统文件
4. 其他库头文件
5. 本项目内头文件(避免使用UNIX文件路径".", "..")
```
如： 工程树为`project/src/foo/internal/fooserver.cc`

// 不要使用UNIX文件路径".", ".."
#include "foo/public/fooserver.h"  

#include <sys/types.h>
#include <unistd.h>

#include <hash_map>
#include <vector>

#include "base/basictypes.h"
#include "base/commandlineflags.h"
#include "foo/public/bar.h"
```
### **命名空间和using的使用**
禁止使用using namespace xxx污染命名空间
```
// 禁止 会污染命名空间
using namespace foo;
```
可以在整个cc文件和h文件的方法内使用using
```
using std::string
```
[在命名空间的最后注释出命名空间的名字。](#comment_namespace)

### **初始化列表格式**
多行初始化列表， `:`前4空格缩进, 以`,`结尾
多个变量折行对齐
```
EventLoop::EventLoop()
    : _var1_(10)
      _var2_(false) {
  ...
}
```
单行初始化列表
```
Class::Class() : _var(xx) {
  ...
}
```
构造函数中只进行那些没有实际意义的初始化
### **函数参数格式**
#### **函数定义**
返回类型和函数名在同一行, 参数也尽量放在同一行, 如果放不下就对形参分行
```
ReturnType ClassName::FunctionName(Type par_name1, Type par_name2) {
  DoSomething();
  ...
}
```
```
ReturnType ClassName::ReallyLongFunctionName(Type par_name1, Type par_name2,
                                             Type par_name3) {
  DoSomething();
  ...
}
```
```
ReturnType LongClassName::ReallyReallyReallyLongFunctionName(
    Type par_name1,  // 4 space indent
    Type par_name2,
    Type par_name3) {
  DoSomething();  // 2 space indent
  ...
}
```
#### **函数调用**
要么一行写完函数调用, 要么在圆括号里对参数分行, 要么参数另起一行且缩进四格. 如果没有其它顾虑的话, 尽可能精简行数, 比如把多个参数适当地放在同一行里.
```
bool retval = DoSomething(argument1, argument2, argument3);
```
如果同一行放不下, 可断为多行, 后面每一行都和第一个实参对齐, 左圆括号后和右圆括号前不要留空格：
```
bool retval = DoSomething(averyveryveryverylongargument1,
                          argument2, argument3);
```
参数也可以放在次行, 缩进四格：
```
if (...) {
  ...
  ...
  if (...) {
    DoSomething(
        argument1, argument2,  // 4 空格缩进
        argument3, argument4);
  }
```
### **条件语句格式**
圆括号内无括号
(condition)左右1空格
if执行体2空格缩进
大括号与else同行
else左右1空格
```
if (condition) {  // 圆括号里没有空格.
  ...  // 2 空格缩进.
} else if (...) {  // else 与 if 的右括号同一行.
  ...
} else {
  ...
}
```
如果能增强可读性, 简短的条件语句允许写在同一行. 只有当语句简单并且没有使用`else`子句时使用:
```
if (x == kFoo) return new Foo();
if (x == kBar) return new Bar();
```

条件变量过多时，条件运算符 && 结尾 条件左对齐
```
if (this_one_thing < this_other_thing) &&
    a_third_thing == a_fourth_thing {
}
```
### **循环语句格式**
```
for (int i = 0; i < kSomeNumber; ++i)
  printf("I love you\n");

for (int i = 0; i < kSomeNumber; ++i) {
  printf("I take it back\n");
}
```
空循环体应使用`{}`或`continue`, 而不是一个简单的分号.
```
while (condition) {
  // 反复循环直到条件失效.
}
for (int i = 0; i < kSomeNumber; ++i) {}  // 可 - 空循环体.
while (condition) continue;  // 可 - contunue 表明没有逻辑.
```
### **switch语句格式**
使用大括号分段, 以表明 cases 之间不是连在一起的
空循环体应使用`{}`
如果有不满足`case`条件的枚举值,`switch`该总是包含一个`default`匹配
如果`default`应该永远执行不到, 简单的加条`assert`
(var)左右各1空格
条件相对switch   2空格缩进
执行体相对switch 4空格缩进
```
switch (var) {
  case 0: {  // 2 空格缩进
    ...      // 4 空格缩进
    break;
  }
  case 1: {
    ...
    break;
  }
  default: {
    assert(false);
  }
}
```
### **函数返回值格式**
```
return result;                  // 返回值很简单, 没有圆括号.
// 可以用圆括号把复杂表达式圈起来, 改善可读性.
return (some_long_condition &&
        another_condition);
```
### **注释**
#### **注释风格**
`//` 或 `/* */` 都可以; 但 `//` 更 常用. 要在如何注释及注释风格上确保统一.

#### **文件注释**
版权
许可证， BSD/GPL/MIT/...
作者
文件内容简短说明
```
// Copyright 2009 Google Inc.
// License(BSD/GPL/...)
// Author: xxx
// This is ...
```

#### **类注释**
每个类的定义都要附带一份注释, 描述类的功能和用法, 除非它的功能相当明显.
```
// Iterates over the contents of a GargantuanTable.
// Example:
//    GargantuanTableIterator* iter = table->NewIterator();
//    for (iter->Seek("foo"); !iter->done(); iter->Next()) {
//      process(iter->key(), iter->value());
//    }
//    delete iter;
class GargantuanTableIterator {
  ...
};
```

#### **函数注释**
函数的输入输出.
对类成员函数而言: 函数调用期间对象是否需要保持引用参数, 是否会释放这些参数.
函数是否分配了必须由调用者释放的空间.
参数是否可以为空指针.
是否存在函数使用上的性能隐患.
如果函数是可重入的, 其同步前提是什么?
```
// Returns an iterator for this table.  It is the client's
// responsibility to delete the iterator when it is done with it,
// and it must not use the iterator once the GargantuanTable object
// on which the iterator was created has been deleted.
//
// The iterator is initially positioned at the beginning of the table.
//
// This method is equivalent to:
//    Iterator* iter = table->NewIterator();
//    iter->Seek("");
//    return iter;
// If you are going to immediately seek to another place in the
// returned iterator, it will be faster to use NewIterator()
// and avoid the extra seek.
Iterator* GetIterator() const;
```

#### **TODO注释**
临时方案使用TODO(大写)注释,
后面括号里加上名称，邮件地址
```
// TODO(name@abc.com): xxx
```
#### **命名空间** <span id="comment_namespace"></span>
命名空间结束注释
```
namespace mynamespace {
  ...
}  // namespace mynamespace
```


### **命名规则**
[详见](#naming_rules)

### **注意事项**

 - 尽量不使用宏
 - 不使用异常
 - 禁止使用RTTI
 - 使用printf之类的代替流
 - 除位域不使用无符号数字
 - 除特定环境，不使用操作符重载
 - 使用4种cast运算符类型转换
 - 禁止使用class类型全局变量，若使用必须为单例模式
 - sizeof(var)代替sizeof(type)
 - scoped_ptr可以胜任智能指针
 - 特殊情况下可用shared_ptr
 - 任何时候都不使用auto_ptr

### **编译器，编辑器，QT版本**

---

**QT版本**： 5.15.2
**编译器**： 

 - Linux：   GCC 9.3.0 
 - windows： MinGW 8.1.0 64-bit

**编辑器**： 各自喜好/visual studio 15或以上版本


### **参考**
[Google开源项目风格指南][1]
 


  [1]: https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/