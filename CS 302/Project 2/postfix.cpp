#include "Stack.cpp"
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
    Code does not run properly, I was unable to figure out how to deal with the white space associated with reading in the
    expression as well as converting from a char to a float, I would love to know what steps I could have taken in order to
    write the correct code. If possible I would like to meet and discuss the errors, unfortunately I was unable to make it to
    Prof. Keith's office hours as well as yours due to my work schedule.
*/

int main(){
    Stack<char> operatorStack;
    string expression;
    int precedence(const char operation);

    cout << "Enter an expression: ";
    getline(cin,expression);
    char postFixExpression[expression.length()]{' '};
    for(int i = 0;i < expression.length();i++){
        if(expression[i] - '0' >= 0 && expression[i] - '0' <= 9){
            postFixExpression[i] = expression[i];
        }else{
                if(expression[i] == '('){
                    operatorStack.push(expression[i]);
                   }else if(expression[i] == ')'){
                        while(operatorStack.peek() != '('){
                                postFixExpression[i] = operatorStack.peek();
                                operatorStack.pop();
                              }
                              operatorStack.pop();
                   }else{
                        if(!operatorStack.isEmpty()){
                            while(precedence(operatorStack.peek()) >= precedence(expression[i])){
                                postFixExpression[i] = operatorStack.peek();
                                operatorStack.pop();
                            }
                        }
                            operatorStack.push(expression[i]);
                   }
            }
        }
        operatorStack.clear();
        cout << "Postfix Expression: ";
        for(int i = 0;i < expression.length();i++){
            cout << postFixExpression[i];
       }

    float operand1 = 0;
    float operand2 = 0;
    float result = 0;

    for(int i = 0;i < strlen(postFixExpression);i++){
        if(postFixExpression[i] >= 0 && postFixExpression[i] <= 9){
            operatorStack.push(postFixExpression[i]);
        }else{
                operand1 = (float)(operatorStack.peek());
                operatorStack.pop();
                operand2 = (float)(operatorStack.peek());
                operatorStack.pop();
            switch(postFixExpression[i]){
            case '+':
                result = operand2 + operand1;
                operatorStack.push(result);
                break;
            case '-':
                result = operand2 - operand1;
                operatorStack.push(result);
                break;
            case '*':
                result = operand1 * operand2;
                operatorStack.push(result);
                break;
            case  '/':
                result = operand2 / operand1;
                operatorStack.push(result);
                break;
            case '^':
                result = pow(operand2,operand1);
                operatorStack.push(result);
                break;
            }
        }
    }
    result = (float)(operatorStack.peek());
        cout << endl << "Evaluation: " << result;
    }


int precedence(const char operation){
    switch(operation){
            case '+':
            case '-':
                return 1;
                break;
            case '*':
            case '/':
                return 2;
                break;
            case '^':
                return 3;
                break;
            default:
                return -1;
                break;
    }
}

