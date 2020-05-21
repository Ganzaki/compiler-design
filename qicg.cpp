
#include <bits/stdc++.h>
using namespace std;
extern "C" {
    int yylex(void);
    void yyerror(const char *s);
    int yywrap(void);
}
map<string, string> ascii_to_var;
map<string, string> printf_body;
int print_body;
int ascii_counter = 0;
ofstream assembly_file;

#define STR(VAR) (#VAR)
#define release 1
#define MAXCHILD 10

struct SymbolTableTree{
	struct SymbolTableTree *child[MAXCHILD];
    string nodeType;
    string name;
    string value;
    string dataType;
    int lineNo;
    int Nchildren;
    int scope;
    int scopeChildren;
    struct SymbolTableTree *parent;
};
struct ast{
    int Nchildren;
    string str;
    ast *child[MAXCHILD];
};


bool assignrhs = false;
string assignvar = "";
//namespace ksb{
    // template<typename OP, typename ARG1, typename ARG2, typename RES>
    // class Quadruple
    // {

    // public:
    //     OP op;
    //     ARG1 arg1;
    //     ARG2 arg2;
    //     RES result;
    //     Quadruple(OP _op, ARG1 _arg1, ARG2 _arg2, RES _result): op(_op), arg1(_arg1), arg2(_agr2), result(_result){};
    // };

    unsigned int temp_counter = 0;
    unsigned int label_counter = 1;
    std::vector<std::string> stk1;
    std::vector<std::string> stk2;
    class Quadruple
    {

    public:
        std::string op;
        std::string arg1;
        std::string arg2;
        std::string result;
        Quadruple(std::string _op, std::string _arg1, std::string _arg2, std::string _result): op(_op), arg1(_arg1), arg2(_arg2), result(_result){};
    };
    void get_icg_rec(SymbolTableTree *, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);
    std::string get_icg_for_exp(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);
    void get_icg_for_var_def(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);
    void get_icg_for_while(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);
    void get_icg_for_switch_case(SymbolTableTree *node, std::vector<Quadruple> &icg, std::string &tmpv, std::string &label, std::map<string, SymbolTableTree> &mapper);
    void get_icg_for_switch(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);
    void get_icg_for_printf(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper);


    SymbolTableTree *make_new_node(string nodeType, string name, string value, string dataType, int lineNo, SymbolTableTree *parent){
        SymbolTableTree *ttt = new SymbolTableTree;
        ttt -> nodeType = nodeType;
        ttt -> name = name;
        ttt -> value = value;
        ttt -> dataType = dataType;
        ttt -> lineNo = lineNo;
        ttt -> Nchildren = 0;
        ttt -> scope = -1;
        ttt -> scopeChildren = 0;
        ttt -> parent = parent;
        return ttt;
    }

    

    void get_icg_rec(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        // cout<<"lol2\n";
        if(node->nodeType=="Expression"){
            // cout<<"lol3\n";
            get_icg_for_exp(node,icg, mapper);
        }
        else if(node->nodeType=="While"){
            // cout<<"lol4\n";
            get_icg_for_while(node,icg, mapper);
        }
        else if(node->nodeType=="Switch"){
            // cout<<"lol5\n";
            get_icg_for_switch(node,icg, mapper);
        }
        else if(node->nodeType=="VariableDefine"){
            // cout<<"lol6\n";
            get_icg_for_var_def(node,icg, mapper);
        }
        else if(node->nodeType=="Extra_SemiColon"){
            // cout<<"lol7\n";
            return;
        }
        else if(node->nodeType=="Scope2_Continue"){
            // cout<<"lol8\n";
            std::string tmp;
            if(stk1.size()>0) tmp = stk1.back();
            else tmp = stk2.back();
            Quadruple newg("goto", "", "", tmp);
            icg.push_back(newg);
            return;
        }
        else if(node->nodeType=="Scope2_Break"){
            // cout<<"lol9\n";
            Quadruple newg("goto", "", "", stk2.back());
            icg.push_back(newg);
            return;
        }
        else if(node->nodeType=="Main_Scope_Return"){
            // cout<<"lol10\n";
            Quadruple newg("goto", "", "", "l0");
            icg.push_back(newg);
            return;
        }
        else if(node->nodeType == "Print"){
            get_icg_for_printf(node,icg, mapper);
        }
        else{
            for(int i = 0; i < node -> Nchildren; ++i){
                get_icg_rec(node->child[i], icg, mapper);
            }
        }
        
    }

    void get_icg_for_print_inside(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper, int &p){
        if(node->nodeType == "PrintInsider"){
            
            std::string t1 = get_icg_for_exp(node -> child[2], icg, mapper);
            ++p;
            Quadruple newq("Param", t1, "", "");
            icg.push_back(newq);
            get_icg_for_print_inside(node -> child[0], icg, mapper, p);
            return;
        }
        std::string t1 = get_icg_for_exp(node, icg, mapper);
        ++p;
        Quadruple newq("Param", t1, "", "");
        icg.push_back(newq);
    }

    void get_icg_for_printf(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        if(node->Nchildren == 4){
            Quadruple newq("Param", node->value, "", "");
            if(node->value.length()>3 && node->value[0]=='"'){
                printf_body[node->value] = "print_body"+to_string(print_body++);
            }
            icg.push_back(newq);
            Quadruple newq2("call", "printf", "1", "");
            icg.push_back(newq2);
        }
        else {
            
            int p = 1;
            get_icg_for_print_inside(node -> child[3], icg, mapper, p);
            Quadruple newq("Param", node->value, "", "");
            if(node->value.length()>3 && node->value[0]=='"'){
                printf_body[node->value] = "print_body"+to_string(print_body++);
            }
            icg.push_back(newq);
            Quadruple newq2("call", "printf", std::to_string(p), "");
            icg.push_back(newq2);
        }
    }


    std::string do_operation(std::string a, std::string b, std::string optr, std::string dT){
        if(dT=="double" || dT.find("float")!=string::npos){
            char c[100] = "";
            double tt1; double tt2;
            if(a[0]=='\'') tt1 = double(a[1]);
            else  tt1 = std::stof(a);
            if(b[0]=='\'') tt2 = double(b[1]);
            else  tt2 = std::stof(b);
            if(optr == "+") gcvt(tt1 + tt2, 128, c);
            else if(optr == "-") gcvt(tt1 - tt2, 128, c);
            else if(optr == "*") gcvt(tt1 * tt2, 128, c);
            else if(optr == "/") gcvt(tt1 / tt2, 128, c);
            else if(optr == "%") yyerror("% operation on float is illigal \n");
            else if(optr == "||") gcvt(tt1 || tt2, 1, c);
            else if(optr == "&&") gcvt(tt1 && tt2, 1, c);
            else if(optr == ">") gcvt(tt1 > tt2, 1, c);
            else if(optr == "<") gcvt(tt1 < tt2, 1, c);
            else if(optr == "==") gcvt(tt1 == tt2, 1, c);
            else if(optr == "<=") gcvt(tt1 <= tt2, 1, c);
            else if(optr == ">=") gcvt(tt1 >= tt2, 1, c);
            else if(optr == "!=") gcvt(tt1 != tt2, 1, c);
            // cerr<<std::string(c)<<"     blah  "<<optr<<" "<<tt1<<" "<<tt2<<" "<<a<<" "<<b<<" "<<(std::stof("1.5"))<<"\n";
            return std::string(c);
        }
        else if(dT == "char"){
            std::string c = "'x'";
            char tt1; char tt2;
            tt1 = (a[1]);
            
            tt2 = (b[1]);
            
            if(optr == "+") c[2] = tt1 + tt2;
            else if(optr == "-") c[2] = tt1 - tt2;
            else if(optr == "*") c[2] = tt1 * tt2;
            else if(optr == "/") c[2] = tt1 / tt2;
            else if(optr == "%") c[2] = tt1 / tt2;
            else if(optr == "||") return std::to_string(tt1 || tt2);
            else if(optr == "&&") return std::to_string(tt1 && tt2);
            else if(optr == ">") return std::to_string(tt1 > tt2);
            else if(optr == "<") return std::to_string(tt1 < tt2);
            else if(optr == "==") return std::to_string(tt1 == tt2);
            else if(optr == "<=") return std::to_string(tt1 <= tt2);
            else if(optr == ">=") return std::to_string(tt1 >= tt2);
            else if(optr == "!=") return std::to_string(tt1 != tt2);
            return std::string(c);
        }

        long long tt1;
        long long tt2;
        if(a[0]=='\'') tt1 = (long long)(a[1]);
        else  tt1 = std::stoi(a);
        if(b[0]=='\'') tt2 = (long long)(b[1]);
        else  tt2 = std::stoi(b);
        if(optr == "+") return std::to_string(tt1 + tt2);
        else if(optr == "-") return std::to_string(tt1 - tt2);
        else if(optr == "*") return std::to_string(tt1 * tt2);
        else if(optr == "/") return std::to_string(tt1 / tt2);
        else if(optr == "%") return std::to_string(tt1 % tt2);
        else if(optr == "||") return std::to_string(tt1 || tt2);
        else if(optr == "&&") return std::to_string(tt1 && tt2);
        else if(optr == ">") return std::to_string(tt1 > tt2);
        else if(optr == "<") return std::to_string(tt1 < tt2);
        else if(optr == "==") return std::to_string(tt1 == tt2);
        else if(optr == "<=") return std::to_string(tt1 <= tt2);
        else if(optr == ">=") return std::to_string(tt1 >= tt2);
        else if(optr == "!=") return std::to_string(tt1 != tt2);
        return "";
    }


    std::string get_icg_for_exp(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        // cout<<"lol14\n";
        // cout<<"lol15 "<<(node==nullptr)<<"\n";
        if(node -> nodeType == "Expression"){
            if(node->Nchildren > 2) return get_icg_for_exp(node -> child[1], icg, mapper);
            return get_icg_for_exp(node -> child[0], icg, mapper);
        }
        else if(node -> nodeType == "BinaryFOp" || node -> nodeType == "BinarySOp" || node -> nodeType == "RelationalOp" || node -> nodeType == "LogicalOp"){
            assignvar = "none";
            bool flg = false;
            bool flg1 = false;
            bool flg2 = false;
            std::string t2 = get_icg_for_exp(node -> child[0], icg, mapper);
            std::string t3 = get_icg_for_exp(node -> child[2], icg, mapper);
            std::string dT = "";
            if(node -> nodeType == "RelationalOp" || node -> nodeType == "LogicalOp")   dT="int";
            else{ 
                
                if(t2.length()>0){
                    if(t2[0] == '\'') dT = "char";
                    else if(t2[0] >= '0' && t2[0] <= '9'){ 
                        if(find(t2.begin(), t2.end(), '.') != t2.end()) dT = "double";
                        else dT = "long long int";
                    }
                    else if(t2[0] == '-'){
                        if(find(t2.begin(), t2.end(), '.') != t2.end()) dT = "double";
                        else dT = "long long int";
                    }
                    else dT =  mapper[t2].dataType;

                }
                std::string dT2 = "";
                if(t3.length()>0){
                    if(t3[0] == '\'') dT2 = "char";
                    else if(t3[0] >= '0' && t3[0] <= '9'){ 
                        if(find(t3.begin(), t3.end(), '.') != t3.end()) dT = "double";
                        else dT2 = "long long int";
                    }
                    else if(t3[0] == '-'){
                        if(find(t3.begin(), t3.end(), '.') != t3.end()) dT = "double";
                        else dT2 = "long long int";
                    }
                    else dT2 =  mapper[t3].dataType;

                }
                if(dT2 == "double" || dT2.find("float")!=string::npos || dT == "char") dT = dT2;
                
            
        
            }
            if(t2.length()>0 && ((t2[0] == '\'') || ((t2[0] >= '0' && t2[0] <= '9')) || (t2[0] == '-'))) flg1 = true;
            if(t3.length()>0 && ((t3[0] == '\'') || ((t3[0] >= '0' && t3[0] <= '9')) || (t3[0] == '-'))) flg2 = true;
            flg = flg1 && flg2;
            if(flg){
                
                std::string optr= node->child[1]->value;
                return do_operation(t2, t3, optr, dT);

            }
            else{
                if(node -> nodeType == "BinaryFOp"){
                    if(flg1 && t2[0]!='\'' && std::stof(t2) == 0){
                        return t3;
                    }
                    else if(flg2 && t3[0]!='\'' && std::stof(t3) == 0){
                        return t2;
                    }
                }
                else if( node -> nodeType == "BinarySOp"){
                    if(flg1 && t2[0]!='\'' && std::stof(t2) == 1){
                        return t3;
                    }
                    else if(flg2 && t3[0]!='\'' && std::stof(t3) == 1){
                        return t2;
                    }
                    else if(flg1 && t2[0]!='\'' && std::stof(t2) == 0 && node->child[1]->value=="*"){
                        return "0";
                    }
                    else if(flg2 && t3[0]!='\'' && std::stof(t3) == 0 && node->child[1]->value=="*"){
                        return "0";
                    }
                }
                std::string t1 = "t"+std::to_string(temp_counter++);
                
                mapper[t1] = *make_new_node("TempVariable", t1, "", dT, -1, node);
                
                Quadruple newq(node->child[1]->value, t2, t3, t1);
                icg.push_back(newq);
                
                return t1;
            }
        }
        else if(node->nodeType == "Value"){
            // cout<<"lol15\n";
            // std::string t1 = "t"+std::to_string(temp_counter++);
            // mapper[t1] = *make_new_node("TempVariable", t1, node -> value, node->dataType, -1, node);
            // Quadruple newq("=", node -> value, "", t1);
            // icg.push_back(newq);
            if(node->dataType == "char"){
                ascii_to_var[node -> value] = "lol"+to_string(ascii_counter++);
            }
            return node -> value;
        }
        else if( node->nodeType == "Identifier" ){
            if(assignvar == node->name){
                std::string t1 = "t"+std::to_string(temp_counter++);
                mapper[t1] = *make_new_node("TempVariable", t1, node -> value, node->dataType, -1, node);
                Quadruple newq("=", node -> name, "", t1);
                icg.push_back(newq);
                return t1;
            }
            return node->name;
        }
        else if( node->nodeType == "Unary" )
        {
            std::string t1 = "t"+std::to_string(temp_counter++);
            if(node -> child[0] -> nodeType == "BinaryFOp"){
                std::string t2 = get_icg_for_exp(node -> child[1], icg, mapper);
                if((t2[0]=='_') || (t2[0]>='a' && t2[0]<='z') || (t2[0]>='A' && t2[0]<='Z'))
                    mapper[t1] = *make_new_node("TempVariable", t1, "", mapper[t2].dataType, -1, node);
                else{
                    if(t2[0] == '\'' )
                        mapper[t1] = *make_new_node("TempVariable", t1, "", "char", -1, node);
                    else if(std::find(t2.begin(), t2.end(),'.')!=t2.end())
                        mapper[t1] = *make_new_node("TempVariable", t1, "", "double", -1, node);
                    else
                        mapper[t1] = *make_new_node("TempVariable", t1, "", "long long int", -1, node);
                }
                Quadruple newq(node -> child[0] -> value, t2, "", t1);
                icg.push_back(newq);
                return t1;
            }
            if(node -> child[0] -> nodeType == "UnaryOp"){
                string prevv = assignvar;
                assignvar = node->child[1]->name;
                bool prev = assignrhs;
                if(!prev) assignrhs = true;
                std::string t2 = get_icg_for_exp(node -> child[1], icg, mapper);
                assignvar = prev;
                if(!prev) assignrhs = false;
                if(node ->child[0] -> value == "!"){
                    std::string vval = get_icg_for_exp(node->child[1], icg, mapper);
                    Quadruple newq2("!", vval, "", t1);
                    mapper[t1] = *make_new_node("TempVariable", t1, "", "int", -1, node);
                    icg.push_back(newq2);
                }
                else if(node ->child[0] -> value == "--"){
                    Quadruple newq("-", t2, "1", node->child[1]->name);
                    icg.push_back(newq);

                    Quadruple newq2("=", node->child[1]->name, "", t1);
                    mapper[t1] = *make_new_node("TempVariable", t1, node ->child[1]-> value, node->child[1]->dataType, -1, node);
                    icg.push_back(newq2);
                }
                else{
                    Quadruple newq("+", t2, "1", node->child[1]->name);
                    icg.push_back(newq);

                    Quadruple newq2("=", node->child[1]->name, "", t1);
                    mapper[t1] = *make_new_node("TempVariable", t1, node ->child[1]-> value, node->child[1]->dataType, -1, node);
                    icg.push_back(newq2);
                }

                return t1;
            }
            string prevv = assignvar;
            assignvar = node->child[0]->name;
            bool prev = assignrhs;
            if(!prev) assignrhs = true;
            std::string t2 = get_icg_for_exp(node -> child[0], icg, mapper);
            assignvar = prev;
            if(!prev) assignrhs = false;
            if(node ->child[1] -> value == "--"){
                Quadruple newq2("=", node->child[0]->name, "", t1);
                mapper[t1] = *make_new_node("TempVariable", t1, node ->child[0]-> value, node->child[0]->dataType, -1, node);
                icg.push_back(newq2);

                Quadruple newq("-", t2, "1", node->child[0]->name);
                icg.push_back(newq);
            }
            else{
                Quadruple newq2("=", node->child[0]->name, "", t1);
                mapper[t1] = *make_new_node("TempVariable", t1, node ->child[0]-> value, node->child[0]->dataType, -1, node);
                icg.push_back(newq2);

                Quadruple newq("+", t2, "1", node->child[0]->name);
                icg.push_back(newq);
            }
            return t1;
        }

        else if(node -> nodeType == "Assign"){
            string prevv = assignvar;
            assignvar = node->child[0]->name;
            bool prev = assignrhs;
            std::string t1 = "";
            if(!prev) assignrhs = true;
            std::string t2 = get_icg_for_exp(node->child[2], icg, mapper);
            assignvar = prev;
            if(!prev) assignrhs = false;
            if(assignrhs) t1 = "t"+std::to_string(temp_counter++);
            else t1 = node->child[0]->name;
            if(node -> child[1] ->nodeType =="AssignInOp"){
                Quadruple newq2("=", t2, "", node->child[0]->name);
                icg.push_back(newq2);
                if(assignrhs){
                    Quadruple newq3("=", node->child[0]->name, "", t1);
                    icg.push_back(newq3);
                    mapper[t1] = *make_new_node("TempVariable", t1, node -> child[0]->value, node->child[0]->dataType, -1, node);
                }
                return t1;
            }
            else if(node -> child[1] ->nodeType =="AssignOp"){
                auto t3 = t1 = "t"+std::to_string(temp_counter++);
                mapper[t3] = *make_new_node("TempVariable", t3, node -> child[0]->value, node->child[0]->dataType, -1, node);
                string op = "";
                op.push_back(node->child[1]->value[0]);
                Quadruple newq3(op, node->child[0]->name, t2, t3);
                Quadruple newq2("=", t3, "", node->child[0]->name);
                icg.push_back(newq3);
                icg.push_back(newq2);
                if(assignrhs){
                    Quadruple newq3("=", node->child[0]->name, "", t1);
                    icg.push_back(newq3);
                    mapper[t1] = *make_new_node("TempVariable", t1, node -> child[0]->value, node->child[0]->dataType, -1, node);
                }
                return t1;
            }
            else{
                std::string t3 = t2;
                if(t2.length()>0 && t2[0]!='\'' && !(t2[0]>='0' && t2[0]<='9') && t2[0]!='-'){
                    t3 = "t"+std::to_string(temp_counter++);
                    Quadruple newq2("=", t2, "", t3);
                    icg.push_back(newq2);
                    
                    mapper[t3] = *make_new_node("TempVariable", t3, node -> child[0]->value, node->child[0]->dataType, -1, node);
                }
                
                Quadruple newq4(std::string(node -> child[1] ->value.begin(), node -> child[1] ->value.begin()+1), t3, "", node->child[0]->name);
                icg.push_back(newq4);
                if(assignrhs){
                    Quadruple newq3("=", node->child[0]->name, "", t1);
                    mapper[t1] = *make_new_node("TempVariable", t1, node -> child[0]->value, node->child[0]->dataType, -1, node);
                    icg.push_back(newq3);
                }
            }
            return t1;
        }

        return "";
        
    }

    void get_icg_for_var_def(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        if (node->Nchildren == 3 && node -> child[0]-> nodeType == "TypeName"){
            // cout<<"lol11\n";
            // cout<<(node->Nchildren)<<"\n";
            get_icg_for_var_def(node->child[1], icg, mapper);
            // cout<<"lol100\n";
            return;
        }
        if(node->Nchildren == 3){
            if(node->child[1]->nodeType=="Comma"){
                get_icg_for_var_def(node->child[2], icg, mapper);
                return;
            }
            // cout<<"lol12\n";
            std::string tmpv = get_icg_for_exp(node -> child[2], icg, mapper);
            Quadruple newq("=", tmpv, "", node->child[0]->name);
            icg.push_back(newq);
        }
        else if(node->Nchildren == 5){
            std::string tmpv = get_icg_for_exp(node -> child[2], icg, mapper);
            Quadruple newq("=", tmpv, "", node->child[0]->name);
            icg.push_back(newq);
            get_icg_for_var_def(node->child[4], icg, mapper);
        }
        // cout<<"lol200\n";
    }

    void get_icg_for_while(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        auto l1 = "l"+std::to_string(label_counter++);
        auto l2 = "l"+std::to_string(label_counter++);
        stk1.push_back(l1);
        stk2.push_back(l2);
        Quadruple newl("Label", "", "", l1);
        icg.push_back(newl);
        std::string tmpv = get_icg_for_exp(node -> child[0] -> child[2], icg, mapper);
        
        
        Quadruple newq("ifFalse", tmpv, "", l2);
        
        icg.push_back(newq);
        if(node -> Nchildren == 2) {get_icg_rec(node->child[1], icg, mapper);
            Quadruple newg("goto", "", "", l1);
            icg.push_back(newg);
        }"l"+std::to_string(label_counter++);
        Quadruple newl2("Label", "", "", l2);
        icg.push_back(newl2);
        stk1.pop_back();
        stk2.pop_back();
    }

    void get_icg_for_switch_case(SymbolTableTree *node, std::vector<Quadruple> &icg, std::string &tmpv, std::string &label, std::map<string, SymbolTableTree> &mapper){
        if(node -> Nchildren < 2) return;
        if(node -> child[0] -> Nchildren > 2){
            std::string tmpv2 = get_icg_for_exp(node -> child[0] -> child[1], icg, mapper);
            std::string tmpv3 = "t"+std::to_string(temp_counter++);
            mapper[tmpv3] = *make_new_node("TempVariable", tmpv3, "0", "int", -1, node);
            auto l1 = "l"+std::to_string(label_counter++);
            auto l2 = "l"+std::to_string(label_counter++);
            Quadruple newc("==", tmpv2, tmpv, tmpv3);
            icg.push_back(newc);
            Quadruple newq("ifFalse", tmpv3, "", l1);
            icg.push_back(newq);
            if(label.length() > 1){
                Quadruple newl("Label", "", "", label);
                icg.push_back(newl);
            }
            get_icg_rec(node->child[1], icg, mapper);
            Quadruple newg("goto", "", "", l2);
            icg.push_back(newg);
            Quadruple newl("Label", "", "", l1);
            icg.push_back(newl);
            get_icg_for_switch_case(node -> child[2], icg, tmpv, l2, mapper);
            return;
        }
        if(label.length() > 1){
            Quadruple newl("Label", "", "", label);
            icg.push_back(newl);
        }
        get_icg_rec(node->child[1], icg, mapper);
        std::string l2 = stk2.back();
        Quadruple newg("goto", "", "", l2);
        icg.push_back(newg);
        get_icg_for_switch_case(node -> child[2], icg, tmpv, l2, mapper);
    }

    void get_icg_for_switch(SymbolTableTree *node, std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
        std::string tmpv = get_icg_for_exp(node -> child[0] -> child[2], icg, mapper);
        auto l2 = "l"+std::to_string(label_counter++);
        stk2.push_back(l2);
        std::string tmplabel = "";
        get_icg_for_switch_case(node->child[2], icg, tmpv, tmplabel, mapper);
        Quadruple newl2("Label", "", "", l2);
        icg.push_back(newl2);
        stk2.pop_back();
    }

    std::vector<Quadruple> &get_icg(SymbolTableTree *node, std::map<string, SymbolTableTree> &mapper){
        std::vector<Quadruple> *icg = new std::vector<Quadruple>;
        // cout<<"\n\n\nlol0\n";
        get_icg_rec(node, *icg, mapper);
        // cout<<"lol1\n";
        Quadruple newl2("Label", "", "", "l0");
        icg->push_back(newl2);
        return *icg;
    }
    
//}
