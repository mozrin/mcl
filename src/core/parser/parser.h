#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <memory>
#include "../lexer/lexer.h"
#include "../parser/ast.h"
#include "../common/token.h"

class Parser
{
private:
    Lexer &lexer;
    Token currentToken;

    void advance();
    void consume(TokenType type);
    TokenType consumeTypeKeyword();
    std::string consumeIdentifier();

    std::unique_ptr<ASTNode> parsePrimaryExpression();
    std::unique_ptr<ASTNode> parseCall();
    std::unique_ptr<ASTNode> parseUnary();
    std::unique_ptr<ASTNode> parseFactor();
    std::unique_ptr<ASTNode> parseTerm();
    std::unique_ptr<ASTNode> parseComparison();
    std::unique_ptr<ASTNode> parseEquality();
    std::unique_ptr<ASTNode> parseBitwiseOr();
    std::unique_ptr<ASTNode> parseLogicalAnd();
    std::unique_ptr<ASTNode> parseLogicalOr();
    std::unique_ptr<ASTNode> parseConcatenation();
    std::unique_ptr<ASTNode> parseExpression();

    std::unique_ptr<EchoStatement> parseEchoStatement();
    std::unique_ptr<DeclarationStatement> parsePublicDeclarationStatement();
    std::unique_ptr<DeclarationStatement> parseLocalDeclarationStatement();
    std::unique_ptr<ReturnStatement> parseReturnStatement();
    std::unique_ptr<BlockStatement> parseBlock();
    std::vector<ParameterDeclaration> parseParameterList();
    std::unique_ptr<FunctionDeclaration> parseFunctionDeclaration();

    std::unique_ptr<ASTNode> parseStatement();
    std::unique_ptr<ASTNode> parseTopLevelStatement();

public:
    Parser(Lexer &lexer);

    std::unique_ptr<ProgramNode> parseProgram();
};

#endif