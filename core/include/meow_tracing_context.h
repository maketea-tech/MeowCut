#pragma once

namespace Meow {

/**
 * @brief 用于全链路追踪的结构体
 * 每个函数的首个参数都是此结构体的指针，
 * 函数在进入和退出时都往此结构体里写入状态信息，dump时可构成树信息
 * 比如
 * main enter
 *  func1 enter
 *    func2 enter
 *      func3 enter
 *      func3 exit
 *    func2 exit
 *  func1 exit
 *  func3 enter
 *  func3 exit
 * main exit
 * 具体实现方法需要进一步调研
 */
struct MeowTracingContext {
    /**
     * @brief 打印当前追踪的信息
     *
     */
    void Dump();
};

}  // namespace Meow
