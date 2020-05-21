

#ifndef QICG
#define QICG 1
#include "qicg"
#endif
#ifndef OPT
#define OPT 1
#include "opt"
#endif


void add_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\n";  
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z')){
                assembly_file<<"lb $a0 "<<b<<"\n";
            }    
            else
            { 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            }
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"add.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"add.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;

    }
    
}


void sub_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
    }
        
}


void mul_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mul.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
    }
        
}


void div_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"div.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
    }
        
}


void rem_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"div.s $f1 $f0 $f1\n";
            assembly_file<<"l.s $f0 8($sp)\n";
            assembly_file<<"mul.s $f0 $f1 $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mov.s $f2 $f1\ndiv.s $f1 $f0 $f1\nmul.s $f2 $f1 $f2\nsub.s $f0 $f1 $f0\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
            
    }
        
}


void is_equal_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
    }
        
}


void is_not_equal_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t ";
            break;
    }
        
}


void less_than_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1f ";
            break;
    }
        
}


void less_than_equal_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 223:
                if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1f ";
            break;
    }
        
}


void grt_than_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.le.s $f0 $f1\nbc1t ";
            break;
    }
        
}


void grt_than_equal_float(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 133:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\n";   
            else 
                assembly_file<<"li.s $f0 "<<b<<"\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 213:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 123:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 223:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 323:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"s.s $f0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -8\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"l.s $f1 8($sp)\n";
            assembly_file<<"sub.s $f0 $f1 $f0\n";
            assembly_file<<"addiu $sp $sp 8\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
        case 333:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.lt.s $f0 $f1\nbc1t ";
            break;
    }
            
}



void add_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"add.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;

    }
    
}


void sub_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
    }
        
}


void mul_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mul.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void div_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"div.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void rem_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mov.s $f2 $f1\ndiv.s $f1 $f0 $f1\nmul.s $f2 $f1 $f2\nsub.s $f0 $f1 $f0\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
            
    }
        
}


void is_equal_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
    }
        
}


void is_not_equal_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void less_than_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbge $a0 0 ";
            break;
    }
        
}


void less_than_equal_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 221:
                if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbgt $a0 0 ";
            break;
    }
        
}


void grt_than_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nble $a0 0 ";
            break;
    }
        
}


void grt_than_equal_char(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 131:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 211:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 121:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 221:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 321:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
        case 331:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nblt $a0 0 ";
            break;
    }
            
}



void add_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"add $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"add.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;

    }
    
}


void sub_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
    }
        
}


void mul_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mul.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void div_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"div.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void rem_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"div $t0 $a0 $t0\n";
            assembly_file<<"li $a0 4($sp)\n";
            assembly_file<<"mul $a0 $t0 $a0\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"mov.s $f2 $f1\ndiv.s $f1 $f0 $f1\nmul.s $f2 $f1 $f2\nsub.s $f0 $f1 $f0\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
            
    }
        
}


void is_equal_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
    }
        
}


void is_not_equal_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbeq $a0 0 ";
            break;
    }
        
}


void less_than_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbge $a0 0 ";
            break;
    }
        
}


void less_than_equal_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 222:
                if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbgt $a0 0 ";
            break;
    }
        
}


void grt_than_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nble $a0 0 ";
            break;
    }
        
}


void grt_than_equal_int(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 132:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else 
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 212:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 122:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && a[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lb $a0 "<<b<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 222:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<b<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 322:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 0($sp)\n";
            assembly_file<<"addiu $sp $sp -4\n";
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"lw $a0 "<<b<<"\n";    
            else
                assembly_file<<"li $a0 "<<b<<"\n";
            assembly_file<<"lw $t0 4($sp)\n";
            assembly_file<<"sub $a0 $t0 $a0\n";
            assembly_file<<"addiu $sp $sp 4\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
        case 332:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            if((b[0]=='_') || (b[0]>='a' && b[0]<='z') || (b[0]>='A' && b[0]<='Z'))
                assembly_file<<"l.s $f1 "<<b<<"\n";    
            else {
                assembly_file<<"li.s $f1 "<<b<<"\n";
            }
            assembly_file<<"sub.s $f1 $f0 $f1\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n"; 
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nblt $a0 0 ";
            break;
    }
            
}



void if_false(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    // switch(slctr){
    //     case 222:
    //     case 232:
    //     case 322:
    //     case 332:
    // }
    if(slctr/100 == 2){
        if(branch.find(a) != branch.end()){
            std::string lol = branch[a];
            lol = lol + c + "\n";
            assembly_file<<lol;
            return;
        }
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
            assembly_file<<"lw $a0 "<<a<<"\n";    
        else 
            assembly_file<<"li $a0 "<<a<<"\n";
        assembly_file<<"beq $a0 0 " + c + "\n";
    }
    if(slctr/100 == 1){
        if(branch.find(a) != branch.end()){
            std::string lol = branch[a];
            lol = lol + c + "\n";
            assembly_file<<lol;
            return;
        }
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
            assembly_file<<"lb $a0 "<<a<<"\n";    
        else 
            assembly_file<<"lb $a0 "<<(ascii_to_var[b])<<"\n";
        assembly_file<<"beq $a0 0 " + c + "\n";
    }
    if(slctr/100 == 3){
        if(branch.find(a) != branch.end()){
            std::string lol = branch[a];
            lol = lol + c + "\n";
            assembly_file<<lol;
            return;
        }
        if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
            assembly_file<<"l.s $f0 "<<a<<"\n";    
        else 
            assembly_file<<"li.s $f0 "<<a<<"\n";
        assembly_file<<"li.s $f1 0.0\nc.eq.s $f0 $f1\nbc1t " + c + "\n";
    }
}


void label(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    assembly_file<<c<<" : "<<"\n";
}


void goto_label(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    assembly_file<<"b "<<c<<"\n";
}


void equal_to_all(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 222:
        case 212:
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 322:
        case 332:
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 122:
        case 132:
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 223:
        case 213:
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 323:
        case 333:
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\n";  
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 123:
        case 133:
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 221:
        case 211:
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 321:
        case 331:
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 121:
        case 131:
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";

    }
}



void minus_all(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    switch(slctr){
        case 222:
        case 212:
        case 232:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 322:
        case 332:
        case 312:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 122:
        case 132:
        case 112:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 223:
        case 213:
        case 233:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"neg.s $f1 $f0\n";
            assembly_file<<"mov.s $f0 $f1\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 323:
        case 333:
        case 313:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\n";  
            else {
                assembly_file<<"li.s $f0 "<<a<<"\n";
            }
            assembly_file<<"neg.s $f1 $f0\n";
            assembly_file<<"mov.s $f0 $f1\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 123:
        case 133:
        case 113:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"mtc1 $a0 $f0\ncvt.s.w $f0, $f0\n";
            assembly_file<<"neg.s $f1 $f0\n";
            assembly_file<<"mov.s $f0 $f1\n";
            assembly_file<<"s.s $f0 "<<c<<"\n";
            branch[c] = "l.s $f0 "+c+"\nli.s $f1 0.0\nc.eq.s $f0 $f1\nbc1f ";
            break;
        case 221:
        case 211:
        case 231:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t1\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 321:
        case 331:
        case 311:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";
            break;
        case 121:
        case 131:
        case 111:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"neg $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sb $a0 "<<c<<"\n";
            branch[c] = "lb $a0 "+c+"\nbne $a0 0 ";

    }
}



void not_all(std::string a, std::string b, std::string c, std::map<std::string, std::string> &branch, int &slctr){
    int now = slctr/100;
    switch(now){
        case 2:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lw $a0 "<<a<<"\n";    
            else 
                assembly_file<<"li $a0 "<<a<<"\n";
            assembly_file<<"not $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 3:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"l.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";    
            else {
                assembly_file<<"li.s $f0 "<<a<<"\ncvt.w.s $f1 $f0\nmfc1 $a0, $f1\n";
            }
            assembly_file<<"not $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
        case 1:
            if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z'))
                assembly_file<<"lb $a0 "<<a<<"\n";    
            else 
                assembly_file<<"lb $a0 "<<(ascii_to_var[a])<<"\n";
            assembly_file<<"not $t0 $a0\n";
            assembly_file<<"move $a0 $t0\n";
            assembly_file<<"sw $a0 "<<c<<"\n";
            branch[c] = "lw $a0 "+c+"\nbne $a0 0 ";
            break;
    }
}






void get_selector(string a, std::map<string, SymbolTableTree> &mapper, int &slctr){
    if((a[0]=='_') || (a[0]>='a' && a[0]<='z') || (a[0]>='A' && a[0]<='Z')){
        if(mapper[a].dataType == "char"){
            slctr = slctr*10 + 1;
        }
        else if(mapper[a].dataType.find("float")!=string::npos || mapper[a].dataType.find("double")!=string::npos){
            slctr = slctr*10 + 3;
        }
        else{
            slctr = slctr*10 + 2;
        }
    } 
    else {
        if(a[0] == '\''){
            slctr = slctr*10 + 1;
        }
        else if(find(a.begin(), a.end(), '.') != a.end()){
            slctr = slctr*10 + 3;
        }
        else{
            slctr = slctr*10 + 2;
        }
    }
}


void ass_creator(std::vector<Quadruple> &icg, std::map<string, SymbolTableTree> &mapper){
    
    assembly_file.open("Output/ass.s", ios::out | ios::trunc );

    assembly_file<<".data\n";
    for(auto zz : printf_body){
        assembly_file<<(zz.second)<<": .asciiz "<<(zz.first)<<"\n";
    }
    for(auto yy : ascii_to_var){
        assembly_file<<(yy.second)<<": .asciiz "<<"\""<<(yy.first[1])<<"\"\n";
    }
    for(auto xx : mapper){
        if(xx.second.dataType.find("float")!=string::npos || xx.second.dataType.find("double")!=string::npos){
            auto dT = "float";
            // if(xx.second.dataType.find("double")!=string::npos) dT = "double";
            if(xx.second.value.length() > 0)
                assembly_file<<(xx.first)<<(string(": .")+dT+" ")<<(xx.second.value)<<"\n";
            else
                assembly_file<<(xx.first)<<(string(": .")+dT+" 0.0")<<"\n";
        }
        else if(xx.second.dataType.find("char")!=string::npos){
            if(xx.second.value.length() > 0)
                assembly_file<<(xx.first)<<": .asciiz \""<<(xx.second.value[1])<<"\"\n";
            else
                assembly_file<<(xx.first)<<": .asciiz \"\""<<"\n";
        }
        else{
            if(xx.second.value.length() > 0)
                assembly_file<<(xx.first)<<": .word "<<(xx.second.value)<<"\n";
            else
                assembly_file<<(xx.first)<<": .word 0"<<"\n";
        }
    }

    ifstream printer;
    printer.open("printf.s");
    string from_printf_s;
    while (getline (printer, from_printf_s)) {
        assembly_file<<from_printf_s<<"\n";
    }
    assembly_file<<".globl main\n";
    assembly_file<<"main:\n";
    std::map<std::string, std::string> branch;
    vector<string> params;
    for(auto tt : icg){
        string a = tt.arg1;
        string b = tt.arg2;
        string c = tt.result;
        int slctr = 0;

        if(tt.op != "call")
            get_selector(a, mapper, slctr);
        else
            slctr = slctr*10;
        if(tt.op != "call")
            get_selector(b, mapper, slctr);
        else
            slctr = slctr*10;
        if(tt.op != "goto" && tt.op != "Label" && tt.op != "call" && tt.op != "ifFalse")
            get_selector(c, mapper, slctr);
        else
            slctr = slctr*10;
        
        int now = slctr %10;
        if(tt.op == "+" && tt.arg2.length()>0){

            switch(now){
                case 1:
                    add_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    add_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    add_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "+"){

        }
        else if(tt.op == "-" && tt.arg2.length()>0){

            switch(now){
                case 1:
                    sub_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    sub_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    sub_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "-"){

            minus_all(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "*"){

            switch(now){
                case 1:
                    mul_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    mul_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    mul_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "/"){

            switch(now){
                case 1:
                    div_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    div_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    div_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "%"){

            switch(now){
                case 1:
                    rem_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    rem_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    rem_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "=="){

            switch(now){
                case 1:
                    is_equal_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    is_equal_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    is_equal_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "<"){

            switch(now){
                case 1:
                    less_than_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    less_than_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    less_than_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == ">"){

            switch(now){
                case 1:
                    grt_than_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    grt_than_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    grt_than_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "!="){

            switch(now){
                case 1:
                    is_not_equal_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    is_not_equal_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    is_not_equal_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == ">="){

            switch(now){
                case 1:
                    grt_than_equal_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    grt_than_equal_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    grt_than_equal_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "<="){

            switch(now){
                case 1:
                    less_than_equal_char(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 2:
                    less_than_equal_int(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
                case 3:
                    less_than_equal_float(tt.arg1, tt.arg2, tt.result, branch, slctr);
                    break;
            }
            
        }
        else if(tt.op == "!"){

            equal_to_all(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "ifFalse"){

            if_false(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "Label"){

            label(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "goto"){
            
            goto_label(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "="){

            equal_to_all(tt.arg1, tt.arg2, tt.result, branch, slctr);

        }
        else if(tt.op == "Param"){
            if(a == "b#1") cerr<<"OKAY\n";
            params.push_back(a);
            
        }
        else if(tt.op == "call" && a == "printf"){
            int a0 = 0;
            int f0 = 0;
            for(int ii = params.size()-1; ii >= 0; --ii){
                auto xxx = params[ii];
                if(xxx.length()>3 && xxx[0]=='"'){
                    
                    assembly_file<<"la $a"+to_string(a0++)+" "<<(printf_body[xxx])<<"\n";
                }
                else
                {
                    int tpe=0;
                    get_selector(xxx, mapper, tpe);
                    if(tpe == 3){
                        assembly_file<<"l.s $f"+to_string(f0++)+" "<<(xxx)<<"\n";
                    }
                    else if(tpe == 2){
                        assembly_file<<"lw $a"+to_string(a0++)+" "<<(xxx)<<"\n";
                    }
                    else if(tpe == 1){
                        assembly_file<<"lb $a"+to_string(a0++)+" "<<(xxx)<<"\n";
                    }
                }
                if(a0 >=4 || f0>=3) break;
            }
            while(params.size()>0){
                params.pop_back();
            }
            assembly_file<<"jal printf\n";
        }

    }
    assembly_file<<"li $v0 10\nsyscall\n";
    assembly_file.close();
    std::fstream fs("Output/ass.s", std::fstream::in | std::fstream::out);
    if (fs.is_open()) {
        while (!fs.eof()) {
            if (fs.get() == '#') {
                fs.seekp((fs.tellp() - static_cast<std::streampos>(1)));
                fs.put('_');
                fs.seekp(fs.tellp());
            }
        }
        fs.close();
    }
}
