#include<iostream>
#include<map>
#include<stack>
#include<string>
#include<cmath>
using namespace std;

double compute(string& formula, map<char, double>& value_table){
    // 中缀表达式转为后缀表达式(存在new_formula中)
    stack<char> helper;
    string new_formula;
    int size = formula.size();
    for(int i = 0; i < size; ++i){ 
        if(formula[i] >= 'a' && formula[i] <= 'z'){
            new_formula.push_back(formula[i]);
        }
        else if(formula[i] == '(')  helper.push(formula[i]);
        else if(formula[i] == ')'){
            while(helper.top() != '('){
                new_formula.push_back(helper.top());
                helper.pop();
            }
            helper.pop(); // 将 "(" 弹出
        }
        else if(formula[i] == '+' || formula[i] == '-'){
            if(helper.empty() || helper.top() == '(') helper.push(formula[i]);
            else{
                new_formula.push_back(helper.top());
                helper.pop();
                --i;
            }
        }
        else if(formula[i] == '*' || formula[i] == '/'){
            if(helper.empty() || helper.top() == '(' || helper.top() == '+' || helper.top() == '-') helper.push(formula[i]);
            else{
                new_formula.push_back(helper.top());
                helper.pop();
                --i;
            }
        }
    }
    while(!helper.empty()){
        new_formula.push_back(helper.top());
        helper.pop();
    }

    // 通过后缀表达式计算结果
    size = new_formula.size();
    stack<double> help;
    for(int i = 0; i < size; ++i){
        if(new_formula[i] >= 'a' && new_formula[i] <= 'z')
            help.push(value_table[new_formula[i]]);
        else if(new_formula[i] == '+'){
            double res = help.top();
            help.pop();
            res += help.top();
            help.pop();
            help.push(res);
        }
        else if(new_formula[i] == '-'){
            double res = help.top();
            help.pop();
            res = help.top()-res;
            help.pop();
            help.push(res);
        }
        else if(new_formula[i] == '*'){
            double res = help.top();
            help.pop();
            res *= help.top();
            help.pop();
            help.push(res);
        }
        else if(new_formula[i] == '/'){
            double res = help.top();
            help.pop();
            if(res) res = help.top()/res;
            else return NAN;
            help.pop();
            help.push(res);
        }
    }
    return help.top();
}


int main(){
    cout << "输入格式: a*(b+c),a=5,b=4,c=1" << endl;
    cout << "目前仅支持: 加+ 减- 乘* 除/" << endl; 
    string str, formula;
    cin >> str;
    map<char, double> value_table;

    int i = 0, size = str.size();
    for(; i < size && str[i] != ','; ++i)
        formula.push_back(str[i]);
    
    while(i < size){
        char key; double value = 0;
        if(str[i] == ','){      
            if(i + 1 < size)  key = str[i+1];
            if(i + 2 < size && str[i+2] == '='){
                int j = i + 3;
                while(j < size && str[j] != ','){
                    value = value * 10 + (str[j] - 48);
                    ++j;
                }
                i = j;
            }
            value_table[key] = value;
        }
    }
    double res = compute(formula, value_table);
    cout << "计算结果为:" << res << endl;
    system("pause");
}