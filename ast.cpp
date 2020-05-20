
#ifndef QICG
#define QICG 1
#include "qicg"
#endif


std::map<string, int> mmm;
std::vector<int> switch_stack;
ofstream ast_out;
streampos oldpos;
void print_ast(SymbolTableTree *);
void print_ast_for_exp(SymbolTableTree *);
void print_ast_for_var_def(SymbolTableTree *);
void print_ast_for_while(SymbolTableTree *);
void print_ast_for_switch_case(SymbolTableTree *);
void print_ast_for_switch(SymbolTableTree *);
void print_ast_for_printf(SymbolTableTree *);





void print_ast_for_print_inside(SymbolTableTree *node){
    if(node->nodeType == "PrintInsider"){
        int nu = mmm[("printf")];
        print_ast_for_exp(node -> child[2]);
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_print_inside(node -> child[0]);
        return;
    }
    print_ast_for_exp(node);
}

void print_ast_for_printf(SymbolTableTree *node){
    if(node->Nchildren == 4){
        int nu = mmm[("printf")];
        ++mmm[("printf")];
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"`";
        int nm = mmm[(node->value)];
        ++mmm[(node->value)];
        ast_out<<(node->value)<<"("<<std::to_string(nm)<<")"<<"\n";
    }
    else {
        int nu = mmm[("printf")];
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"`";
        int nm = mmm[(node->value)];
        ++mmm[(node->value)];
        print_ast_for_print_inside(node -> child[3]);
        ++mmm[("printf")];
        ast_out<<("printf")<<"("<<std::to_string(nu)<<")"<<"`";
        ast_out<<(node->value)<<"("<<std::to_string(nm)<<")"<<"\n";
        
    }
}



void print_ast_for_exp(SymbolTableTree *node){
    // cout<<"lol14\n";
    // cout<<"lol15 "<<(node==nullptr)<<"\n";
    if(node -> nodeType == "Expression"){
        int nu = mmm[(node -> nodeType)];
        ++mmm[(node -> nodeType)];
        ast_out<<(node -> nodeType)<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<(node -> nodeType)<<"("<<std::to_string(nu)<<")"<<"`";
        if(node->Nchildren > 2)  print_ast_for_exp(node -> child[1]);
        else print_ast_for_exp(node -> child[0]);
    }
    else if(node -> nodeType == "BinaryFOp" || node -> nodeType == "BinarySOp" || node -> nodeType == "RelationalOp" || node -> nodeType == "LogicalOp"){
        if(node -> Nchildren == 3){
            int nu = mmm[(node -> child[1] -> value)];
            ++mmm[(node -> child[1] -> value)];
            ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
            ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
            print_ast_for_exp(node -> child[0]);
            ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
            print_ast_for_exp(node -> child[2]);
        }
    }
    else if(node->nodeType == "Value"){
        int nu = mmm[(node -> value)];
        ++mmm[(node -> value)];
        ast_out<<(node -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
    }
    else if( node->nodeType == "Identifier" ){
        int nu = mmm[(node -> name)];
        ++mmm[(node -> name)];
        ast_out<<(node -> name)<<"("<<std::to_string(nu)<<")"<<"\n";
    }
    else if( node->nodeType == "Unary" )
    {
        std::string t1 = "t"+std::to_string(temp_counter++);
        if(node -> child[0] -> nodeType == "BinaryFOp"){
            int nu = mmm[(node -> child[0] -> value)];
            ++mmm[(node -> child[0] -> value)];
            ast_out<<(node -> child[0] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
            ast_out<<(node -> child[0] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
            print_ast_for_exp(node -> child[1]);
            
        }
        else if(node -> child[0] -> nodeType == "UnaryOp"){
            int nu = mmm[(node -> child[0] -> value)];
            ++mmm[(node -> child[0] -> value)];
            ast_out<<(node -> child[0] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
            ast_out<<(node -> child[0] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
            print_ast_for_exp(node -> child[1]);
            return ;
        }
        int nu = mmm[(node -> child[1] -> value)];
        ++mmm[(node -> child[1] -> value)];
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[0]);
    }

    else if(node -> nodeType == "Assign"){
        int nu = mmm[(node -> child[1] -> value)];
        ++mmm[(node -> child[1] -> value)];
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[0]);
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[2]);
    }
    
}

void print_ast_for_var_def(SymbolTableTree *node){
    if (node->Nchildren == 3 && node -> child[0]-> nodeType == "TypeName"){
        print_ast_for_var_def(node->child[1]);
        return;
    }
    if(node->Nchildren == 3){
        if(node->child[1]->nodeType=="Comma"){
            print_ast_for_var_def(node->child[2]);
            return;
        }
        int nu = mmm[(node -> child[1] -> value)];
        ++mmm[(node -> child[1] -> value)];
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[0]);
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[2]);
    }
    else if(node->Nchildren == 5){
        int nu = mmm[(node -> child[1] -> value)];
        ++mmm[(node -> child[1] -> value)];
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"\n";
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[0]);
        ast_out<<(node -> child[1] -> value)<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast_for_exp(node -> child[2]);
        print_ast_for_var_def(node->child[4]);
    }
}

void print_ast_for_while(SymbolTableTree *node){
    int nu = mmm[("while")];
    ++mmm[("while")];
    ast_out<<("while")<<"("<<std::to_string(nu)<<")"<<"\n";
    ast_out<<("while")<<"("<<std::to_string(nu)<<")"<<"`";
    int nm = mmm[("cmp")];
    ++mmm[("cmp")];
    ast_out<<("cmp")<<"("<<std::to_string(nm)<<")"<<"\n";
    ast_out<<("cmp")<<"("<<std::to_string(nm)<<")"<<"`";
    print_ast_for_exp(node -> child[0] -> child[2]);
    
    if(node -> Nchildren == 2) {
        oldpos = ast_out.tellp();
        ast_out<<("while")<<"("<<std::to_string(nu)<<")"<<"`";
        print_ast(node->child[1]);
    }
    
}

void print_ast_for_switch_case(SymbolTableTree *node){
    if(node -> Nchildren < 2) return;
    if(node -> child[0] -> Nchildren > 2){
        int nm = mmm[("case")];
        ++mmm[("case")];
        ast_out<<("case")<<"("<<std::to_string(nm)<<")"<<"\n";
        ast_out<<("case")<<"("<<std::to_string(nm)<<")"<<"`";
        print_ast_for_exp(node -> child[0] -> child[1]);
        oldpos = ast_out.tellp();
        ast_out<<("case")<<"("<<std::to_string(nm)<<")"<<"`";
        print_ast(node -> child[1]);
        ast_out<<("switch")<<"("<<std::to_string(switch_stack.back())<<")"<<"`";
        print_ast_for_switch_case(node -> child[2]);
        return;
    }
    int nm = mmm[("default")];
    ++mmm[("default")];
    ast_out<<("default")<<"("<<std::to_string(nm)<<")"<<"\n";
    oldpos = ast_out.tellp();
    ast_out<<("default")<<"("<<std::to_string(nm)<<")"<<"`";
    print_ast(node -> child[1]);
}

void print_ast_for_switch(SymbolTableTree *node){
    int nm = mmm[("switch")];
    switch_stack.push_back(nm);
    ++mmm[("switch")];
    ast_out<<("switch")<<"("<<std::to_string(nm)<<")"<<"\n";
    ast_out<<("switch")<<"("<<std::to_string(nm)<<")"<<"`";
    print_ast_for_exp(node -> child[0] -> child[2]);
    ast_out<<("switch")<<"("<<std::to_string(nm)<<")"<<"`";
    print_ast_for_switch_case(node->child[2]);
    switch_stack.pop_back();
}





void print_ast(SymbolTableTree *node){
        
    if(node->nodeType=="Expression"){
        // cout<<"lol3\n";
        print_ast_for_exp(node);
    }
    else if(node->nodeType=="While"){
        // cout<<"lol4\n";
        print_ast_for_while(node);
    }
    else if(node->nodeType=="Switch"){
        // cout<<"lol5\n";
        print_ast_for_switch(node);
    }
    else if(node->nodeType=="VariableDefine"){
        // cout<<"lol6\n";
        print_ast_for_var_def(node);
    }
    else if(node->nodeType=="Extra_SemiColon"){
        // cout<<"lol7\n";
        return;
    }
    else if(node->nodeType=="Scope2_Continue"){
        int nm = mmm[("continue")];
        ++mmm[("continue")];
        ast_out<<("continue")<<"("<<std::to_string(nm)<<")"<<"\n";
        return;
    }
    else if(node->nodeType=="Scope2_Break"){
        int nm = mmm[("break")];
        ++mmm[("break")];
        ast_out<<("break")<<"("<<std::to_string(nm)<<")"<<"\n";
        return;
    }
    else if(node->nodeType=="Main_Scope_Return"){
        int nm = mmm[("return")];
        ++mmm[("return")];
        ast_out<<("return")<<"("<<std::to_string(nm)<<")"<<"\n";
        return;
    }
    else if(node->nodeType == "Print"){
        print_ast_for_printf(node);
    }
    else if(node -> Nchildren > 0){
        int nm = mmm[("scope")];
        ++mmm[("scope")];
        ast_out<<("scope")<<"("<<std::to_string(nm)<<")"<<"\n";
        for(int i = 0; i < node -> Nchildren; ++i){
            oldpos = ast_out.tellp();
            ast_out<<("scope")<<"("<<std::to_string(nm)<<")"<<"`";
            print_ast(node->child[i]);
        }
    }
    else{
        ast_out.seekp(oldpos);
    }
}



void get_ast(SymbolTableTree *node){
    ast_out.open("ast.txt", ios::out | ios::trunc );
    ast_out<<("main")<<"("<<std::to_string(0)<<")"<<"\n";
    ast_out<<("main")<<"("<<std::to_string(0)<<")"<<"`";
    print_ast(node);
    ast_out.close();
}

