
#ifndef QICG
#define QICG 1
#include "qicg"
#endif




void unwanted_exp_remover(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    std::set<std::string> req_variable;
    for(Quadruple x : icg){
        std::string a = x.arg1;
        std::string b = x.arg2;
        
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
            req_variable.insert(a);
        }
        if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
            req_variable.insert(b);
        }
    }
    long long itr = 0;
    while(itr < icg.size()){
        Quadruple lol = icg[itr];
        std::string o = lol.op;
        if((o[0]=='_') || (o[0]>='a' && o[0]<='z') || (o[0]>='A' && o[0]<='Z')){
            ++itr;
            continue;
        }
        if(req_variable.find(lol.result)== req_variable.end()){
            icg.erase(icg.begin()+itr);
        }else{
            ++itr;
        }
    }
}


void unwanted_exp_remover_the_second(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    std::set<std::string> req_variable;
    long long itr = icg.size() - 1;
    while(itr >= 0){
        Quadruple x = icg[itr];
        std::string a = x.arg1;
        std::string b = x.arg2;
        std::string c = x.result;
        std::string o = x.op;

        if((o[0]=='_') || (o[0]>='a' && o[0]<='z') || (o[0]>='A' && o[0]<='Z') || c[0] == 't'){
            --itr;
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
                req_variable.insert(a);
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
                req_variable.insert(b);
            }
            continue;
        }
        if(req_variable.find(c) == req_variable.end() && !((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')) &&
                !((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))){
            icg.erase(icg.begin()+itr);
            --itr;
            continue;
        }
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
            req_variable.insert(a);
        }
        if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
            req_variable.insert(b);
        }
        --itr;
    }
}


void reused_exp_remover(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    long long itr = 0;
    std::set<std::string> req_variable;
    std::map<std::vector<std::string>, std::string> qic;
    while(itr < icg.size()){
        Quadruple x = icg[itr];
        std::string a = x.arg1;
        std::string b = x.arg2;
        std::string c = x.result;
        std::string o = x.op;
        if((o[0]=='_') || (o[0]>='a' && o[0]<='z') || (o[0]>='A' && o[0]<='Z')){
            ++itr;
            continue;
        }
        std::vector<std::string> args;
        std::vector<std::string> operation;
        if(a.length()>0 && b.length()>0){
            operation.push_back(o);
            operation.push_back(a);
            operation.push_back(b);
        }
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
            args.push_back(a);
        }
        if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
            args.push_back(b);
        }
        bool lol = true;
        for(auto t : args){
            if(req_variable.find(t) == req_variable.end()){
                lol = false;
                break;
            }
        }
        if(lol){
            if(qic.find(operation) != qic.end()){
                if(itr + 1 < icg.size() && icg[itr + 1].result != a && icg[itr + 1].result != b) 
                icg[itr].op = "=";
                icg[itr].arg1 = qic[operation];
                icg[itr].arg2 = "";

            }
        }
        for(auto t : args){
            req_variable.insert(t);
        }
        if(req_variable.find(c) != req_variable.end()){
            req_variable.erase(c);
        }
        if(operation.size()==3){
            qic[operation] = c;
        }
        ++itr;
    }
}



void unwanted_temp_remover(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    long long itr = 0;
    while(itr < icg.size()){
        Quadruple x = icg[itr];
        std::string a = x.arg1;
        std::string b = x.arg2;
        std::string c = x.result;
        std::string o = x.op;
        if(o == "="){
            if(mapper.find(a) != mapper.end() && mapper.find(c) != mapper.end() && mapper[a].nodeType == "TempVariable" && mapper[c].nodeType == "TempVariable"){
                long long itr2 = itr+1;
                while(itr2 < icg.size()){
                    Quadruple xx = icg[itr2];
                    if(xx.arg1 == c){
                        icg[itr2].arg1 = a;
                    }
                    if(xx.arg2 == c){
                        icg[itr2].arg2 = a;
                    }
                    ++itr2;
                }
                icg.erase(icg.begin()+itr);
                continue;
            }
        }
        ++itr;
    }
}

void unwanted_temp_remover_the_second(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    long long itr = 0;
    while(itr < icg.size() && itr + 1 < icg.size()){
        Quadruple x = icg[itr];
        std::string a = x.arg1;
        std::string b = x.arg2;
        std::string c = x.result;
        std::string o = x.op;
        Quadruple x2 = icg[itr+1];
        std::string a2 = x2.arg1;
        std::string b2 = x2.arg2;
        std::string c2 = x2.result;
        std::string o2 = x2.op;
        if((o[0]=='_') || (o[0]>='a' && o[0]<='z') || (o[0]>='A' && o[0]<='Z')){
            ++itr;
            continue;
        }
        if((o2[0]=='_') || (o2[0]>='a' && o2[0]<='z') || (o2[0]>='A' && o2[0]<='Z')){
            ++itr;++itr;
            continue;
        }
        if(c[0] == 't' && o2 == "=" && o != "=" && c2!=a && c2!=b){
            icg[itr+1].arg1 = a;
            icg[itr+1].arg2 = b;
            icg[itr+1].op = o;
            icg.erase(icg.begin()+itr);
        }
        ++itr;
    }
}

void unwanted_assignment_remover(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    long long itr = 0;
    while(itr < icg.size()){
        if(itr < 0) itr = 0;
        long long itr2 = itr - 1;
        Quadruple x = icg[itr];
        std::string a = x.arg1;
        std::string b = x.arg2;
        std::string c = x.result;
        std::string o = x.op;
        if((o[0]=='_') || (o[0]>='a' && o[0]<='z') || (o[0]>='A' && o[0]<='Z')){
            ++itr;
            continue;
        }
        //std::cerr<<"lol "<<itr<<" "<<c<<"\n";
        while(itr2 >= 0){
            
            Quadruple x2 = icg[itr2];
            std::string a2 = x2.arg1;
            std::string b2 = x2.arg2;
            std::string c2 = x2.result;
            std::string o2 = x2.op;
            //std::cerr<<"lol "<<itr2<<" "<<c<<" "<<c2<<"\n";
            if(a2 == c || b2 == c){
                break;
            }
            if(c2 == c){
                icg.erase(icg.begin()+itr2);
                --itr;
            }
            --itr2;
        }
        ++itr;
    }
}


void optimiser(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    unwanted_exp_remover(icg, mapper);
    reused_exp_remover(icg, mapper);
    unwanted_temp_remover(icg, mapper);
    unwanted_temp_remover_the_second(icg, mapper);
    unwanted_assignment_remover(icg, mapper);
    unwanted_exp_remover_the_second(icg, mapper);
    
}
