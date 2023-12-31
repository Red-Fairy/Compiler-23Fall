#include <iostream>
#include <memory>
#include <string>

// 所有 AST 的基类
class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void Dump() const = 0;
};

// CompUnit 是 BaseAST
class CompUnitAST : public BaseAST
{
public:
    // 用智能指针管理对象
    std::unique_ptr<BaseAST> func_def;
    void Dump() const override {
        func_def->Dump();
        // std::cout << "fun "
        // std::cout << "CompUnitAST { ";
        // func_def->Dump();
        // std::cout << " }";
    }
};

// FuncDef 也是 BaseAST
class FuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;
    void Dump() const override {
        std::cout << "fun @" << ident << "(): ";
        func_type->Dump();
        block->Dump();
        // std::cout << "FuncDefAST { ";
        // func_type->Dump();
        // std::cout << ", " << ident << ", ";
        // block->Dump();
        // std::cout << " }";
    }
};

class FuncTypeAST : public BaseAST
{
public:
    std::unique_ptr<std::string> ret_type;
    void Dump() const override {
        // std::cout << "FuncTypeAST { ";
        std::cout << *ret_type;
        // std::cout << " }";
    }
};

class BlockAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> stmt;
    void Dump() const override {
        std::cout << " { \n";
        std::cout << "%entry:\n";
        stmt->Dump();
        std::cout << " }\n";
    }
};

class StmtAST : public BaseAST
{
public:
    std::unique_ptr<std::string> number;
    void Dump() const override {
        std::cout << "\tret " << *number << "\n";
        // std::cout << "StmtAST { ";
        // std::cout << *number;
        // std::cout << " }";
    }
};
